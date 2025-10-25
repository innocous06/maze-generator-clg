# 🎮 Maze Generator and Solver

An interactive C program that generates random mazes using recursive backtracking and solves them using BFS (Breadth-First Search). Features both automatic solving and manual gameplay modes!
[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/innocous06/maze-generator)


![C](https://img.shields.io/badge/language-C-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS%20%7C%20Windows-lightgrey.svg)

## ✨ Features

- 🎲 **Random Maze Generation** - Uses recursive backtracking algorithm with added complexity
- 🧭 **Automatic Solver** - Finds shortest path using BFS algorithm
- 🎮 **Manual Mode** - Play through the maze yourself with WASD controls
- 📊 **Multiple Sizes** - Generate mazes from 11×11 up to 49×49
- 🎯 **Path Visualization** - See the optimal solution highlighted
- 📈 **Move Tracking** - Counts your moves in manual mode

## 🚀 Quick Start

### Run Online (No Installation Required!)

**GitHub Codespaces:**
1. Click the green **Code** button above
2. Select **Codespaces** tab
3. Click **Create codespace on main**
4. In the terminal, run:
   ```bash
   make run
   ```

### Local Installation

**Prerequisites:**
- GCC compiler
- Make (optional, for easier compilation)

**Compile and Run:**
```bash
# Using Make
make
./maze

# Or compile manually
gcc maze_generator.c -o maze
./maze
```

## 🎯 How to Use

### Main Menu Options

1. **Generate Maze** - Create a new random maze (11-49 rows/cols)
2. **Display Maze** - Show the current maze
3. **Find Shortest Path** - Automatically solve and display solution
4. **Manual Mode** - Play through the maze yourself
5. **Quick Demo** - Generate a 21×21 maze and show solution
6. **Exit** - Quit the program

### Manual Mode Controls

- **W** - Move Up ⬆️
- **S** - Move Down ⬇️
- **A** - Move Left ⬅️
- **D** - Move Right ➡️
- **Q** - Quit to menu

### Maze Symbols

- `S` - Start position 🏁
- `E` - End position 🎯
- `#` - Wall 🧱
- ` ` - Path (space)
- `*` - Solution path ⭐
- `@` - Your position (manual mode) 🎮
- `.` - Visited cells (manual mode) 👣

## 🧮 Algorithms

### Maze Generation
- **Algorithm:** Randomized Depth-First Search (Recursive Backtracking)
- **Enhancement:** Adds extra paths to increase complexity
- **Start/End:** Positioned to maximize distance

### Pathfinding
- **Algorithm:** Breadth-First Search (BFS)
- **Guarantee:** Always finds the shortest path
- **Visualization:** Marks solution with `*` characters

## 📸 Example Output

```
 # # # # # # # # # # # # # # # # # # # # # 
 # # # # # # # # # # # # # # # # # # # # # 
 # # S #                       #       # # 
 # #   # # #   # # #   # # #   #   # # # # 
 # #       #       #   #       #       # # 
 # # # #   #   #   #   #   # # # # #   # # 
 # #       #   #   #   #       #       # # 
 # #   # # # # #   #   # # #   #   # # # # 
 # #                           #       # # 
 # # #   # # # # # #   #   #   #   #   # # 
 # #               #   #               # # 
 # #   # # #   #       # # #   # # #   # # 
 # #   #       #   #       #   #   #   # # 
 # #   #   # # # # # # #   #   #   #   # # 
 # #   #                   #   #       # # 
 # #   # # # # # # # # # # #   #   # # # # 
 # #                           #   #   # # 
 # # # # # # # # # # # # # # #     #   # # 
 # #                                 E # # 
 # # # # # # # # # # # # # # # # # # # # # 
 # # # # # # # # # # # # # # # # # # # # # 

Path length: 40 steps
```

## 🛠️ Compilation Options

```bash
# Debug mode with symbols
gcc -g maze_generator.c -o maze_debug

# Optimized build
gcc -O2 maze_generator.c -o maze

# With warnings
gcc -Wall -Wextra maze_generator.c -o maze
```

## 📋 Technical Details

- **Language:** C (C99 standard)
- **Maximum Size:** 50×50 grid
- **Memory:** Static allocation for efficiency
- **Dependencies:** Standard C library only

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs 🐛
- Suggest features 💡
- Submit pull requests 🔧

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 👨‍💻 Author

**innocous06**
- GitHub: [@innocous06](https://github.com/innocous06)
- Location: Himalayas 🏔️

## 🌟 Acknowledgments

- Maze generation inspired by classic recursive backtracking algorithms
- BFS pathfinding for optimal solution finding
- Built for educational purposes and fun! 🎓

---

⭐ **Star this repo if you find it helpful!**
