//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//
#include <iostream>
#include <chrono>
#include "../skeleton/BaseTest.h"
#include "../traits/Traits.h"

namespace Core {
    
    template<typename T,
            typename std::enable_if<std::is_base_of<BaseTest, T>::value>::type * = nullptr>
    static void RunAndComputeResults(T &base_test) {
        // Count set up by default
        auto start = std::chrono::high_resolution_clock::now();
        base_test.SetUp();
        if (!COUNT_SET_UP<T>::value) {
            // Refresh timer if we are not counting set up
            start = std::chrono::high_resolution_clock::now();
        }
        base_test.Run();
        auto stop = std::chrono::high_resolution_clock::now();
        // Compute results
        std::cout << " The test: " << base_test.Name() << " took: "
                  << (std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count())
                  << "ms to complete and allocated: " << base_test.MemoryUsed() << " bytes." << std::endl;
    }

}


