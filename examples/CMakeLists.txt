add_executable(Port-Echo port-echo.cc)
target_link_libraries(Port-Echo Port)

install(TARGETS Port-Echo
RUNTIME DESTINATION "bin/examples")
