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
    //����
    string data;
};

queue<Cachedata>Cachequeue;
//����������
const int MAX_CACHE_SIZE = 10;

mutex m;
condition_variable condition_consumer;
condition_variable condition_producer;
//ȫ��id
int ID = 1;

void ConsumerAction(){
    unique_lock<mutex> lock_Consumer(m);
    cout<<this_thread::get_id()<<"�������"<<endl;
    while(Cachequeue.empty()){
        cout<<"��ʱ����Ϊ�գ�������sleep"<<endl;
        cout<<this_thread::get_id()<<"���ڳ�����"<<endl;
        condition_consumer.wait(lock_Consumer);
        cout << "[" << this_thread::get_id() << "] Weak, ���»�ȡ����" << endl;
    }
    cout<<this_thread::get_id();
    Cachedata tmp = Cachequeue.front();
    cout<<"����ID:"<<tmp.id<<"  �������ݣ�"<<tmp.data<<endl;
    Cachequeue.pop();
    cout<<this_thread::get_id()<<"�ͷ�����"<<endl;
    condition_producer.notify_one();
}

void ProducerAction(){
    unique_lock<mutex>lock_Producer(m);
    cout<<this_thread::get_id()<<"�������"<<endl;
    while(Cachequeue.size()>MAX_CACHE_SIZE){
        cout<<"��Ϊ�������ˣ�����������sleep"<<endl;
        cout<<this_thread::get_id()<<"���ڳ�����"<<endl;
        condition_producer.wait(lock_Producer);
        cout << "[" << this_thread::get_id() << "] Weak, ���»�ȡ����" << endl;
    }
    cout<<this_thread::get_id();
    Cachedata tmp;
    tmp.id = ID++;
    tmp.data = "*****";
    Cachequeue.push(tmp);
    cout<<"���ID:"<<tmp.id<<"  ������ݣ�"<<tmp.data<<endl;
    cout<<this_thread::get_id()<<"�ͷ�����"<<endl;
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
