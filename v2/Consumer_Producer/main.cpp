#include <iostream>
#include <thread>
#include<condition_variable>
#include<mutex>
#include<queue>

using namespace std;

//buffer
struct Cachedata{
    //id
    int id;
    //属性
    string data;
};

queue<Cachedata>Cachequeue;
//缓冲区容量
const int MAX_CACHE_SIZE = 10;

mutex m;
condition_variable condition_consumer;
condition_variable condition_producer;
//全局id
int ID = 1;

void ConsumerAction(){
    unique_lock<mutex> lock_Consumer(m);
    cout<<this_thread::get_id()<<"获得了锁"<<endl;
    while(Cachequeue.empty()){
        cout<<"此时队列为空，消费者sleep"<<endl;
        cout<<this_thread::get_id()<<"不在持有锁"<<endl;
        condition_consumer.wait(lock_Consumer);
        cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl;
    }
    cout<<this_thread::get_id();
    Cachedata tmp = Cachequeue.front();
    cout<<"消耗ID:"<<tmp.id<<"  消耗数据："<<tmp.data<<endl;
    Cachequeue.pop();
    cout<<this_thread::get_id()<<"释放了锁"<<endl;
    condition_producer.notify_one();
}

void ProducerAction(){
    unique_lock<mutex>lock_Producer(m);
    cout<<this_thread::get_id()<<"获得了锁"<<endl;
    while(Cachequeue.size()>MAX_CACHE_SIZE){
        cout<<"因为队列满了，所以生产者sleep"<<endl;
        cout<<this_thread::get_id()<<"不在持有锁"<<endl;
        condition_producer.wait(lock_Producer);
        cout << "[" << this_thread::get_id() << "] Weak, 重新获取了锁" << endl;
    }
    cout<<this_thread::get_id();
    Cachedata tmp;
    tmp.id = ID++;
    tmp.data = "*****";
    Cachequeue.push(tmp);
    cout<<"添加ID:"<<tmp.id<<"  添加数据："<<tmp.data<<endl;
    cout<<this_thread::get_id()<<"释放了锁"<<endl;
    condition_consumer.notify_one();
}
void ConsumerTask(){
    while(1){
        ConsumerAction();
    }
}
void ProducerTask(){
    while(1){
        ProducerAction();
    }
}

void Dispatch(int Consumer_Num, int Producer_Num){
    vector<thread>thsP;
    vector<thread>thsC;
    for(int i = 0; i < Consumer_Num; i++){
        thsC.push_back(thread(ConsumerTask));
    }
    for(int j = 0; j < Producer_Num; j++){
        thsP.push_back(thread(ProducerTask));
    }
    for (int i = 0; i < Consumer_Num; ++i)
    {
        if (thsC[i].joinable())
        {
            thsC[i].join();
        }
    }

    for (int j = 0; j < Producer_Num; ++j)
    {
        if (thsP[j].joinable())
        {
            thsP[j].join();
        }
    }
}
int main() {
    Dispatch(1,5);
    return 0;
}
