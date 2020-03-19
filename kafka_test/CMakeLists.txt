
include_directories(/usr/local/include/gtest)
include_directories(/usr/local/include/)
include_directories(../librdkafka-master/src-cpp/)
link_directories(/usr/local/lib)
link_directories(../librdkafka-master/src-cpp/)
#aux_source_directory(. TESTCPLUSa)

add_executable(kafka_test_c kafka_test_c.cpp)
target_link_libraries(kafka_test_c librdkafka++.a)

add_executable(kafka_test_c_two kafka_test_c_two.cpp)
target_link_libraries(kafka_test_c_two librdkafka++.a)


add_executable(kafka_test_p kafka_test_p.cpp)
target_link_libraries(kafka_test_p librdkafka++.a)