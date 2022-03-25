/// @file Grid.cpp
/// @brief Grid Class Source Code
#include "Grid.hpp"

/// @brief Default Constructor
/// @param rows Number of rows in the grid
/// @param columns Number of columns in the grid
Grid::Grid(size_t rows, size_t columns) { Resize(rows, columns); }

/// @brief Destructor
Grid::~Grid() {}

/// @brief Anthill Getter
/// @return Collection of Langton's ants on the grid
std::list<Ant *> Grid::getAnthill(void) const { return anthill_; }

/// @brief Anthill Setter
/// @return Void
void Grid::setAnthill(const std::list<Ant *> anthill) { anthill_ = anthill; }

/// @brief Default Push Ant Method. Inserts a new Langton ant to the grid
/// @return Void
void Grid::PushAnt(void) {
  anthill_.push_back(
      new Ant(this, (*this).Center(), (*this)[Begin()].Center()));
}

/// @brief Push Ant Method. Inserts a new Langton ant to the grid in a specific
/// cell
/// @return Void
void Grid::PushAnt(const size_t row, const size_t column) {
  anthill_.push_back(new Ant(this, row, column));
}

/// @brief Resize the grid dimensions
/// @param rows Number of rows in the grid
/// @param columns Number of columns in the grid
/// @return Void
void Grid::Resize(size_t rows, size_t columns) {
  clear();
  if (rows > 0 && columns > 0) {
    SmartVector::Resize(0, rows);
    for (size_t i = Begin(); i < End(); ++i)
      (*this)[i].SmartVector::Resize(0, columns);
  }
}

/// @brief Update Method. Moves all the ants of the grid
/// @return Void
void Grid::Update(void) {
  std::list<Ant *>::iterator it;
  for (it = anthill_.begin(); it != anthill_.end(); ++it) (*it)->Move();
}

/// @brief OutOfBounds Method. Receives two indexes given to check if they
/// belong to the grids
/// @param row Row to check
/// @param column Column to check
/// @return Void
bool Grid::OutOfBounds(const size_t row, const size_t column) const {
  if ((row < Begin()) || (row >= End())) return true;

  if ((column < (*this)[(*this).Begin()].Begin()) ||
      (column >= (*this)[(*this).Begin()].End()))
    return true;

  return false;
}

/// @brief Write Method
/// @param os Outputstream
/// @return All the Cells of the Grid and the Anthill
std::ostream &Grid::Write(std::ostream &os) const {
  PrintBorders(os);
  os << std::endl;

  for (size_t i = Begin(); i < End(); ++i) {
    os << "|";
    for (size_t j = (*this)[Begin()].Begin(); j < (*this)[Begin()].End(); ++j) {
      const Ant *ant = NULL;

      for (std::list<Ant *>::const_iterator it = anthill_.begin();
           it != anthill_.end(); ++it) {
        if (&(*this)[i][j] == &(*it)->Position()) {
          ant = (*it);
          break;
        }
      }

      if (ant)
        os << *ant;
      else if ((*this)[i][j].color_ == white)
        os << " ";
      else
        os << "X";
    }
    os << "|" << std::endl;
  }
  PrintBorders(os);
  os << std::endl;

  return os;
}

/// @brief Write Border Method
/// @param os Outputstream
/// @return The Upper and Lower Bounds of the Grid
std::ostream &Grid::PrintBorders(std::ostream &os) const {
  for (size_t i = 0; i <= (*this)[Begin()].size() + 1; i++) {
    os << "■";
  }

  return os;
}

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream
/// @param grid Grid to write
/// @return All the Cells of the Grid and the Anthill
std::ostream &operator<<(std::ostream &os, const Grid &grid) {
  return grid.Write(os);
}