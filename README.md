# HardwareSoftware


The /PROJECT file is where the functional arduino setup is stored.

It also holds the arduino versions of the code.

The following have been simplified
-BoardClass.h
-BoardClass.cpp
-Snake.h
-Snake.cpp
Added scripts:
-Apple.h
-Apple.cpp
-Game.h
-Game.cpp
-Point.h

The current game uses a grid to check collision and to allow us to draw a background
We store the player and apples as a 2 byte integer or a uint8_t x, uint8_t y
And then just draw them in the scene after the board.

// CLASS GAME

Stores the current game state, and references to the snake, apple and board objects.
PLANNED:
- Add a GAMESTATE enum's for MENU, PLAYING, STARTING, RUNNING, LOST, EXIT, OPTIONS.
    This will be used to transition from the menu to the game and to the various menu's

// PROJECT.INO

PLANNED:
- Add a main menu with Play, Options, and Exit buttons, and a highscore display
- Draw the current score on the screen to the right.

// SNAKE
- FINISHED IMPLEMENTATION
- ADD COMMENTS FOR READABILITY

// BOARDCLASS
- FINISHED IMPLEMENTATION
- ADD COMMENTS FOR READABILITY

// APPLE
- FINISHED IMPLEMENTATION
- ADD COMMENTS FOR READABILITY

// POINT
- FINISHED IMPLEMENTATION
- ADD COMMENTS FOR READABILITY