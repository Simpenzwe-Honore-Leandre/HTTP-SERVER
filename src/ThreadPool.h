#ifndef THREADPOOL_H
#define THREADPOOL_H
#include<functional>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>
#include<vector>
#include<iostream>

class ThreadPool{
    public:
    ThreadPool(int num_threads);
    void queueWork(const std::function<void()> &task);
    ~ThreadPool();
    private:
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool done;
};

#endif