//
// Created by Juan Sebastian Quiceno Rico on 2019-09-20.
//

#include "Arena.h"

Arena::Arena(int maximum_size_bytes) {
    initial_memory_location_ = static_cast<char*>(std::malloc(maximum_size_bytes));
    ending_memory_location_ = static_cast<char*>(initial_memory_location_ + maximum_size_bytes);
    current_pointer_ = initial_memory_location_;
}

void Arena::Reset() {
    current_pointer_ = initial_memory_location_;
}

Arena::~Arena() {
    free(initial_memory_location_);
}