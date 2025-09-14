# maze-generator-clg

[![Language: C99](https://img.shields.io/badge/language-C99-18181f?style=flat-square)](https://en.wikipedia.org/wiki/C99)
[![License: MIT](https://img.shields.io/badge/license-MIT-18181f?style=flat-square)](LICENSE)

A zero-dependency C99 terminal application that procedurally generates random mazes and solves them using graph traversal algorithms.

## Overview

The program constructs perfect mazes using randomized recursive backtracking and finds the shortest exit path using Breadth-First Search (BFS). It includes an interactive terminal mode allowing users to manually navigate the generated maze with keyboard controls.

## Tech Stack

- **Language:** C (C99 Standard)
- **Libraries:** Standard C Library (`stdio.h`, `stdlib.h`, `time.h`, `string.h`)
- **Build System:** GNU Make / GCC

## Usage

```bash
# Compile with Makefile
make

# Or compile directly with GCC
gcc -O2 -std=c99 maze_generator.c -o maze_generator

# Run
./maze_generator
```

## License

Released under the [MIT License](LICENSE).

Copyright (c) 2026 innocous06. All rights reserved.
