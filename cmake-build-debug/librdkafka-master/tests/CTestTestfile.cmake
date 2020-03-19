# CMake generated Testfile for 
# Source directory: /Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests
# Build directory: /Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(RdKafkaTestInParallel "/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/tests/rdkafka_test" "-p5")
set_tests_properties(RdKafkaTestInParallel PROPERTIES  _BACKTRACE_TRIPLES "/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;96;add_test;/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;0;")
add_test(RdKafkaTestSequentially "/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/tests/rdkafka_test" "-p1")
set_tests_properties(RdKafkaTestSequentially PROPERTIES  _BACKTRACE_TRIPLES "/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;97;add_test;/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;0;")
add_test(RdKafkaTestBrokerLess "/Users/james/jameswork/james_clion/testpoco/cmake-build-debug/librdkafka-master/tests/rdkafka_test" "-p5" "-l")
set_tests_properties(RdKafkaTestBrokerLess PROPERTIES  _BACKTRACE_TRIPLES "/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;98;add_test;/Users/james/jameswork/james_clion/testpoco/librdkafka-master/tests/CMakeLists.txt;0;")
