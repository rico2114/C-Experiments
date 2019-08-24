//
// Created by Juan Sebastian Quiceno Rico on 2019-08-22.
//

#ifndef EXPERIMENTS_SEQUENCETEST_H
#define EXPERIMENTS_SEQUENCETEST_H

#include "../VariadicClass.h"
#include "../VariadicFilter.h"

class ColumnA {
public:
    int value;
};

class ColumnB {
public:
    int value;
};

class ColumnC {
public:
    int value;
};

class Wrapper {
public:
    ColumnA column_a;
    ColumnB column_b;
    //ColumnC column_c;
};

class Wrapper2 {
public:
    ColumnA column_a;
};

// When you see a class you usually think it exists a relation between
// The fields and the class name so to make this as non relation as possible
// We would have to name it like ColumnHolder1, ColumnHolder2,... or use something else
// That will not imply relations
class Wrapper3 {
public:
    ColumnA column_a;
    ColumnC column_c;
};

class C {
public:

    void DoC(Wrapper wrapper) {
        // Do something with the columns
    }

    void DoC(ColumnA column_a, ColumnB column_b) {
        // Do something with the columns
    }

    template<typename ... Args>
    void DoC(VariadicClass<Args...> variadic) {
        // Do something with the variadic class
        ColumnA column_a = variadic.template Get<ColumnA>();
        // Do something with column b
        ColumnB column_b = variadic.template Get<ColumnB>();
        // Do something with column c
        ColumnC column_c = variadic.template Get<ColumnC>();
        std::cout << column_c.value << std::endl;
        // print stuff
        std::cout << column_b.value;
    }
};

class B {
public:
    C c;

    void DoB(Wrapper wrapper) {
        c.DoC(wrapper);
    }

    void DoB(ColumnA column_a, ColumnB column_b) {
        c.DoC(column_a, column_b);
    }

    template<typename ... Args>
    void DoB(VariadicClass<Args...> variadic) {
        c.DoC(variadic);
    }
};

template <typename ... Args>
struct HelperStructComplex {
    VariadicClass<Args...> variadic_class;
};

struct HelperStructDefined {
    VariadicClass<ColumnA, ColumnB> variadic_class;
};

class A {
public:
    B b;

    void DoA(Wrapper wrapper) {
        b.DoB(wrapper);
    }

    void DoA(ColumnA column_a, ColumnB column_b) {
        // If we had a wrapper we had a few options
        // 1) Add that field into the wrapper
        // 2) Create another wrapper and wire it again
        b.DoB(column_a, column_b);
    }

    template<typename ... Args>
    void DoA(VariadicClass<Args...> variadic) {
        //VariadicClass<ColumnA, ColumnC> filter = Filter<ColumnA, ColumnC>(variadic);
        b.DoB(variadic);
    }

    template<typename ... Args>
    void DoStruct(VariadicClass<Args...> variadic) {
        // For structs I think is not a good idea to have you define
        // a template argument. I think it confuses a lot, so
        // a good idea is to make it clear what you need at the point in the template
        HelperStructComplex<Args...> helper = {variadic};

        HelperStructDefined helper_defined = {variadic};
    }
};




#endif //EXPERIMENTS_SEQUENCETEST_H
