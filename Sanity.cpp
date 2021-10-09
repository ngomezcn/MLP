#include <iostream>
//#include "include/core/Context/Context.h"
#include "include/core/Debug/Windows/Windows_D.h"


int main() {
  
    std::cout << "init\n";
    mlp::debug::Windows_D caca;
    caca.printList(true);

    std::cout << "isThisWindow" << caca.isThisWindow(L"Cheat Engine 7.2") << std::endl;

}