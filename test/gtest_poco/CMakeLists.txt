
include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)

include_directories(/usr/local/Cellar/poco/1.9.4/include/)
link_directories(/usr/local/Cellar/poco/1.9.4/lib)
aux_source_directory(. TESTCPLUSa)

add_executable(ab ${TESTCPLUSa})

target_link_libraries(ab libgtest.a libgtest_main.a libPocoFoundation.dylib PocoNet PocoUtil PocoXML iconv PocoJSON PocoRedis)
