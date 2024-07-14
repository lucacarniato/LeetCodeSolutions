cmake_minimum_required(VERSION 3.23)

project(
  LeetCodeSolutions
  DESCRIPTION "Leetcode solutions"
  LANGUAGES CXX C
)

# Require C++20
set(CMAKE_CXX_STANDARD 20)


# Docs only available if this is the main app
add_subdirectory(src)