#pragma once
#include <mutex>
#include <deque>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <functional>
#include <cstdio>

#ifndef NDEBUG
#define DEBUG_PRINTF(...) printf(__VA_ARGS__)//__VA_ARGS__:用于在宏替换部分中，表示可变参数列表
#else
#define DEBUG_PRINTF(...) ((void)0)
#endif

using Callable = std::function<void()>;

template<typename T>
class SafeDequeue {
public:
    SafeDequeue() = default;
    ~SafeDequeue() = default;
    SafeDequeue(const SafeDequeue&) = delete;//禁用拷贝构造
    SafeDequeue& operator=(const SafeDequeue&) = delete;//禁用拷贝复制

private:
    using unique_lock = std::unique_lock<std::mutex>;//定义别名unique_lock

public:
    template<typename _Fun>
    void push_front(_Fun&& callback);//万能引用

    template<typename _Fun>
    void push_back(_Fun&& callback);//万能引用

    void pop_front(T& callback);
    void pop_back(T& callback);

    bool pop_front(T& callback, uint32_t timeout);
    bool pop_back(T& callback, uint32_t timeout);

    void swap(T& right);
    size_t size() const;
    bool empty() const;
    void clear();

private:
    std::deque<T> mDequeue;
    mutable std::mutex mMutex;//常成员函数不能改变类的成员变量的值，除非该成员变量为mutable
    std::condition_variable mCond;//条件变量mCond
};

#include "SafeDequeue.inl"