#include <iostream>

class MyClass
{
public:
    void* ptr;

    MyClass()
    {
        std::cout << "Allocating 1MB\n";

        // Allocate 1MB for no reason:
        ptr = malloc(sizeof(1000 * 1000));
    }

    ~MyClass()
    {
        free(ptr);
        std::cout << "Destroyed 1MB\n";
    }
};

int main()
{
    MyClass myClass;

    {
        MyClass myClass2;
    }
}