/// @file Grid.hpp
/// @brief Grid Class Header
#pragma once

#include <list>

#include "ant.hpp"
#include "smartVector.hpp"

/// @class Grid
/// @brief Black and White Cells Grid. On its surface the ants moves following
/// the Langton's Ant rules.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Grid grid(10, 10);
/// grid.PushAnt();
/// std::cout << grid;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Grid : public SmartVector<SmartVector<Cell>> {
 protected:
  std::list<Ant *> anthill_;

 public:
  /** @name Constructors and Destructor */
  /// @{
  Grid(size_t = 0, size_t = 0);
  ~Grid();
  /// @}

  /** @name Getters */
  /// @{
  std::list<Ant *> getAnthill(void) const;
  /// @}

  /** @name Setters */
  /// @{
  void setAnthill(std::list<Ant *>);
  /// @}

  /** @name Auxiliar Public Methods */
  /// @{
  virtual void PushAnt(void);
  virtual void PushAnt(const size_t, const size_t);

  void Resize(size_t, size_t);
  void Update(void);
  bool OutOfBounds(const size_t, const size_t) const;
  std::ostream &Write(std::ostream &) const;
  std::ostream &PrintUpperBorders(std::ostream &) const;
  std::ostream& PrintLowerBorders(std::ostream&) const;
  /// @}
};


std::ostream &operator<<(std::ostream &, const Grid &);