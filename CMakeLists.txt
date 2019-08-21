cmake_minimum_required(VERSION 3.14)
project(Experiments)

set(CMAKE_CXX_STANDARD 14)

add_executable(Experiments src/skeleton/BaseTest.cpp src/skeleton/BaseTest.h src/memory/arenas/ArenaEfficiencyTest.h src/memory/vector/VectorEfficiencyTest.h src/core/Executer.h src/traits/Traits.h src/core/TestSet.h src/macros/Macros.h src/tests/MemoryTest.h src/Main.cpp src/classes/VariadicClass.h src/classes/VariadicFilter.h src/classes/tests/VariadicTest.cpp)