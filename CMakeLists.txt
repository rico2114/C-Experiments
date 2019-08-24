cmake_minimum_required(VERSION 3.14)
project(Experiments)

set(CMAKE_CXX_STANDARD 14)

add_executable(Experiments src/library/skeleton/BaseTest.cpp src/library/skeleton/BaseTest.h src/library/memory/arenas/ArenaEfficiencyTest.h src/library/memory/vector/VectorEfficiencyTest.h src/library/core/Executer.h src/library/traits/Traits.h src/library/core/TestSet.h src/library/macros/Macros.h src/library/tests/MemoryTest.h src/Main.cpp src/custom/classes/VariadicClass.h src/custom/classes/VariadicFilter.h src/custom/classes/tests/VariadicTest.cpp src/custom/classes/ObjectLiveness.h src/custom/classes/tests/ObjectLivenessTest.cpp src/custom/pointers/UniquePointers.h src/custom/pointers/tests/UniquePointerTest.cpp src/custom/classes/google/SequenceTest.h src/custom/classes/google/SequenceMain.cpp)
set_target_properties(Experiments PROPERTIES COMPILE_FLAGS "-save-temps")
