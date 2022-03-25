/// @file main.cpp
/// @brief Program Main File 
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <thread>

#include "Grid.hpp"

// MACRO to determine if Current OS is Windows or UNIX
#ifdef _WIN32
#include <windows.h>

#include <cstdio>

#pragma execution_character_set("utf-8")

#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

std::atomic<bool> quit(false);

void CreateGrid(Grid&);
void LangtonAnt(Grid&);
void SignalHandler(void);
void Sleep(unsigned);
void ClearScreen(void);

int main(void) {
#ifdef _WIN32
  SetConsoleOutputCP(65001);
#endif
  ClearScreen();
  Grid grid;
  CreateGrid(grid);
  std::cin.get();
  Sleep(unsigned(500));
  std::thread game(LangtonAnt, std::ref(grid));
  std::thread signal_handler(SignalHandler);

  while (!quit)
    ;

  game.join();
  signal_handler.join();

  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
  std::cout << "|                                |" << std::endl;
  std::cout << "|     Exiting the program...     |" << std::endl;
  std::cout << "|                                |" << std::endl;
  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
  return 0;
}

/// @brief Create Grid Function. Request by input rows and columns numbers and
/// creates an empty white cells grid
/// @param grid Black and White Cells Grid
/// @return Void
void CreateGrid(Grid& grid) {
  int rows, columns;
  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "|     INSERT THE GRID DIMENSIONS     |" << std::endl;
  std::cout << "|                                    |" << std::endl;
  std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << std::endl;
  std::cout << "Rows    ->  ";
  std::cin >> rows;
  std::cout << "Columns ->  ";
  std::cin >> columns;
  ClearScreen();

  grid.Resize(rows, columns);
  std::cout << grid;
  Sleep(unsigned(500));
  ClearScreen();
}

/// @brief Langont Ant Function. Inserts and Ant and prints its movement pattern
/// on console
/// @param grid Black and White Cells Grid
/// @return Void
void LangtonAnt(Grid& grid) {
  grid.PushAnt();
  std::cout << grid;
  Sleep(unsigned(500));

  do {
    ClearScreen();
    grid.Update();
    std::cout << grid;
    Sleep(unsigned(500));
  } while (!quit);
}

/// @brief Signal Handler Function. Waits for an Input to end the game
/// @return Void
void SignalHandler(void) {
  std::cin.get();
  quit = true;
}

/// @brief Sleep Function. Waits a specified amount of miliseconds. It can be
/// used to make smooth transitions between processes
/// @return Void
void Sleep(unsigned miliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

/// @brief Clears all console contents.
/// @return Void
void ClearScreen(void) { std::system(CLEAR); }