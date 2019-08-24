//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_TRAITS_H
#define EXPERIMENTS_TRAITS_H

#include "../memory/arenas/ArenaEfficiencyTest.h"

// Type trait inference to detect if we want to count the set up time
template <typename T>
struct COUNT_SET_UP {
    static bool value;
};

template <typename T>
bool COUNT_SET_UP<T>::value = true;

#endif //EXPERIMENTS_TRAITS_H
