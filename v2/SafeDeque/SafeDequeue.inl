#include "SafeDequeue.h"


template<typename T>
template<typename _Fun>
inline void SafeDequeue<T>::push_front(_Fun&& callback)
{
    unique_lock lock(mMutex);
    mDequeue.emplace_front(std::forward<_Fun>(callback));//原地构造，完美转发
    //emplace_front 函数会尝试将该参数构造为 SafeDequeue 类的元素类型 T。这可能涉及到类型转换
    lock.unlock();

   // DEBUG_PRINT("push_front\n");
    mCond.notify_one();//给pop放锁
}

template<typename T>
template<typename _Fun>
inline void SafeDequeue<T>::push_back(_Fun&& callback)
{
    unique_lock lock(mMutex);
    mDequeue.emplace_back(std::forward<_Fun>(callback));//原地构造，完美转发
    lock.unlock();

    //DEBUG_PRINT("push_back\n");
    mCond.notify_one();
}

template<typename T>
inline void SafeDequeue<T>::pop_front(T& callback)
{
    unique_lock lock(mMutex);
    mCond.wait(lock, [this] {
        return !mDequeue.empty();
    });
    //只有在调用 notify（notify_one 或 notify_all）并且等待条件为真时，wait 函数才会不阻塞。

    callback = std::move(mDequeue.front());
    mDequeue.pop_front();
    //DEBUG_PRINT("pop_front\n");
}

template<typename T>
inline bool SafeDequeue<T>::pop_front(T& callback, uint32_t timeout)
{//这个函数有一个超时参数 timeout，它允许等待一段指定的时间。
    unique_lock lock(mMutex);
    const bool result = mCond.wait_for(lock, std::chrono::milliseconds(timeout), [this] {
        return !mDequeue.empty();
    });

    if (result) {
        callback = std::move(mDequeue.front());
        mDequeue.pop_front();
    }
    //DEBUG_PRINT("pop_front\n");
    return result;
}

template<typename T>
inline void SafeDequeue<T>::pop_back(T& callback)
{
    unique_lock lock(mMutex);
    mCond.wait(lock, [this] {
        return !mDequeue.empty();
    });

    callback = std::move(mDequeue.back());
    //DEBUG_PRINT("pop_back\n");
    mDequeue.pop_back();
}

template<typename T>
inline bool SafeDequeue<T>::pop_back(T& callback, uint32_t timeout)
{
    unique_lock lock(mMutex);
    const bool result = mCond.wait_for(lock, std::chrono::milliseconds(timeout), [this] {
        return !mDequeue.empty();
    });

    if (result) {
        callback = std::move(mDequeue.back());
        mDequeue.pop_back();
    }
    //DEBUG_PRINT("pop_back\n");
    return result;
}

template<typename T>
inline void SafeDequeue<T>::swap(T& right)
{
    unique_lock lock1(mMutex, std::adopt_lock);
    unique_lock lock2(right.mMutex, std::adopt_lock);
    std::lock(lock1, lock2);
    mDequeue.swap(right.mDequeue);
    //DEBUG_PRINT("swap\n");
}

template<typename T>
inline size_t SafeDequeue<T>::size() const
{
    std::unique_lock<std::mutex> mlock(mMutex);//常成员函数不能改变类的成员变量的值，除非该成员变量为mutable
   // DEBUG_PRINT("size\n");
    return mDequeue.size();
}

template<typename T>
inline bool SafeDequeue<T>::empty() const
{
    std::unique_lock<std::mutex> mlock(mMutex);
    //DEBUG_PRINT("empty\n");
    return mDequeue.empty();
}

template<typename T>
inline void SafeDequeue<T>::clear()
{
    std::unique_lock<std::mutex> mlock(mMutex);
    //DEBUG_PRINT("clear\n");
    return mDequeue.clear();
}