cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(designPatterns VERSION 0.1.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/designPatterns_bits")

# Source files
set(SOURCE_FILES
    
    ${PROJECT_INCLUDE_DIR}/test.hpp
    ${PROJECT_INCLUDE_DIR}/singleResponsability.hpp
    ${PROJECT_INCLUDE_DIR}/openClose.hpp
    ${PROJECT_INCLUDE_DIR}/lyskovSubstitution.hpp
    ${PROJECT_INCLUDE_DIR}/interfaceAggregation.hpp
    ${PROJECT_INCLUDE_DIR}/dependencyInversion.hpp
    ${PROJECT_INCLUDE_DIR}/builderPattern.hpp
    ${PROJECT_INCLUDE_DIR}/groovyStyle.hpp
  
    ${PROJECT_SOURCE_DIR}/test.cpp
    
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(designPatterns SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(designPatterns PRIVATE include/designPatterns_bits)

# Install
install(TARGETS designPatterns DESTINATION lib)

# Install the headers
install(FILES include/designPatterns DESTINATION include)

# Create base directory
install(DIRECTORY include/designPatterns_bits DESTINATION include)
