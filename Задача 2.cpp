//Задача 2

#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <random>
#include <algorithm>
#include <execution>
#include <chrono>
#include <random>
#include<thread>
using namespace std::chrono_literals;

void zap(std::vector<int>& z, int d)
{
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis(0, d);
    auto rand_num([=]() mutable {return dis(gen); });
    generate(z.begin(), z.end(), rand_num);
}

void alg_measure_time(std::vector<int> A, std::vector<int> B)
{    
     std::transform(A.begin(), A.end(), B.begin(), A.begin(), std::plus<int>());     
}

void measure_time(std::vector<int> A, std::vector<int> B) 
{
    auto a = A.begin();
    auto b = B.begin();    
    while (a != A.end(), b != B.end())
    {
        int S = (*a) + (*b);
        //std::cout <<S << " ";
        a++; b++;
    }
}

void timeSV(int nt, std::vector<int> A, std::vector<int> B) 
{
    measure_time(A, B);

    std::vector<std::thread> TV;
    auto start1 = std::chrono::high_resolution_clock::now();//начальная точка измерения времени 
    for (int i = 0; i < nt; i++)
    {
        TV.push_back(std::thread(measure_time, A, B));
    }
    for (auto& t : TV)
    {
        t.join();
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end1 - start1;//вычисляем время выполненея сортировки
    std::cout  << time1.count() << "s" << "\t " ;//вывод    

}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> vecA(1000);
    zap(vecA, 100);
    std::vector<int> vecB(1000);
    zap(vecB, 150);

    std::vector<int> vecC(10000);
    zap(vecA, 100);
    std::vector<int> vecD(10000);
    zap(vecB, 150);

    std::vector<int> vecE(100000);
    zap(vecA, 100);
    std::vector<int> vecF(100000);
    zap(vecB, 150);

    std::vector<int> vecG(1000000);
    zap(vecA, 100);
    std::vector<int> vecH(1000000);
    zap(vecB, 150);

    std::cout <<"Количество аппаратных ядер: "<< std::thread::hardware_concurrency() << std::endl;
    std::cout << std::endl;

    std::cout <<"             1000          "<<"10000          "<<"100000          "<<"1000000          " << std::endl;
    std::cout << "1 поток: ";

    timeSV(1, vecA, vecB);
    timeSV(1, vecC, vecD);
    timeSV(1, vecE, vecF);
    timeSV(1, vecG, vecH);
    std::cout << std::endl;

    std::cout << "2 потока: ";
    timeSV(2, vecA, vecB);
    timeSV(2, vecC, vecD);
    timeSV(2, vecE, vecF);
    timeSV(2, vecG, vecH);
    std::cout << std::endl;

    std::cout << "4 потока: ";
    timeSV(4, vecA, vecB);
    timeSV(4, vecC, vecD);
    timeSV(4, vecE, vecF);
    timeSV(4, vecG, vecH);
    std::cout << std::endl;

    std::cout << "8 потоков: ";
    timeSV(8, vecA, vecB);
    timeSV(8, vecC, vecD);
    timeSV(8, vecE, vecF);
    timeSV(8, vecG, vecH);
    std::cout << std::endl;

    std::cout << "16 потоков: ";
    timeSV(16, vecA, vecB);
    timeSV(16, vecC, vecD);
    timeSV(16, vecE, vecF);
    timeSV(16, vecG, vecH);
    std::cout << std::endl;     
 
 return 0;
    }