//Задача 2
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <list>

template <class T>
 void print_container(T s, T e)
{    
     while ( s != e) 
     {
         std::cout << *s <<",";
         ++s;
     } 
     std::cout << std::endl;
}


 template <class T>
 void print2_container(const T& container)
 { 
     for (const auto & elem : container)
                     std::cout << elem << std::endl;     
     std::cout << std::endl;
 }
    int main()
    {
        setlocale(LC_ALL, "ru");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        std::vector<std::string> test_vector = { "one", "two", "three", "four" };         
        print_container(test_vector.begin(),test_vector.end());
        std::cout << std::endl;
        print2_container(test_vector);        

        std::set<std::string> test_set = { "one", "two", "three", "four" };        
        print_container(test_set.begin(), test_set.end());
        std::cout << std::endl;
        print2_container(test_set);

        std::list<std::string> test_list = { "one", "two", "three", "four" };        
        print_container(test_list.begin(), test_list.end());
        std::cout << std::endl;
        print2_container(test_list);

        return 0;
    }