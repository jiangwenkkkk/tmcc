find_package(Boost 1.36.0)
find_package(Boost 1.56 REQUIRED COMPONENTS
        date_time filesystem iostreams)
if(Boost_FOUND)
    link_directories(/usr/local/lib)
    include_directories(/usr/local/include/gtest)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(foo test_boost.cpp)
    add_executable(test_muti test_muti.cpp)
    target_link_libraries(foo libgtest.a libgtest_main.a)

    target_link_libraries(foo Boost::date_time Boost::filesystem
            Boost::iostreams)
    target_link_libraries(test_muti Boost::date_time Boost::filesystem
            Boost::iostreams)
endif()