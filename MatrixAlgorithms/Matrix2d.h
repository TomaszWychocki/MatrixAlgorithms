#pragma once
#include <vector>
#include <iostream>

class Matrix2d
{
public:
  /*
   * CONSTRUCTOR
   */
  Matrix2d();
  Matrix2d(std::initializer_list<std::initializer_list<double>> lst);

  /*
   * OPERATOR
   */
  friend std::ostream& operator<<(std::ostream& os, const Matrix2d& matrix);
  bool operator==(const Matrix2d& matrix) const;
  bool operator!=(const Matrix2d& matrix) const;

  /*
   * METHODS
   */
  double getValue(std::size_t row, std::size_t col) const;
  std::size_t getRows() const;
  std::size_t getCols() const;
  std::vector<double> toVector() const;

private:
  /*
   * FIELDS
   */
  const std::size_t rows;
  const std::size_t cols;

  /*
   * METHODS
   */
  std::vector<std::vector<double>> numbersArray;
};