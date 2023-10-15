#include <iostream>
#include <string>
#include <windows.h>
#include <exception>

template<class T>
class arr
{
private:
    int rows;
    int cols;
    T** table;  


public:
    arr(int rows, int cols)
    {
        table = (T**) new T* [rows]();        
        for (int i = 0; i < rows; i++)
        {
            table[i] = new int[cols]();
        }
        this->rows = rows;
        this->cols = cols;

    }



    T* operator[](T elem)
    {
        return table[elem];
    }

    const T* operator[](const T elem)const
    {
        return  table[elem];
    }

    T size(int r, int c)
    {
        if (r > 0)
        {            
            for (int i = 0; i < r; i++)
                delete[] table[i];
        }

        if (c > 0)
        {
            delete[] table;
        }
       
        this->rows = r;
        this->cols = c;
        
        table = (T**) new T* [r](); 
        for (int i = 0; i < r; i++)
            table[i] = (T*) new T[c]();
        
        return **table;
    }

    void print_arr()
    {
        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++)
            {
                std::cout << table[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~arr()
    {
        if (cols > 0) {
            for (int i = 0; i < rows; i++)
                delete[] table[i];
        }

        if (rows > 0)
            delete[] table;        
    }
};





int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);      

    auto test = arr<int>(6, 5);
    test[3][3] = 4;
    std::cout << test[3][3];
    std::cout << std::endl;
    test.print_arr();
    test.size(3, 3);
    std::cout << std::endl;
    test[2][2] = 9;
    std::cout << test[2][2] << std::endl;
    test.print_arr();      

    return 0;
}