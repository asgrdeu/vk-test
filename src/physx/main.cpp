#include <iostream>

int add(int x) {
     
     asm {
         mov eax, x
     }

     return x;
}

int main() {
  std::cout << add(5) << std::endl;

  return 0;
}