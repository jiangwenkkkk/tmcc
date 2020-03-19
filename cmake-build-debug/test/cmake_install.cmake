# Install script for directory: /Users/james/jameswork/james_clion/testpoco/test

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/gtest_poco/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/main_poco/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/protobuf/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/notification_tst/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/mysql_test/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/gtestinherit/cmake_install.cmake")
  include("/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/test/audit_test/cmake_install.cmake")

endif()

