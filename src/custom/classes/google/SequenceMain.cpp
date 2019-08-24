#include "../VariadicClass.h"
#include "SequenceTest.h"

//
// Created by Juan Sebastian Quiceno Rico on 2019-08-22.
//
int main() {
    ColumnA column_a;
    ColumnB column_b;
    ColumnC column_c;
    column_b.value = 2114;
    column_c.value = 9999;
    VariadicClass<ColumnA, ColumnB, ColumnC> variadic;
    variadic.Set<ColumnA>(column_a);
    variadic.Set<ColumnB>(column_b);
    variadic.Set<ColumnC>(column_c);
    A a;
    //Wrapper wrapper = {column_a, column_b};
    a.DoA(column_a, column_b);
    a.DoA(variadic);

    // struct calls
    //a.DoStruct(variadic);
    return 0;
}
