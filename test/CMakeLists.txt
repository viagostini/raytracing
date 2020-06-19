set(BINARY ${CMAKE_PROJECT_NAME}_tests)

# file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cc)

set(TEST_SOURCES main.cc 
                 tuple_test.cc
                 color_test.cc
                 canvas_test.cc)

add_executable(${BINARY} ${TEST_SOURCES})

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)