#include <iostream>
#include <iomanip>

int sum(int a, int b) {
    return a + b;
}

int main() {
    std::cout << sum(2, 2) << std::endl;
    std::cout << sum(100, 200) << std::endl;
    return 0;
}