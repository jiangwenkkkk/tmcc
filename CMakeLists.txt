cmake_minimum_required(VERSION 3.10)
project(testpoco)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(testpoco ${SOURCE_FILES})





## set the POCO paths and libs
#set(POCO_PREFIX      "/usr/local/Cellar/poco/1.9.4") # the directory containing "include" and "lib"
#set(POCO_INCLUDE_DIR "${POCO_PREFIX}/include")
#set(POCO_LIB_DIR     "${POCO_PREFIX}/lib")
#set(POCO_LIBS        "${POCO_LIB_DIR}/libPocoNet.dylib"
#        "${POCO_LIB_DIR}/libPocoUtil.dylib"
#        "${POCO_LIB_DIR}/libPocoJSON.dylib"
#        "${POCO_LIB_DIR}/libPocoXML.dylib"
#        "${POCO_LIB_DIR}/libPocoFoundation.dylib"
#        "pthread")
#message(${POCO_LIBS})
## set the include path for the app
#target_include_directories(testpoco PRIVATE "${POCO_INCLUDE_DIR}")
## link the app against POCO
#target_link_libraries(testpoco "${POCO_LIBS}")
#



#add_executable(testactive test_active.cpp)
# set the include path for the app
#target_include_directories(testactive PRIVATE "${POCO_INCLUDE_DIR}")
# link the app against POCO
#target_link_libraries(testactive "${POCO_LIBS}")


#add_executable(test_servera test_server.cpp)
#target_include_directories(test_servera PRIVATE "${POCO_INCLUDE_DIR}")
## link the app against POCO
#target_link_libraries(test_servera "${POCO_LIBS}")


add_subdirectory(test)
#add_subdirectory(poco)

#add_subdirectory(test_boost)
add_subdirectory(test_redis)
#add_subdirectory(test_qt)
add_subdirectory(test_fun)
add_subdirectory(kafka_test)
add_subdirectory(librdkafka-master)
#add_subdirectory(c++)
add_subdirectory(c_plus_plus_test)
add_subdirectory(object_design)
