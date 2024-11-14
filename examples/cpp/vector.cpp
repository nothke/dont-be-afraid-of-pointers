#include <iostream>
#include <vector>

int main()
{
    std::vector<int> ints;

    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    for (auto i : ints)
    {
        std::cout << i << "\n";
    }
}