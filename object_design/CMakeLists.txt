


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

SET(Poco_INCLUDE_DIRS "/usr/local/include/Poco")
find_package(Poco REQUIRED COMPONENTS Foundation XML JSON Util )
#这个地方还有引用顺序的问题
include_directories(
        ${MY_SRC_INCLUDE}
        ${Poco_INCLUDE_DIRS}
)
link_directories(${CMAKE_BINARY_DIR})

add_executable(elector elector.cpp)

target_link_libraries(elector ${Poco_LIBRARIES})

