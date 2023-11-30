#include <iostream>
#include <thread>

// Afunction Object
class SomeFunctor
{
public:

    void operator()()
    {
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Display Thread Executing" << std::endl;
        }
    }
};

int main()
{
    // Create a Thread using Function Object
    SomeFunctor func_object;
    std::thread threadObj(func_object);
//    // Create a Thread from Lambda function
//    std::thread threadObj([]() {
//        for(int i = 0; i < 5; ++i) {
//            std::cout << "Display Thread Executing" << std::endl;
//        }
//    });
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Display From Main Thread " << std::endl;
    }

    std::cout << "Waiting For Thread to complete" << std::endl;

    // Wait for the thread to finish
    threadObj.join();
    //threadObj.detach();

    std::cout << "Exiting from Main Thread" << std::endl;
    return 0;
}