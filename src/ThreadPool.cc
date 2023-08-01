#include "ThreadPool.h"

ThreadPool::ThreadPool(int num_threads) : done(false)
{
    for(int i = 0; i < num_threads;++i)
    {
        threads.emplace_back([this]
        {
            for(;;)
            {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(queueMutex); 
                    //wait until queue is not empty or done is true
                    this->condition.wait(lock, [this]{return this->done || !this->tasks.empty();});
                    if(this->done and this->tasks.empty())
                    {
                        //exit loop and thread, destructor will be called
                        return;
                    }
                    task = std::move(this->tasks.front());
                    this->tasks.pop();                           
                }
                task();
            }
        });
    }
}

void ThreadPool::queueWork(std::function<void()> task)
{
    {
        //aquire lock and push task into queue
        std::unique_lock<std::mutex> lock(queueMutex);
        this->tasks.emplace(std::move(task));
    }
    condition.notify_one();
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        done = true;
    }
    condition.notify_all();
    for(std::thread& thread:threads)
    {
        thread.join();
    }
}

