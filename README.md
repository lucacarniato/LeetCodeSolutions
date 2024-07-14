# LeetCode solutions

## Introduction

This repository contains LeetCode solutions for several problems. The solutions are grouped by topics

## Build

The build requirements are:

- CMake 3.19.3 or higher
- A C++17 compatible compiler

Linux

```bash
cmake -S . -B xbuild -G"Unix Makefiles"
cd xbuild
make
```

Windows
```powershell
cmake -S . -B xbuild -G"Visual Studio 16 2019"
cmake --build build
```
