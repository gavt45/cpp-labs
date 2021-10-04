if (APPLE)
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
    link_libraries(boost_program_options)
endif()

add_executable(cpp_labs_1
        main.cpp
        HashCalc.h
        HashCalc.cpp)