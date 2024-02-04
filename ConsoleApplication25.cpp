#include <iostream>
#include <string>
#include "Queue.h"


int main()
{
    Queue<const char*> Que1;
    Queue<const char*> Que2;
    Queue<const char*> Que3;
    Que1.push_back("Hello");
    std::cout << Que1;
    std::cout << std::endl;
    Que2.push_back("World");
    std::cout << Que1 << Que2;
    Que2.pop();
    std::cout << std::endl;
    std::cout << Que1 << Que2;
}
