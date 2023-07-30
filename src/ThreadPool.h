#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<functional>
class ThreadPool
{
    public:
    ThreadPool(int num_threads);
    void queueWork(std::function<void()> lambda);
};


#endif