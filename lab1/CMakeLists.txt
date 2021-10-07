project(cpp_labs)

add_compile_options(-Wall -pedantic)

target_sources(cpp_labs_1 PRIVATE
        main.cpp
        HashCalc.h
        HashCalc.cpp)