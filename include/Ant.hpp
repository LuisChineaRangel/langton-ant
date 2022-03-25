/// @file Ant.hpp
/// @brief Ant Class Header
#pragma once

#include <cmath>
#include <iostream>
#include <string>

class WrongIndex;

/** @name Color Enum */
/// @brief Grid's cells color.
/// @{
enum Color { black, white, NUM_CELL };
/// @}

/** @name Cell Structure */
/// @brief Grid's Squares in which the Langton's ant travels.
/// @{
struct Cell {
  Color color_ = white;
  bool taken_ = false;
};
/// @}

/** @name Direction Structure */
/// @brief Possible directions for the ant.
/// @{
enum Direction { up, left, down, right, NUM_DIR };
/// @}

/** @name Types of Grids */
/// @brief See Grid, FiniteGrid and InfiniteGrid for more information.
/// @{
class Grid;
class FiniteGrid;
class InfiniteGrid;
/// @}

/// @class Ant
/// @brief Represents a Langton's Ant. It defines the ant behavior and stores
/// the current position and direction.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Ant langton;
/// langton.move(grid);
/// std::cout << langton;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Ant {
 protected:
  Direction dir_;
  std::string sprite_;
  Grid *grid_;
  size_t row_, column_;

 public:
  /** @name Constructors and Destructor */
  /// @{
  Ant(Grid * = NULL, size_t = 0, size_t = 0);
  ~Ant();
  /// @}

  /** @name Getters */
  /// @{
  Direction getDirection(void) const;
  Grid *getGridP(void) const;
  /// @}

  /** @name Setters */
  /// @{
  void setDirection(Direction);
  void setGrid(Grid *);
  /// @}

  /** @name Auxiliar Public Methods */
  /// @{
  virtual void Move(void);
  void Rotate();
  Cell &Position(void);
  std::ostream &Write(std::ostream &) const;
  Ant &operator=(const Ant &);
  /// @}

 protected:
  /** @name Auxiliar Protected Methods */
  /// @{
  void SwitchCellColor(Cell &) const;
  /// @}
};

std::ostream &operator<<(std::ostream &, const Ant &);