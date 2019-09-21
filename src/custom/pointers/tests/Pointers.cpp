//
// Created by Juan Sebastian Quiceno Rico on 2019-09-13.
//
#include <iostream>

class Temp {
    int x;
    bool flag;
};

// Class generic template
template <typename T>
struct DeConst {
    typedef T value;
};

// Template specialization with a another typename
template <typename T>
struct DeConst<T&> {
    typedef T value;
};

// Template specialization with a another typename
template <typename T>
struct DeConst<T&&> {
    typedef T value;
};

template<typename T>
T DoA(T x) {
    return static_cast<typename DeConst<T>::value&&>(x);
}

void DoSomething(Temp* temp) {
    std::cout << "[CLASS] Copy direction: " << &temp << std::endl
                << " Points to: " << temp << std::endl;
}

void DoSomething(int* val) {
    std::cout << "[NATIVE] Copy direction fo val: " << &val << std::endl
                << " Points to:" << val << std::endl;
}

/*int main() {
    Temp temp;
    std::cout << "[CLASS] Direction: " << &temp << std::endl;
    DoSomething(&temp);
    int xx = 10;
    std::cout << "[NATIVE] Direction INT: " << &xx << std::endl;
    DoSomething(&xx);

    Temp temp5;
    DoA(temp5);
    return 0;
}*/
