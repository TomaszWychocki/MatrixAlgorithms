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
  Matrix2d(std::size_t rows, std::size_t cols, std::initializer_list<std::initializer_list<double>> lst);

  /*
   * OPERATOR
   */
  friend std::ostream& operator<<(std::ostream& os, const Matrix2d& matrix);

  /*
   * METHODS
   */
  double getValue(std::size_t row, std::size_t col);
  std::vector<double> toVector();

private:
  std::vector<std::vector<double>> numbersArray;
};