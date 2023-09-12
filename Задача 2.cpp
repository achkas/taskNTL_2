#include <iostream>
#include <string>
#include <windows.h>
#include <exception>


class Unwanted_index : public std::exception
{
public:
    const char* what() const override { return "Выход за пределы массива! Добавить элемент невозможно!"; }
};


class arr
{

private:

    int* element;
    int index = 0;
    int size;

public:

    arr(int size)
    {       
        element = new int[size]();
        this->size = size;
    }


    auto add_element(int num) 
    {
        if (index > size - 1) throw Unwanted_index();
        element[index] = num;
        index++;
        return element[index];


    }    

    auto get_element(int index) 
    {
        if ((index > size - 1) || (index < 0)) throw("...");
        return element[index];
    }

    auto get_size()
    {
        int S = size;
        return S;
    }


    void print_arr(arr*) 
    {
        for (int i = 0; i < size; ++i)
            std::cout << element[i] << " ";
        std::cout << std::endl;
    }
    
    arr& operator=(const arr& other)
    {
        if (this != &other)
        {
            delete[] element;
            this->size = other.size;
            this->index = other.index;
            this->element = new int[other.size];
            for (int i = 0; i < other.size; ++i)
                this->element[i] = other.element[i];
        }
        return *this;
    } 

    
    arr(const arr& other) 
    {       
            this->size = other.size;
            this->index = other.index;
            this->element = new int[other.size];
            for (int i = 0; i < other.size; ++i)
                this->element[i] = other.element[i];                 
    }

    ~arr()
    {        
        delete[] element;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        arr smart_array(6);
        smart_array.add_element(99);
        smart_array.add_element(77);
        smart_array.add_element(88);
        smart_array.add_element(66);
        smart_array.add_element(33);
        smart_array.add_element(22);
       /* smart_array.add_element(55);*/

        arr new_array(2);
        new_array.add_element(909);
        new_array.add_element(304);        

        /*std::cout << smart_array.get_element(4) <<"*"<< smart_array.get_size() << std::endl;
        std::cout << new_array.get_element(0) << "*" << new_array.get_size() << std::endl; */ 

        new_array.print_arr(&new_array);
        std::cout << std::endl;

        smart_array.print_arr(&smart_array);
        std::cout << std::endl;

        arr smart_array_copy(smart_array);
        smart_array_copy.print_arr(&smart_array_copy);
        std::cout << std::endl;
        

        smart_array = new_array;

      /*smart_array = smart_array;*/
        

        smart_array.print_arr(&smart_array);        

    }

    catch (const std::exception& ex) 
    {
        std::cout << ex.what() << std::endl;
    }

    catch (...)
    {
        std::cout << "Элемента с таким индексом не существует!" << std::endl;
    }

    return 0;
}
    


