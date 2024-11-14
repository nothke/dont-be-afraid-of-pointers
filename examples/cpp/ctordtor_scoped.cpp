#include <iostream>

class MyClass
{
public:
    void* ptr;
    const std::string& name;

    MyClass(const std::string& _name) : name(_name)
    {
        // Allocate 1MB for no reason:
        ptr = malloc(sizeof(1000 * 1000));

        std::cout << name << " is allocating 1MB\n";
    }

    ~MyClass()
    {
        free(ptr);
        std::cout << name << " is destroying 1MB\n";
    }
};

int main()
{
    MyClass myClass("Something");

    {
        MyClass myClass("Some other thing");
    }
}