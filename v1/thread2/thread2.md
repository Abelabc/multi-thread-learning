#11/30 getid（）获得进程的id

##命名空间std::this_thread提供了一组关于当前线程的函数

this::this_thread::get_id()获取线程id

```

std::this_thread::get_id()//返回线程id

```
##this_thread::yield()放弃当前线程占用时间片使CPU重新调度以便其它线程执行

```
bool g_ready;

void waitReady() { while (!g_ready) { this_thread::yield(); } cout << "ok" << endl; }
//一个函数，使得当g_ready不为真时，将目前线程对象让出时间片
thread t(waitReady);

t.detach();
```

##std::this_thread::sleeo_for()阻塞当前线程一段时间

```
this_thread::sleep_for(chrono::nanoseconds(1000));//阻塞当前线程1000纳秒

```

##std::this_thread::sleep_until()阻塞当前线程直到某个时间点

```
template< class Clock, class Duration >
void sleep_until( const std::chrono::time_point<Clock,Duration>& sleepk_time );

chrono::system_clock::time_point until = chrono::system_clock::now();

until += chrono::seconds(5);

this_thread::sleep_until(until);//阻塞到5秒之后

```
