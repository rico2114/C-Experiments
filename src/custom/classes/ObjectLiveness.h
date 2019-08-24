//
// Created by Juan Sebastian Quiceno Rico on 2019-08-22.
//

#ifndef EXPERIMENTS_OBJECTLIVENESS_H
#define EXPERIMENTS_OBJECTLIVENESS_H


class ObjectLiveness {
private:
    int value_;
public:
    ObjectLiveness() {}

    void SetValue(int value) {
        value_ = value;
    }

    int GetValue() {
        return value_;
    }
};

class ObjectLivenessBuilder {
    ObjectLiveness object_;

public:
    ObjectLiveness Build() {
        return object_;
    }

    ObjectLivenessBuilder SetValue(int value) {
        object_.SetValue(value);
        return *this;
    }

    ObjectLivenessBuilder() { }
};


#endif //EXPERIMENTS_OBJECTLIVENESS_H
