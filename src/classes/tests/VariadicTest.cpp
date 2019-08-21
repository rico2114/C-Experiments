//
// Created by Juan Sebastian Quiceno Rico on 2019-08-20.
//

#include "../VariadicClass.h"
#include "../VariadicFilter.h"

int main()
{
    VariadicClass<int, double, std::string> variadic;
    variadic.Set<int>(4);
    variadic.Set<double>(12.5);
    variadic.Set<std::string>("Hello World");

    // variadic.Set<bool>(true); fails at compile time!

    std::cout << "int: " << variadic.Get<int>() << "\n";
    std::cout << "double: " << variadic.Get<double>() << "\n";
    std::cout << "string: " << variadic.Get<std::string>() << std::endl;

    // Filter
    VariadicClass<int, std::string> * filtered = Filter<int, std::string>(variadic);
    int val = filtered->template Get<int>();
    // double x = filtered->template Get<double>(); Error
    std::string x = filtered -> template Get<std::string>();
    std::cout << "int: " << val << "\n";
    std::cout << "string: " << x << "\n";
    return 0;
}