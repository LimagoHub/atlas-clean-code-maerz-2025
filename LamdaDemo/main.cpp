#include <iostream>
#include <functional>

void ausgabe (int x) {

}

auto foo() {
    int bar = 5;
    std::function<void(int)> fptr = [](int x)->void{
        std::cout << x + bar << std::endl;
    } ;
    bar = 10;
    fptr(5);
    return fptr;
}



int main() {

    auto ptr = foo();
    ptr(10);

    return 0;
}
