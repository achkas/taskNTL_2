#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <map>
#include <unordered_map>






int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);      

    std::cout << "[IN] : " << std::endl;   

    std::array<int, 6> arr_i{ 1, 5, 1, 3, 4, 4 };

    for (const auto& elem : arr_i)
        std::cout << elem << std::endl;

    std::cout << std::endl;

    std::cout << "[OUT] : " << std::endl;

    std::set<int> set_i;         

    set_i.insert(arr_i.begin(), arr_i.end());
    
    std::for_each(set_i.rbegin(), set_i.rend(), [](int number)
        {
            std::cout << number << ' ' << std::endl;
        });   

    return 0;
}