#include "Grid.hpp"

/// @brief Default Constructor.
Grid::Grid(size_t rows, size_t columns) {
  Resize(0, rows);
  for (size_t i = Begin(); i < End(); ++i)
    (*this)[i].Resize(0, columns);
}

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

/// @brief Push Ant Method. Inserts a new Langton ant to the grid
/// @return Void
void Grid::PushAnt(const size_t row, const size_t column) {
  anthill_.push_back(new Ant(this, row, column));
}

/// @brief
void Grid::Update(void) {
  std::list<Ant *>::iterator it;
  for (it = anthill_.begin(); it != anthill_.end(); ++it)
    (*it)->Move();
}

bool Grid::OutOfBounds(const size_t row, const size_t column) const {
  if ((row < Begin()) || (row >= End()))
    return true;

  if ((column < (*this)[(*this).Begin()].Begin()) ||
      (column >= (*this)[(*this).Begin()].End()))
    return true;

  return false;
}

std::ostream &Grid::Write(std::ostream &os) const {
  write_border(os, (*this));
  os << std::endl;

  for (size_t i = Begin(); i < End(); ++i) {
    os << "█";
    for (size_t j = (*this)[Begin()].Begin(); j < (*this)[Begin()].End(); ++j) {
      const Ant *hormiga = NULL;

      for (std::list<Ant *>::const_iterator it = anthill_.begin();
           it != anthill_.end(); ++it) {
        if (&(*this)[i][j] == &(*it)->Position()) {
          hormiga = (*it);
          break;
        }
      }

      if (hormiga)
        os << *hormiga;
      else if ((*this)[i][j].color_ == white)
        os << " ";
      else
        os << "X";
    }
    os << "█" << std::endl;
  }
  write_border(os, (*this));
  os << std::endl;

  return os;
}

std::ostream &write_border(std::ostream &os, const Grid &mundo) {
  for (size_t i = 0; i <= mundo[mundo.Begin()].size() + 1; i++) {
    os << "▀";
  }

  return os;
}

std::ostream &operator<<(std::ostream &os, const Grid &mundo) {
  return mundo.Write(os);
}