cmake_minimum_required(VERSION 3.0.0)
project(server VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing(TRUE)
include_directories(src)
set(SOURCE_DIR src)
set(BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR})
set(TESTS tests)

add_executable(server 
    ${SOURCE_DIR}/server.cc
    ${SOURCE_DIR}/ThreadPool.h
    ${SOURCE_DIR}/ThreadPool.cc
    ${SOURCE_DIR}/requestHandler.cc
    ${SOURCE_DIR}/requestHandler.h
)

add_executable(client 
    ${SOURCE_DIR}/client.cc
)

# add_executable(server_test 
#     ${TESTS}/server_test.cc
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# target_link_libraries()
