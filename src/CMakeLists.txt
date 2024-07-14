# Source directories
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(ARRAYS_SRC_DIR ${SRC_DIR}/arrays)
set(TWO_POINTERS_SRC_DIR ${SRC_DIR}/twopointers)

# Get all .cpp files in the arrays directory
file(GLOB ARRAYS_SRC_FILES ${ARRAYS_SRC_DIR}/*.cpp)
file(GLOB TWO_POINTERS_SRC_FILES ${TWO_POINTERS_SRC_DIR}/*.cpp)

# Combine all source files into a single list for the library
set(LIB_SRC_LIST
  ${ARRAYS_SRC_FILES}
  ${TWO_POINTERS_SRC_FILES}
)

# Create a static library
set(LIB_NAME "${PROJECT_NAME}Lib")
add_library(${LIB_NAME} STATIC ${LIB_SRC_LIST})

# Add precompiled headers to speed up compilation
target_precompile_headers(
  ${LIB_NAME}
  PRIVATE
    <algorithm>
    <map>
    <memory>
    <unordered_map>
    <set>
    <string>
    <unordered_set>
    <vector>
)

# Get all .cpp files for the executable
set(EXECUTABLE_SRC_FILES ${SRC_DIR}/main.cpp)

# Add the executable
set(EXC_TARGET_NAME ${PROJECT_NAME})
add_executable(${EXC_TARGET_NAME} ${EXECUTABLE_SRC_FILES})

# Link the static library to the executable
target_link_libraries(${EXC_TARGET_NAME} PRIVATE ${LIB_NAME})
target_include_directories(${EXC_TARGET_NAME} PUBLIC ${LIB_SRC_LIST})

# group the sources in IDE tree
source_group("Source Files/arrays" FILES ${ARRAYS_SRC_FILES})
source_group("Source Files/twopointers" FILES ${TWO_POINTERS_SRC_FILES})

