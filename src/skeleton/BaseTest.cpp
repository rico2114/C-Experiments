//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//
// LValues: Objects that occupy some identifiable location in memory.
// RValues: Complement(LValues): Objects that do not occupy some identifiable location in memory (ex: function calls)
#include "BaseTest.h"

// Cleans up the objects in memory
void BaseTest::CleanUp() {
    // Avoid using free since destructors are not called.
    for (void* pointer : pointers_) {
        delete(pointer);
    }
}

// Computes the amount of memory used in bytes
long long BaseTest::MemoryUsed() {
    return memory_used_;
}

// Modifies the currently memory used
void BaseTest::SetMemoryUsed(long long memory_used) {
    memory_used_ = memory_used;
}