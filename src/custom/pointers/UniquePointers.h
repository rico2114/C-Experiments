//
// Created by Juan Sebastian Quiceno Rico on 2019-08-22.
//

#ifndef EXPERIMENTS_UNIQUEPOINTERS_H
#define EXPERIMENTS_UNIQUEPOINTERS_H


#include <memory>

class Car {
public:
    int wheels_;
    int windows_;
};

template <typename T>
class Column {

public:
    std::unique_ptr<T> t_;

    Column() { }

    void Set(std::unique_ptr<T> && t) {
        t_ = std::move(t);
    }

    void Set(std::unique_ptr<T>& t) {
        t_ = std::move(t);
    }

    const T* Get() {
        return t_.get();
    }
};


#endif //EXPERIMENTS_UNIQUEPOINTERS_H
