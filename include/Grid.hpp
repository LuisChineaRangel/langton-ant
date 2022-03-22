/// @file Grid.hpp
/// @brief Grid Class Header
#pragma once

#include <list>

#include "Ant.hpp"
#include "SmartVector.hpp"

/// @class Ant
/// @brief Represents a Langton's Ant Grid. It defines the ant behavior and
/// stores the current position and direction.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Ant solution;
/// solution.insertCoin(ONE_CENT);
/// std::cout << solution;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Grid : public SmartVector<SmartVector<Cell>> {
protected:
  std::list<Ant *> anthill_;

public:
  /** @name Constructors and Destructor */
  /// @{
  Grid(size_t, size_t);
  ~Grid();
  /// @}

  /** @name Getters */
  /// @{
  std::list<Ant *> getAnthill(void) const;
  /// }@

  /** @name Setters */
  /// @{
  void setAnthill(std::list<Ant *>);
  /// }@

  /** @name Auxiliar Public Methods */
  /// @{
  virtual void PushAnt(void);
  virtual void PushAnt(const size_t, const size_t);
  void Update(void);
  bool OutOfBounds(const size_t, const size_t) const;
  std::ostream &Write(std::ostream &) const;
  /// }@
};

std::ostream &write_border(std::ostream &, const Grid &);
std::ostream &operator<<(std::ostream &, const Grid &);