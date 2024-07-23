# Source directories
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

# Get all .cpp files in the arrays directory
file(GLOB ARRAYS_SRC_FILES ${SRC_DIR}/arrays/*.cpp)
file(GLOB TWO_POINTERS_SRC_FILES ${SRC_DIR}/twopointers/*.cpp)
file(GLOB LINKED_LIST_SRC_FILES ${SRC_DIR}/linkedlist/*.cpp)
file(GLOB STACK_SRC_FILES ${SRC_DIR}/stack/*.cpp)
file(GLOB BIT_MANIPULATION_SRC_FILES ${SRC_DIR}/bitmanipulation/*.cpp)
file(GLOB BACKTRACKING_SRC_FILES ${SRC_DIR}/backtracking/*.cpp)
file(GLOB DYNAMICPROGRAMMING_SRC_FILES ${SRC_DIR}/dynamicprogramming/*.cpp)
file(GLOB TREES_SRC_FILES ${SRC_DIR}/trees/*.cpp)
file(GLOB CONCURRENCY_SRC_FILES ${SRC_DIR}/concurrency/*.cpp)

set(SHARED_INCLUDE_FILES 
  ${SRC_DIR}/shared/ListNode.hpp
  ${SRC_DIR}/shared/TreeNode.hpp)

# Combine all source files into a single list for the library
set(LIB_SRC_LIST
  ${ARRAYS_SRC_FILES}
  ${TWO_POINTERS_SRC_FILES}
  ${SHARED_INCLUDE_FILES}
  ${LINKED_LIST_SRC_FILES}
  ${STACK_SRC_FILES}
  ${BIT_MANIPULATION_SRC_FILES}
  ${BACKTRACKING_SRC_FILES}
  ${DYNAMICPROGRAMMING_SRC_FILES}
  ${TREES_SRC_FILES}
  ${CONCURRENCY_SRC_FILES})

# Create a static library
set(LIB_NAME "${PROJECT_NAME}Lib")
add_library(${LIB_NAME} STATIC ${LIB_SRC_LIST})

# Add precompiled headers to speed up compilation
target_precompile_headers(
  ${LIB_NAME}
  PRIVATE
    <algorithm>
    <queue>
    <map>
    <memory>
    <unordered_map>
    <set>
    <string>
    <stack>
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
source_group("Source Files/shared" FILES ${SHARED_INCLUDE_FILES})
source_group("Source Files/linkedlist" FILES ${LINKED_LIST_SRC_FILES})
source_group("Source Files/stack" FILES ${STACK_SRC_FILES})
source_group("Source Files/bitmanipulation" FILES ${BIT_MANIPULATION_SRC_FILES})
source_group("Source Files/backtracking" FILES ${BACKTRACKING_SRC_FILES})
source_group("Source Files/dynamicprogramming" FILES ${DYNAMICPROGRAMMING_SRC_FILES})
source_group("Source Files/trees" FILES ${TREES_SRC_FILES})
source_group("Source Files/concurrency" FILES ${CONCURRENCY_SRC_FILES})

