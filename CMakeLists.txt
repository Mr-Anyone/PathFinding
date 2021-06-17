cmake_minimum_required(VERSION 3.19)
project(PathFinding)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES src/main.cpp src/path.cpp)
set(HEADERDIR ${PROJECT_SOURCE_DIR}/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Users/vince/Downloads/SFML-2.5.1/lib/cmake/SFML)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(PathFinding ${SOURCE_FILES})

target_link_libraries(PathFinding sfml-graphics sfml-audio)
target_include_directories(PathFinding PRIVATE ${HEADERDIR})

# Packaging
install(TARGETS PathFinding DESTINATION bin)

set(CPACK_GENERATOR NSIS)
set(CPACK_PACKAGE_NAME "PathFinding")
set(CPACK_PACKAGE_VENDOR "lmaolmao123.net")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This will be the first package that uses cpack and SFML")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "PathFinding")
SET(CPACK_NSIS_MODIFY_PATH ON)

include(CPack)