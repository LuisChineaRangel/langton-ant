/// @file Ant.cpp
/// @brief Ant Class Source Code
#include "Ant.hpp"

#include "Grid.hpp"
#include "SmartVector.hpp"

///////////////////////////////////////////////////////
// CLASS MEMBER FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Default Constructor. Initializes ant behavior and attributes
/// @param grid Pointer of Grid where ant is located
/// @param row Ant row on grid
/// @param column Ant column on grid
Ant::Ant(Grid *grid, size_t row, size_t column)
    : dir_(up), sprite_("↑"), grid_(grid), row_(row), column_(column) {
  Position().taken_ = true;
}

/// @brief Destructor. Erases all contents and the ant
Ant::~Ant() { grid_ = NULL; }

/// @brief Direction Getter
/// @return Which direction is taking the ant
Direction Ant::getDirection(void) const { return dir_; }

/// @brief Grid Getter
/// @return Ant's Grid Location
Grid *Ant::getGridP(void) const { return grid_; }

/// @brief Direction Setter
/// @return Void
void Ant::setDirection(Direction dir) { dir = dir; }

/// @brief Grid Setter
/// @return Void
void Ant::setGrid(Grid *grid) { grid_ = grid; }

/// @brief Move Method. Changes the ant current position and its color, and
/// rotates to its new direction
/// @return Void
void Ant::Move(void) {
  size_t row = row_, column = column_;
  Position().taken_ = false;
  SwitchCellColor(Position());
  Rotate();

  while (grid_->OutOfBounds(row_, column_)) {
    row_ = row;
    column_ = column;
    Rotate();
  }

  while ((*grid_)[row_][column_].taken_) {
    row_ = row;
    column_ = column;
    Rotate();
  }

  Position().taken_ = true;
}

/// @brief Rotate method. Changes ant current direction
/// @return Void
void Ant::Rotate(void) {
  switch (static_cast<int>(Position().color_)) {
    case white:
      dir_ = static_cast<Direction>((dir_ + 1) % NUM_DIR);
      break;
    case black:
      dir_ = ((dir_ - 1) % NUM_DIR) < 0 ? static_cast<Direction>(NUM_DIR - 1)
                                        : static_cast<Direction>(dir_ - 1);
      break;
  }

  switch (dir_) {
    case up:
      sprite_ = "↑";
      --row_;
      break;
    case left:
      sprite_ = "←";
      --column_;
      break;
    case down:
      sprite_ = "↓";
      ++row_;
      break;
    case right:
      sprite_ = "→";
      ++column_;
      break;
    default:
      break;
  }
}

/// @brief Position Method
/// @return Cell where Ant is located
Cell &Ant::Position(void) { return (*grid_)[row_][column_]; }

/// @brief Write Method
/// @param os Outputstream
/// @return Ant's Sprite
std::ostream &Ant::Write(std::ostream &os) const { return os << sprite_; }

/// @brief Assignation operator Overload
/// @param ant Assigned ant to copy
/// @return Ant with new values
Ant &Ant::operator=(const Ant &ant) {
  dir_ = ant.getDirection();
  grid_ = ant.getGridP();

  return (*this);
}

/// @brief Switch Cell Color Method
/// @param cell Cell to switch
void Ant::SwitchCellColor(Cell &cell) const {
  cell.color_ = static_cast<Color>((cell.color_ + 1) % NUM_CELL);
}

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream
/// @param ant Langton's Ant to write
/// @return Ant's direction
std::ostream &operator<<(std::ostream &os, const Ant &ant) {
  return ant.Write(os);
}