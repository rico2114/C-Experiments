//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_BASETEST_H
#define EXPERIMENTS_BASETEST_H
#include <vector>

// Notice that the templates need to be defined in the .h file because they are a form of
// code generation, so if the compiler only sees the declarations but not the definitions
// it won't know what to do.
// Notice that every object that is allocated with Allocate should support destructors
// This way we ensure everything is cleaned up from the memory
class BaseTest {

private:
    std::vector<void*> pointers_;
    long long memory_used_;

protected:
    // Allocates a set of lvalues using the move operator
    template<typename T, typename ... Args>
    T* AllocateL(Args&... arguments) {
        return Allocate(std::move(arguments...));
    }

    // Receive a set of arguments as rvalues and constructs
    // a living instance of the desired object
    template<typename T, typename ... Args>
    T* AllocateR(Args&&... arguments) {
        memory_used_ += sizeof(T);
        T* element = new T(arguments...);
        pointers_.push_back(element);
        return element;
    }

    // Simple allocation without passing arguments
    template<typename T>
    T* Allocate() {
        return AllocateR<T>();
    }
public:
    virtual void SetUp() = 0;
    virtual void Run() = 0;
    virtual constexpr char * Name() = 0;

    long long MemoryUsed();
    void CleanUp();
    void SetMemoryUsed(long long memory_used);

    ~BaseTest() {
        CleanUp();
    }
};

#endif //EXPERIMENTS_BASETEST_H
