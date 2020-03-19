
set(POCO_PREFIX      "/usr/local/Cellar/poco/1.9.4") # the directory containing "include" and "lib"
set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoNet.dylib"
        "${POCO_LIB_DIR}/libPocoUtil.dylib"
        "${POCO_LIB_DIR}/libPocoJSON.dylib"
        "${POCO_LIB_DIR}/libPocoXML.dylib"
        "${POCO_LIB_DIR}/libPocoFoundation.dylib"
        "pthread")
message(${POCO_LIBS})
# set the include path for the app



include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
include_directories(/usr/local/Cellar/poco/1.9.4/include/)
link_directories(/usr/local/lib)
link_directories(/usr/local/Cellar/poco/1.9.4/lib)
aux_source_directory(. TESTCPLUSaa)

#add_executable(abcd redis_test.cpp)
add_executable(abcd "${TESTCPLUSaa}")
add_executable(abcde test_main.cpp)

target_include_directories(abcd PRIVATE "${POCO_INCLUDE_DIR}")
# link the app against POCO
target_link_libraries(abcd "${POCO_LIBS}")

target_link_libraries(abcd libgtest.a libgtest_main.a libPocoFoundation.dylib PocoNet PocoUtil PocoXML iconv PocoJSON PocoRedis)
target_link_libraries(abcde   libPocoFoundation.dylib PocoNet PocoUtil PocoXML iconv PocoJSON PocoRedis)
