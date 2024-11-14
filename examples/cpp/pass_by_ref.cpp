#include <iostream>

void setTo5(int& number) {
    number = 5;
}

int main()
{
    int a = 3;
    int& aRef = a;

    aRef = 6;

    std::cout << "a: " << a << ", ref: " << aRef << '\n';

    setTo5(a);

    std::cout << "a: " << a << ", ref: " << aRef << '\n';
}