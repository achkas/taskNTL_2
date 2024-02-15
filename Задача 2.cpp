//Задача 2

#include <iostream>
#include<thread>
#include <random>
#include <iterator>
#include <chrono>
#include <string>
#include <windows.h>
#include<algorithm>
#include <future>
using namespace std::chrono_literals;

void zap(std::vector<int>& z, int d)
{
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, d);
	auto rand_num([=]() mutable {return dis(gen); });
	generate(z.begin(), z.end(), rand_num);
}

void FR_E(int& a)
{
	//std::lock_guard grd(m3);
	a = a * 2;	
}

void print_vec(std::vector<int> v)
{
	for (const auto& elem : v)
		std::cout << elem << " ";
	std::cout << std::endl;
}







template<typename Iterator, typename T>
T parallel_FR_E(Iterator begin, Iterator end, T init)
{
	size_t cur_size = std::distance(begin, end);	
	unsigned long const max_size = 15;
	if (cur_size <= max_size)
	{		
		return std::for_each(begin, end, FR_E);
	}
	else
	{
		Iterator mid_point = begin;
		std::advance(mid_point, cur_size / 2);
		T second_half_result = parallel_FR_E(mid_point, end, init);
		std::future<T> first_half_result = std::async(parallel_FR_E<Iterator, T>, begin, mid_point, init);
		return first_half_result.get();
	}
}




int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<int> vecA(20);
	zap(vecA, 30);
	print_vec(vecA);
	parallel_FR_E(vecA.begin(), vecA.end(), FR_E);
	print_vec(vecA);

	return 0;
}