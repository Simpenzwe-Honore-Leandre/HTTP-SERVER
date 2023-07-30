#include<functional>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<vector>
#include "ThreadPool.h"
#include<iostream>
class ThreadPool
{
    public:
    ThreadPool(int num_threads) : done(false)
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
                       
    
                   }
                }
            });
        }
    }

    private:
    bool done;
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;

    
    

};