//
// Created by Juan Sebastian Quiceno Rico on 2019-09-20.
//

#ifndef EXPERIMENTS_ARENA_H
#define EXPERIMENTS_ARENA_H
#include <iostream>

class Arena {
public:
    Arena(int maximum_size_bytes);

    template<typename T, typename... Params>
    T* const Allocate(Params... params) {
        // Retrieve what's going to be our ending position
        char* new_available_position = current_pointer_ + sizeof(T);
        // We have allocated as many objects as we could
        // Return null pointer
        if (new_available_position >= ending_memory_location_) {
            return nullptr;
        }
        // Instantiate T in the current slot
        T* object_pointer = new (current_pointer_) T(params...);
        // Advance the pointer
        current_pointer_ = new_available_position;
        // Return our T
        return object_pointer;
    }

    void Reset();
    ~Arena();
private:
    char* current_pointer_;
    char* initial_memory_location_;
    char* ending_memory_location_;
};


#endif //EXPERIMENTS_ARENA_H
