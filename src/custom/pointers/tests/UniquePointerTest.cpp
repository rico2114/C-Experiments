//
// Created by Juan Sebastian Quiceno Rico on 2019-08-22.
//
#include <memory>
#include "../UniquePointers.h"
#include <iostream>

/*int main() {
    std::unique_ptr<Car> pointer1 = std::make_unique<Car>();
    pointer1.get()->wheels_ = 2114;
    pointer1.get()->windows_ = 1003;

    Column<Car> column;

    column.Set(pointer1);

    if (pointer1.get() == nullptr) {
        std::cout << "Puntero esta nulo" << std::endl;
        if (column.Get() == nullptr) {
            std::cout << "Puntero interno tambien esta nulo " << std::endl;
        } else {
            std::cout << "Puntero interno esta bien :) " << std::endl;
        }
    } else {
        std::cout << "Puntero no esta nulo" << std::endl;
    }
    return 0;
}*/

int attempt(std::unique_ptr<int>& ref) {
    *ref = 3;
    //std::unique_ptr<int> tmp = std::move(ref);
    return 5;
}

int attempt3(std::unique_ptr<const int>& ref) {
    //*ref = 3;
    //std::unique_ptr<int> tmp = std::move(ref);
    return 5;
}

std::unique_ptr<int> attempt2(std::unique_ptr<int>&& ref) {
    // if we return ref we are trying to copy ref so it can be returned
    // this happens: call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
    return std::move(ref);
}

/*int main() {

    std::string first = "hola";
    std::string second = "pedro";

    // I moved the content of the second element into the first
    // Remember C++ Is a language designed by copy
    // Unique pointers are moved by COPY
    first = std::move(second);
    std::cout << "First: " << first << " Second: " << second;

    std::unique_ptr<int> val = std::make_unique<int>(5);
    attempt(val);
    //attempt3(val);
    //int a = 6;
    std::unique_ptr<int> a = attempt2(std::make_unique<int>(5));
    std::cout << "\n a: " << *(a) << std::endl;

    std::cout << "\n val:" << *val << std::endl;

}*/
