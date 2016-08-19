cmake_minimum_required(VERSION 3.4)

project(qc)
set(EXECUTABLE_OUTPUT_PATH "bin")
set(CMAKE_C_FLAGS "-O2 -Wall -Wextra")
if (CMAKE_C_COMPILER_ID MATCHES "Clang")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wmost -Weverything")
endif()
add_library(qc lib/qc.c)
add_executable(example lib/example.c lib/qc.c)
target_link_libraries(qc -lgc)
target_link_libraries(example -lgc)

enable_testing()
add_test(NAME example-test COMMAND example)

add_custom_target(cppcheck COMMAND cppcheck -q --enable=all --suppressions-list=$ENV{HOME}/suppressions.cfg lib)
add_custom_target(splint COMMAND find lib -type f -name '*.[ch]' -exec splint {} "\;")
add_custom_target(vera++ COMMAND find lib -type f -name '*.cpp' -o -name '*.[ch]' -exec vera++ -s {} "\;")
add_custom_target(lint DEPENDS cppcheck splint vera++)

add_custom_target(valgrind COMMAND valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-fds=yes --dsymutil=yes $<TARGET_FILE:example>)
