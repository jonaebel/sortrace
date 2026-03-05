# 🏁 sortrace

A terminal-based sorting algorithm visualizer written in C. Watch algorithms race each other in real time using ASCII bar charts.

```
3  ###
7  #######
1  #
5  #####
8  ########
```

## Features (planned)
- ASCII visualization of arrays in the terminal
- Multiple sorting algorithms racing side by side: Bubble Sort, Merge Sort, Quick Sort
- Step counter and time measurement per algorithm
- Race history saved to file
- Colorized output with ANSI escape codes

## Algorithms
| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|-----------------|
| Bubble Sort | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n) |
| Quick Sort | O(n log n) avg | O(log n) |

## Build

```bash
make        # compile
./sortrace  # run
make clean  # remove binary
```

## Requirements
- clang (macOS) or gcc (Linux)
- make

## Project Structure
```
sortrace/
├── main.c        # entry point
├── array.h/.c    # array creation and management
├── render.h/.c   # ASCII visualization
├── sorting.h/.c  # sorting algorithms
├── history.h/.c  # linked list for race history
├── fileio.h/.c   # save/load results
└── Makefile
```

## Dev Log
### Step 01
- Array generation with dynamic memory (`malloc`)
- ASCII bar chart visualization
- Makefile setup

### Step 02
- Implemented Bubble Sort, Merge Sort, Quick Sort
- copy_array helper for independent sorting
- All three algorithms tested and working

### Step 03
- Added SortAlgorithm enum and Sorter struct in sorting.h
- create_sorter() and free_sorter() implemented
- main.c refactored to use Sorter structs

### Step 04
- Added HistoryNode linked list to track sorting steps
- History integrated into Sorter struct
- Each algorithm records state after every swap/merge
- print_history shows step-by-step visualization

---

> Built as a C programming exercise for university exams.
