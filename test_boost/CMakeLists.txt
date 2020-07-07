find_package(Boost 1.36.0)
find_package(Boost 1.56 REQUIRED COMPONENTS
        date_time filesystem iostreams)
if(Boost_FOUND)
    link_directories(/usr/local/lib)
    include_directories(/usr/local/include/gtest)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(safe_lib)

    aux_source_directory(. TEST_MUTI)
#    add_executable(foo test_boost.cpp)
    add_executable(test_muti ${TEST_MUTI})
    target_link_libraries(test_muti libgtest.a libgtest_main.a)

    target_link_libraries(test_muti Boost::date_time Boost::filesystem
            Boost::iostreams)
    target_link_libraries(test_muti safe_multi)

#    target_link_libraries(test_muti Boost::date_time Boost::filesystem
#            Boost::iostreams)
endif()

add_subdirectory(safe_lib)
