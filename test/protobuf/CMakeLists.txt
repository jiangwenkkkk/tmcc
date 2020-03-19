include_directories(/usr/local/include)
link_directories(/usr/local/lib)


add_executable(test_protobuf test_protobuf.cpp student.pb.cc)
target_link_libraries(test_protobuf protobuf)

add_executable(send_message send_message.cpp student.pb.cc)
target_link_libraries(send_message protobuf libPocoFoundation.dylib PocoNet PocoUtil PocoXML)

add_executable(receive_message receive_message.cpp student.pb.cc)
target_link_libraries(receive_message protobuf libPocoFoundation.dylib PocoNet PocoUtil PocoXML)
