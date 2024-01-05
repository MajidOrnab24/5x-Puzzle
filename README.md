# 5X PUZZLE GAME DOCUMENTATION

## Overview:
The 5X Puzzle game is a graphical user interface (GUI) project implemented in C++. The game is reminiscent of the popular 2048 game and includes features such as a 5x5 grid, a leaderboard, and save/load game options. Players aim to achieve specific targets while merging tiles with the same values.

## Files:
### `declarations.h`:
Contains necessary header files, constants, and function prototypes used in the project.
Defines tasks such as handling high scores, game outcomes, tile movements, and user interface.

### `functions.h`:
Defines functions responsible for various aspects of the game, including gameplay, user interface, file handling, and scoring.
Functions cover tasks like updating the game state, handling user input, checking game over conditions, and managing the graphical interface.

### `main.cpp`:
The main entry point of the program.
Initializes the graphics window, reads high scores from a file, and navigates through the game menu.
Includes the necessary header files and global variables for the game.

## Global Variables:
- `a[5][5]`: Represents the game grid.
- `temp[5][5]`: Stores the temporary state of the game grid.
- `tar`: Represents the target score for players to achieve.
- `score`: Current score of the player.
- `high_score`: Highest score achieved.
- `key`: Represents the user input during gameplay.
- `opt`: Represents the user's menu choice.
- `nameString[80]`: Stores the player's name.
- `high_scorer[80]`: Stores the name of the player with the highest score.
- `mainMenu[5]`: Options available in the main menu.

## Functions:
- `help()`: Displays the game instructions and visual examples.
- `high_scores()`: Displays the highest scorer and their score.
- `resume()`: Resumes a saved game state from the "savestate.txt" file.
- `victory()`: Displays a victory message when the player achieves the target.
- `if_win()`: Checks if the player has achieved the target.
- `over()`: Displays a game-over message and resets the game state.
- `game_over()`: Checks if the game is over based on the current state.
- `add_tile()`: Adds a new tile to the grid during gameplay.
- `possible()`: Checks if the game state has changed.
- `right()`, `down()`, `up()`, `left()`: Functions for moving tiles in different directions.
- `save()`: Saves the current game state to the "savestate.txt" file.
- `play()`: Handles the main gameplay loop.
- `high_count()`: Updates and saves the high score.
- `update()`: Updates the graphical interface based on the current game state.
- `draw()`: Draws the initial game interface.
- `init()`: Initializes the game grid and reads the high score from "highscores.txt".
- `doCursor(int)`: Handles the cursor display during user input.
- `getGrString(char)*`: Gets input as a string from the user.
- `newLine()`: Moves the cursor to a new line in the console.
- `start()`: Displays the initial player name input screen.
- `target()`: Allows the player to choose a target score.
- `reverse_video(int, int, char)`, `normal_video(int, int, char)`: Functions for displaying text in reverse and normal video modes.
- `menu()`: Displays the main menu and handles user input.
- `home_draw()`: Draws the home screen of the game.
- `control_menu()`: Manages the game control menu and navigation.
- `home()`: Displays the introductory screen.

## Images:
- `image.jpg`: [Description of the image and its purpose in the game]
- `image2.jpg`: [Description of the image and its purpose in the game]
- `victory.jpg`: [Description of the victory image and when it is displayed]

## Project Structure:
- `.gitignore`
- `5x Puzzle.cbp`
- `5x Puzzle.depend`
- `5x Puzzle.layout`
- `CMakeLists.txt`
- `High.gm`
- `README.md`
- `declarations.h`
- `functions.h`
- `highscores.txt`
- `image.jpg`
- `image2.jpg`
- `main.cpp`
- `savestate.txt`
- `victory.jpg`

## Compilation and Execution:
The program is compiled using a C++ compiler with the necessary graphics library.
Execute the compiled program to play the 5X Puzzle game.



## Conclusion:
The 5X Puzzle game provides an engaging and challenging experience, combining logical thinking and strategic moves to achieve the target score. Players can enjoy the game's features, including saving progress and viewing high scores.

