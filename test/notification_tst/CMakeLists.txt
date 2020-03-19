include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)
aux_source_directory(. TESTCPLUSa)

add_executable(abc ${TESTCPLUSa})

target_link_libraries(abc libgtest.a libgtest_main.a libPocoFoundation.dylib PocoNet PocoUtil PocoXML )
