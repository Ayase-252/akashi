add_executable(Port-Read port-read.cc)
target_link_libraries(Port-Read Port)

install(TARGETS Port-Read
RUNTIME DESTINATION "bin/examples")
