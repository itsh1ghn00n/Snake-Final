#include "Game.h"

Game::Game(int gridW, int gridH, int xoffset, int yoffset) 
  : gridW(gridW), gridH(gridH), 
    xOffset(xoffset), yOffset(yoffset), 
    gameBoard(gridW, gridH),
    running(false), dirX(1), dirY(0), 
    inputDirX(0), inputDirY(0) 
    
    {
      for (int x = 0; x < gridW; x++)
        for (int y = 0; y < gridH; y++)
            snakeGrid[x][y] = 0;
    }

void Game::start() {
  dirX = 1;
  dirY = 0;

  snake.init(gridW / 2, gridH / 2, 4, snakeGrid);

  apple.spawn(gridW, gridH, 0, 0, snakeGrid);
  running = true;
}

void Game::reset() {
  dirX = 1;
  dirY = 0;

  snake.init(gridW / 2, gridH / 2, 4, snakeGrid);

  apple.spawn(gridW, gridH, 0, 0, snakeGrid);
  running = false;
}

void Game::update(int inputDirX, int inputDirY) {
  if (!running) return;

  // If our input's are not in opposite directions
  if (!(inputDirX == -dirX && inputDirY == -dirY)) {
    if (inputDirX != 0 || inputDirY != 0) {
      dirX = inputDirX;
      dirY = inputDirY;
    }
  }

  Point newHead = snake.getHead();
  newHead.x += dirX;
  newHead.y += dirY;

  snake.setNewHead(snake.getHead());

  if (newHead.x < 0 ||newHead.x >= gridW) {
    running = false;
    return;
  } if (newHead.y < 0 || newHead.y >= gridH) {
    running = false;
    return;
  }

  // Collision
  if (snakeGrid[newHead.x][newHead.y] != EMPTY) {
    running = false;
    return;
  }
  // move
  snake.move(dirX, dirY, snakeGrid);

  // apple collision
  if (snake.getHead().x == apple.getPos().x && snake.getHead().y == apple.getPos().y) {
     
    if (apple.getIsGolden()) { snake.grow(5); } 
    else { snake.grow(1); }

    apple.spawn(gridW, gridH, xOffset, yOffset, snakeGrid);
  }
}