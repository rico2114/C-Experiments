//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_MEMORYTEST_H
#define EXPERIMENTS_MEMORYTEST_H


#include "../core/TestSet.h"
#include "../macros/Macros.h"

class MemoryTest : public TestSet {

private:
    std::vector<BaseTest*> tests_;
    ArenaEfficiencyTest arena_efficiency;
    VectorEfficiencyTest vector_efficiency;

public:
    MemoryTest() {
        tests_.push_back(&vector_efficiency);
        tests_.push_back(&arena_efficiency);
    }

    std::vector<BaseTest*> & GetTests() override {
        return tests_;
    }
};

// In case you do not want to measure set up speed
// MEASURE_SET_UP(MemoryTest, false);
// Or in case you do not want to measure clear up speed
// MEASURE_CLEAN_UP(MemoryTest, false);
// Both are on by default.

#endif //EXPERIMENTS_MEMORYTEST_H
