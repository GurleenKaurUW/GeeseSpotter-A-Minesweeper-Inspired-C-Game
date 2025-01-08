# GeeseSpotter-A-Minesweeper-Inspired-C-Game
GeeseSpotter is a C++ game inspired by the classic Minesweeper. In this game, players navigate a grid to uncover hidden geese while avoiding marked locations. The game dynamically computes geese neighbours and ensures a thrilling challenge for the player.

# GeeseSpotter Game

GeeseSpotter is a C++ game inspired by the classic Minesweeper. In this game, players navigate a grid to uncover hidden geese while avoiding marked locations. The game dynamically computes geese neighbours and ensures a thrilling challenge for the player.

## Features

- **Dynamic Board Creation**: Customizable grid size to suit the player's preferences.
- **Marking and Revealing**: Mark potential geese locations or reveal tiles to discover numbers or geese.
- **Neighbour Computation**: Accurately calculates the number of geese surrounding each tile.
- **Win Condition**: Automatically detects when the player has successfully revealed all non-geese tiles.
- **Memory Management**: Ensures efficient use of resources with proper allocation and cleanup.

## Key Functions

### Board Management
- **`create_board(x_dim, y_dim)`**: Dynamically creates a new game board of size `x_dim` x `y_dim`.
- **`clean_board(board)`**: Frees up allocated memory for the board.
- **`hide_board(board, x_dim, y_dim)`**: Masks the board to hide unrevealed tiles.
- **`print_board(board, x_dim, y_dim)`**: Displays the current state of the board, showing marks, hidden tiles, or revealed numbers.

### Gameplay Mechanics
- **`mark(board, x_dim, y_dim, x_loc, y_loc)`**: Marks or unmarks a tile as a potential geese location.
- **`reveal(board, x_dim, y_dim, x_loc, y_loc)`**: Reveals a tile—if the tile contains a goose, the game ends; otherwise, neighbouring tiles may be revealed recursively.

### Logic and Rules
- **`compute_neighbours(board, x_dim, y_dim)`**: Calculates the number of geese adjacent to each tile.
- **`is_game_won(board, x_dim, y_dim)`**: Checks if the player has won the game by revealing all non-geese tiles.

## Sample Usage

```cpp
#include "geesespotter_lib.h"
#include <iostream>

int main() {
    // Board dimensions
    std::size_t x_dim = 5, y_dim = 5;

    // Create and initialize the board
    char *board = create_board(x_dim, y_dim);
    hide_board(board, x_dim, y_dim);

    // Example gameplay
    print_board(board, x_dim, y_dim);
    mark(board, x_dim, y_dim, 1, 1);
    compute_neighbours(board, x_dim, y_dim);
    reveal(board, x_dim, y_dim, 2, 2);

    // Clean up memory
    clean_board(board);

    return 0;
}
```

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/geesespotter.git
   ```
2. Navigate to the project directory:
   ```bash
   cd geesespotter
   ```
3. Compile the code using a C++ compiler (e.g., g++):
   ```bash
   g++ -o geesespotter geesespotter.cpp
   ```
4. Run the game:
   ```bash
   ./geesespotter
   ```

## Future Enhancements

- Add a graphical user interface (GUI) for better visualization.
- Implement difficulty levels with varying numbers of geese.
- Save and load game states to continue gameplay later.
- Add a timer and leaderboard for competitive play.

---
Feel free to fork and contribute to this project to make it even better!

