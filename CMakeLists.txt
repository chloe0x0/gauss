cmake_minimum_required(VERSION 3.25)

project(gauss)

# Get source files
file(GLOB SOURCES src/*.cpp)

# Include Header files
include_directories(include)

# Create a shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Install the library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install lib headers
file(GLOB HEADERS include/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})


