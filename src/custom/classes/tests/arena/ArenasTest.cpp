//
// Created by Juan Sebastian Quiceno Rico on 2019-09-20.
//
#include <iostream>
#include <chrono>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Arena.h"

class OBJ {
    int * arr = new int[10];
public:
    ~OBJ() {
        delete[](arr);
    }
};
class DNA {
    OBJ * arr = new OBJ[10];
    OBJ * arr_2 = new OBJ[10];

public:
    DNA(int size) {
    }

    ~DNA() {
        delete[](arr);
        delete[](arr_2);
    }
};

int main() {
    std::unique_ptr<Arena> arena = std::make_unique<Arena>(20000 * sizeof(DNA));
    /* initialize random seed: */
    srand (time(NULL));

    auto begin = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < 10; ++ j) {
        {
            for (int i = 0; i < 20000; ++i) {
                DNA * const dna = arena->Allocate<DNA>(rand() % 1000);
            }
        }
        arena->Reset();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = end - begin;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << "Arena measurement: " << ms << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < 10; ++ j) {
        {
            for (int i = 0; i < 20000; ++i) {
                DNA* dna = new DNA(rand() % 1000);
                delete(dna);
            }
        }
    }
    end = std::chrono::high_resolution_clock::now();
    dur = end - begin;
    ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    std::cout << "Non arena measurement: " << ms << std::endl;
    /*
     * Arena measurement: 46903
     * Non arena measurement: 46198
     * No matter how much they store data or how many instantiations non arena beats.
     */
    /*
     * Arena measurement: 19666
     * Non arena measurement: 28394
     * int[450] con destructors y new DNA en el otro
     */
    return 0;
}
