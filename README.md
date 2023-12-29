# multi-thread-learning

## 目录

## v1

学习多线程的基本用法，更新日常学习

### 11/30：

创建子线程，协调子线程，thread库的学习。

### 12/18：

**lock_guard(m,adopt_lock)**第一个参数为adopt_lock标识时，表示构造函数中不再进行互斥量锁定，因此**此时需要提前手动锁定**。

#### **unique_lock**

(1)可以手动lock和unlock。（2）try_to_lock**得保证锁处于unlock的状态**,然后尝试现在能不能获得锁；尝试用mutx的lock()去锁定这个mutex，但如果没有锁定成功，会立即返回，不会阻塞在那里，并继续往下执行；(3)defer_lock始化了一个没有加锁的mutex;(4)owns_lock()检查锁成功与否

(4)move(g2)所有权转移，让其他guard管理g2的锁。

### 12/19

#### *async与future*

```
future<double> fu = async(t1, a, b);//fu占位
```

刚实例化的future是没有储存值的，但在调用std::future对象的get()成员函数时，主线程会被阻塞直到异步线程执行结束，并把返回结果传递给std::future

#### ***atmic<>***

std::atomic<>对象提供了常见的原子操作（通过调用成员函数实现对数据的原子操作）： store是原子写操作，load是原子读操作。exchange是于两个数值进行交换的原子操作。 **即使使用了std::atomic<>，也要注意执行的操作是否支持原子性**，也就是说，你不要觉得用的是具有原子性的变量（准确说是对象）就可以为所欲为了，你对它进行的运算不支持原子性的话，也不能实现其原子效果。一般针对++，–，+=，-=，&=，|=，^=是支持的，这些原子操作是通过在std::atomic<>对象内部进行运算符重载实现的。



## v2

### Consumer_Producer

实现了一个生产者消费者的多线程并发协作模型。

### SafeDeque

基于STL的dequeue容器, 来实现一个线程安全的双端队列。支持自定义等待时间跳出。

```
const bool result = mCond.wait_for(lock, std::chrono::milliseconds(timeout), [this] {return !mDequeue.empty();});
```

### Threadpool

C++11实现一个简单的线程池,参考文章如下：

[基于C++11实现线程池 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/367309864)