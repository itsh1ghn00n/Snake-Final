#include "Game.h"

Game::Game(int gridW, int gridH) 
  : gridW(gridW), gridH(gridH), gameBoard(gridW, gridH),
    running(false), dirX(1), dirY(0), inputDirX(0), inputDirY(0) {}

void Game::start() {
  dirX = 1;
  dirY = 0;
  snake.init(4);
  apple.spawn(gridW, gridH, snake);
  running = true;
}

void Game::reset() {
  dirX = 1;
  dirY = 0;
  snake.init(4);
  apple.spawn(gridW, gridH, snake);
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

  Point prevTail = snake.getTail();
  Point newHead = snake.getHead();
  newHead.x += dirX;
  newHead.y += dirY;

  if (newHead.x < 0 ||newHead.x >= gridW) {
    running = false;
  } if (newHead.y < 0 || newHead.y >= gridH) {
    running = false;
    return;
  }

  if (snake.isOnBody(newHead.x, newHead.y)) {
    running = false;
    return;
  }

  snake.setPrevTail(snake.getTail());

  // move
  snake.move(dirX, dirY);

  // apple collision
  if (snake.getHead().x == apple.getPos().x && snake.getHead().y == apple.getPos().y) {
    snake.grow(1);
    apple.spawn(gridW, gridH, snake);
  }
}