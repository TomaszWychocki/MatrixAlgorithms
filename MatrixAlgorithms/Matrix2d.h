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

  /*
   * METHODS
   */
  double getValue(std::size_t row, std::size_t col);
  std::size_t getRows();
  std::size_t getCols();
  std::vector<double> toVector();

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