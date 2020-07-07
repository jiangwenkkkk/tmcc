
include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)

include_directories(/usr/local/Cellar/poco/1.9.4/include/)
link_directories(/usr/local/Cellar/poco/1.9.4/lib)

set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/liba")
aux_source_directory(. SAFE_MULTI)
add_library(safe_multi SHARED ${SAFE_MULTI})
add_library(safe_multi_static STATIC ${SAFE_MULTI})
SET_TARGET_PROPERTIES(safe_multi PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(safe_multi_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES (safe_multi PROPERTIES VERSION 1.2 SOVERSION 1)

GET_TARGET_PROPERTY(OUTPUT_VALUE safe_multi_static OUTPUT_NAME)
MESSAGE(STATUS  "This is the hello_static OUTPUT_NAME:" ${OUTPUT_VALUE})


#include_directories(.)
#add_executable(calc_test differ_test.cpp)
#target_link_libraries(calc_test libgtest.a libgtest_main.a libPocoFoundation.dylib PocoNet PocoUtil PocoXML iconv PocoJSON PocoRedis calc)
#
#add_executable(main_a main.cpp)
#target_link_libraries(main_a calc)