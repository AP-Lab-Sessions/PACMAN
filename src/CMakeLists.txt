SET(SRC main.cpp)
ADD_EXECUTABLE(hw ${SRC})

add_subdirectory(lib/googletest)
add_executable(testing_tool tests/test_main.cpp)
target_link_libraries(testing_tool gtest)