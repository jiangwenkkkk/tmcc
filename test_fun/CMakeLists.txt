
include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)
aux_source_directory(. TESTCPLUSa)

add_executable(abcb ${TESTCPLUSa})

target_link_libraries(abcb libgtest.a libgtest_main.a)
