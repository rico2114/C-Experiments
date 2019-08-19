//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_ARENAEFFICIENCYTEST_H
#define EXPERIMENTS_ARENAEFFICIENCYTEST_H

#include <time.h>

#include "../../skeleton/BaseTest.h"
#include "../../traits/Traits.h"

#define MAX_SIZE 10000000
#define ITERATIONS MAX_SIZE
#define ACCESS_TIMES MAX_SIZE>>1

class Arena {
    int * pointer_;
    int offset;

public:
    Arena() {
        pointer_ = (int*) malloc(MAX_SIZE * sizeof(int));
        offset = 0;
    }

    ~Arena() {
        free(pointer_);
    }

    void Allocate(int value) {
        pointer_[offset] = value;
        ++ offset;
    }

    int Get(int position) {
        return pointer_[position];
    }
};

class ArenaEfficiencyTest : public BaseTest {
private:
    Arena * global_arena;

public:
    void SetUp() override {
        srand(time(NULL));
        global_arena = Allocate<Arena>();
    }

    void Run() override {
        // Setting the whole array
        for (int i = 0; i < ITERATIONS; ++ i) {
            int random = rand() % 100000 + 1;
            global_arena->Allocate(random);
        }
        // Accessing random values at the array
        for (int i = 0; i < ACCESS_TIMES; ++ i) {
            int value = global_arena->Get(rand() % MAX_SIZE);
        }
    }

    char * Name() override {
        return "arena_test";
    }
};



#endif //EXPERIMENTS_ARENAEFFICIENCYTEST_H
