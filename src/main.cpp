#include "Grid.hpp"

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <thread>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

std::atomic<bool> quit(false);

void LangtonAnt(Grid &);
void SignalHandler(void);
void ClearScreen(void);

int main(void)
{
  Grid grid(20, 20);

  std::thread game(LangtonAnt, std::ref(grid));
  std::thread signal_handler(SignalHandler);

  while (!quit)
    ;

  game.join();
  signal_handler.join();

  std::cout << "Exiting the program..." << std::endl;

  return 0;
}

void LangtonAnt(Grid &grid)
{
  std::cout << grid;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  grid.PushAnt();
  std::cout << grid;
  std::this_thread::sleep_for(std::chrono::milliseconds(500));

  do
  {
    ClearScreen();
    grid.Update();
    std::cout << grid;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  } while (!quit);
}

void SignalHandler(void)
{
  std::cin.get();
  quit = true;
}

void ClearScreen(void) { std::system(CLEAR); }