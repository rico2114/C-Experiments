//
// Created by Juan Sebastian Quiceno Rico on 2019-09-17.
//
#include <iostream>

class Entity {
public:
    // Default constructor
    Entity() {
        std::cout << "Entity was constructed" << std::endl;
    }

    // Copy constructor (for new instances)
    Entity(const Entity& entity) {
        std::cout << "Copy constructor" << std::endl;
        value_ = entity.value_;
    }

    // Copy constructor (for new instances)
    Entity(const Entity&& entity) {
        std::cout << "Copy constructor R VALUE" << std::endl;
        value_ = entity.value_;
    }

    // For existing instances (notice the Entity& at the start)
    Entity& operator=(const Entity& entity) {
        std::cout << "Assignment operator" << std::endl;
        value_ = entity.value_;
        return *this;
    }

    void SetValue(int value) {
        value_ = value;
    }

    void ToString() {
        std::cout << "[TO_STRING] value: " << value_ << std::endl;
    }
private:
    int value_;
};

Entity GetEntity() {
    Entity entity{};
    entity.SetValue(2114);
    return entity;
}

/*int main() {
    // Copy constructor R value
    Entity copied = std::move(GetEntity());
    // Default constructor
    Entity b{};
    // Assignment operator
    b = copied;
    // Copy constructor
    Entity copy_constructor = b;
    return 0;
}*/