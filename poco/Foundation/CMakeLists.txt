#include_directories(/usr/include)
#link_directories(/usr/local/lib)
#link_directories(/usr/lib)
#add_executable(pocoa aaaaa.cpp)
#target_link_libraries(pocoa libpthread.dylib)

set(LIBNAME ".")
set(POCO_LIBNAME "Poco${LIBNAME}")
file(GLOB SRCS_S "src/*.cpp")
POCO_SOURCE_AUTO(SRCS ${SRCS_S})


message(${LIBNAME})
message(${POCO_LIBNAME})