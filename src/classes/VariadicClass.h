//
// Created by Juan Sebastian Quiceno Rico on 2019-08-19.
//
// Reference: https://stackoverflow.com/questions/27941661/generating-one-class-member-per-variadic-template-argument

#ifndef EXPERIMENTS_VARIADICCLASS_CPP
#define EXPERIMENTS_VARIADICCLASS_CPP

#include <string>
#include <iostream>

// Template specialization
template<typename T, typename... Next> class VariadicClass;

// Base case extension
template <typename T>
class VariadicClass<T> {
private:
    T value_;
protected:
    void SetField(T & value) {
        value_ = value;
    }

    T & GetField() {
        return value_;
    }
};

// Inductive case
template <typename T, typename ... Next>
class VariadicClass : public VariadicClass<T>, public VariadicClass<Next...> {
public:

    // Copy the values into the variadic class
    template <typename F>
    void Set(F f) {
        this->VariadicClass<F>::SetField(f);
    }

    // Retrieve by reference
    template <typename F>
    F & Get() {
        return this->VariadicClass<F>::GetField();
    }
};

// Todo Search for a way to filter up the variadic arguments
#endif //EXPERIMENTS_VARIADICCLASS_CPP
