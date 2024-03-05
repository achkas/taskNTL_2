//Задача 2

#include <iostream>
#include<thread>
#include<atomic>
#include <chrono>
#include <string>
#include <windows.h>
#include<mutex>
using namespace std::chrono_literals;

int cl(int man, std::atomic<int>& c)
{
    
    for (int i = 0; i < man; i++)
    {      
        c++;
        std::this_thread::sleep_for(1000ms);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        std::cout << "client: " << c << std::endl;        
    }
    return c;
}
 
int op(int man, std::atomic<int>& c)
{    
    for (int i = 0; i < man; i++)
    {        
        std::this_thread::sleep_for(2090ms);
        c--;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);//зелёныи
        std::cout << "oprtor: " << c << std::endl;        
    }
    return c;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::atomic<int> c;
    int man = 10;    
    //std::cout << std::boolalpha << c.is_always_lock_free << std::endl;
    
    std::thread t3([&]() {c.store(cl(man, c), std::memory_order_seq_cst); });
    std::thread t4([&]() {c.store(op(man, c), std::memory_order_seq_cst/*std::memory_order_relaxed*/); });
    t3.join();
    t4.join();    
    std::cout << "Количество оставшихся клиентов: " << c << std::endl;
    return 0;
}
//1std::memory_order_relaxed, 2std::memory_order_acquire, 3std::memory_order_consume,
//4std::memory_order_acq_rel, 5std::memory_order_release и 6std::memory_order_seq_cst.