cmake_minimum_required (VERSION 3.8)
project (RFGR_Types VERSION 1.0.0 
                    LANGUAGES CXX)

# Get list of source files in project src folders recursively
# Places in SOURCES variable
file(GLOB_RECURSE SOURCES 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)

# Add source to this project's static lib
add_library(RFGR_Types STATIC ${SOURCES})

set_target_properties(RFGR_Types PROPERTIES LINKER_LANGUAGE CXX)