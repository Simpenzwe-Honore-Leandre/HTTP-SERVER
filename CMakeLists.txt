cmake_minimum_required(VERSION 3.0.0)
project(serverX VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing(TRUE)
set(SOURCE_DIR src)
set(TESTS tests)

add_executable(serverX 
    ${SOURCE_DIR}/main.cc
    ${SOURCE_DIR}/server.cc
    ${SOURCE_DIR}/ThreadPool.h
    ${SOURCE_DIR}/requestHandler.cc
    ${SOURCE_DIR}/client.cc

)
add_executable(server_test 
    ${TESTS}/server_test.cc
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# target_link_libraries()
