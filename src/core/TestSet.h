//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_TESTSET_H
#define EXPERIMENTS_TESTSET_H


#include <type_traits>
#include "../skeleton/BaseTest.h"
#include "Executer.h"

class TestSet {

public:
    void Run() {
        for (int i = 0; i < GetTests().size(); ++ i) {
            BaseTest& base = *(GetTests()[i]);
            Core::RunAndComputeResults(base);
        }
    }

    virtual std::vector<BaseTest*> & GetTests() = 0;
};


#endif //EXPERIMENTS_TESTSET_H
