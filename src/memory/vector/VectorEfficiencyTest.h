//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_VECTOREFFICIENCYTEST_H
#define EXPERIMENTS_VECTOREFFICIENCYTEST_H

#include <time.h>

#include "../../skeleton/BaseTest.h"
#include <vector>

#define MAX_SIZE 10000000
#define ITERATIONS MAX_SIZE
#define ACCESS_TIMES MAX_SIZE>>1

#define INITIAL_VECTOR_SIZE 1000
class CustomIntVector {

private:
    int * elements_;
    int initial_size_;
    int offset_;

public:
    CustomIntVector(int initial_size) {
        elements_ = new int[initial_size];
        initial_size_ = initial_size;
        offset_ = 0;
    }

    ~CustomIntVector() {
        delete [] elements_;
    }

    void Add(int value) {
        if (offset_ >= initial_size_) {
            int * new_data = new int[initial_size_ << 1];
            for (int i = 0; i < initial_size_; ++ i) {
                new_data[i] = elements_[i];
            }
            delete [] elements_;
            elements_ = new_data;
            offset_ = initial_size_;
            initial_size_ = initial_size_ << 1;
        }
        elements_[offset_] = value;
        offset_ += 1;
    }

    int Get(int position) {
        return elements_[position];
    }

    int Size() {
        return initial_size_ * sizeof(int);
    }
};

class VectorEfficiencyTest : public BaseTest {
private:
    CustomIntVector * vector;

public:
    void SetUp() override {
        srand(time(NULL));
        vector = AllocateR<CustomIntVector>(INITIAL_VECTOR_SIZE);
    }

    void Run() override {
        // Setting the whole array
        for (int i = 0; i < ITERATIONS; ++ i) {
            int random = rand() % 100000 + 1;
            vector->Add(random);
        }
        // Accessing random values at the array
        for (int i = 0; i < ACCESS_TIMES; ++ i) {
            int value = vector->Get(rand() % MAX_SIZE);
        }
        SetMemoryUsed(MemoryUsed() + vector->Size());
    }

    char * Name() override {
        return "vector_test";
    }
};

#endif //EXPERIMENTS_VECTOREFFICIENCYTEST_H
