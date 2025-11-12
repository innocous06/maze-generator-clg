# maze-generator-clg

A C program that generates random mazes using recursive backtracking and solves them using breadth-first search. Supports both automatic solving and manual navigation modes. Written to the C99 standard with no external dependencies.

## Requirements

- GCC compiler
- Make (optional)

## Installation

```sh
git clone https://github.com/innocous06/maze-generator-clg.git
cd maze-generator-clg
```

## Usage

```sh
# Using Make
make
./maze

# Manual compile
gcc -O2 maze_generator.c -o maze
./maze
```

From the main menu:

1. Generate a maze — specify dimensions (11 to 49, odd numbers only)
2. Display the current maze
3. Find shortest path — BFS solve with path visualised as `*`
4. Manual mode — navigate with W/A/S/D keys, Q to quit
5. Quick demo — generates a 21x21 maze and shows solution

## License

MIT License

Copyright (c) 2024 innocous06

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
