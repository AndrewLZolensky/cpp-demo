#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    std::cout << "The vector \"numbers\" contains:";
    for (auto i : numbers) {
        std::cout << " " << i;
    }
    std::cout << std::endl;
    return 0;
}