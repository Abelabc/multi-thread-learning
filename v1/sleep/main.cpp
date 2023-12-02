#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#pragma warning(disable:4996)//加上可去掉unsafe 请使用localtime_s的编译报错
int main()
{
    using std::chrono::system_clock;//在当前作用域中使用std::chrono命名空间下的system_clock类型。
    std::time_t tt = system_clock::to_time_t(system_clock::now());//获取当前的系统时间
    struct std::tm *ptm = std::localtime(&tt);//通过localtime函数将时间转换为结构体std::tm的格式。
    std::cout << "Current time: " << std::put_time(ptm, "%X") << '\n'; //必须大写X，若小写x，输出的为日期
    std::cout << "Waiting for the next minute to begin...\n";
    ++ptm->tm_min;//表示将结构体ptm中的tm_min字段（表示分钟数）自增1。这样做可以将当前时间增加1分钟。
    ptm->tm_sec = 0;//将结构体ptm中的tm_sec字段（表示秒数）设为0。
    //mktime(ptm)，可以将ptm结构体中的时间信息转换为对应的时间值，以便在后续的代码中使用。
    std::this_thread::sleep_until(system_clock::from_time_t(mktime(ptm)));//system_clock::from_time_t() 将ptm结构体中的时间信息转换为system_clock类型的时间点
    std::cout << std::put_time(ptm, "%X") << "reached!\n";//std::put_time() 函数将ptm结构体中的时间信息按照格式字符串"%X"进行格式化输出。
    getchar();//getchar(); 用于等待用户按下任意键，以便程序在用户确认后结束。
    return 0;
}