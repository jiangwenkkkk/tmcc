add_executable(testchar testchar.cpp)
add_executable(testa_fork testa_fork.cpp)




include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
link_directories(/usr/local/lib)

set(TESTCPLUS
      testcplus.cpp
        )
add_executable(testcplus ${TESTCPLUS})

target_link_libraries(testcplus libgtest.a libgtest_main.a libPocoFoundation.dylib  )

add_subdirectory(gtest_poco)

add_executable(color test_color.cpp)

add_subdirectory(main_poco)
add_subdirectory(protobuf)
add_subdirectory(notification_tst)
add_subdirectory(mysql_test)
add_subdirectory(gtestinherit)
add_subdirectory(audit_test)
