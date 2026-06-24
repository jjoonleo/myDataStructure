# myDataStructure

C++ data structure experiment for a segmented dynamic list.

## Why This Project Matters

This repository explores a custom dynamic data structure that stores values in
multiple allocated blocks and benchmarks indexed access.

## Contents

- Visual Studio solution
- `dynamicLinkedList.cpp`
- Benchmark output in `result.txt`

## Concept

The custom `dynamicLinkedList<T>` stores pointers to multiple backing arrays.
New blocks are allocated as the structure grows, and indexed lookup maps a
global index to the relevant backing block.

## Build

Open the Visual Studio solution or compile the C++ source manually on a Windows
toolchain that supports the intrinsics used in the source.

## Portfolio Highlight

Use this as a supporting low-level C++ experiment. It is not as strong as the
larger application repos, but it shows data structure curiosity and benchmarking.
