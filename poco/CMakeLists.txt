cmake_minimum_required(VERSION 3.2.0)

project(Poco)

set(CMAKE_C_STANDARD 11)

file(STRINGS "${PROJECT_SOURCE_DIR}/libversion" SHARED_LIBRARY_VERSION)

MESSAGE(STRINGS)