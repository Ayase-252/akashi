include_directories(${AKASHI_TEST_THIRDPARTY_DIR})

add_executable(test-parser parser-test.cc)
target_link_libraries(test-parser Parser)

add_executable(test-dispatcher dispatcher-test.cc)
target_link_libraries(test-dispatcher Dispatcher)

install(TARGETS test-parser test-dispatcher
RUNTIME DESTINATION "test-bin")
