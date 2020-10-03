#include "Matrix2d.h"
#include <vector>

Matrix2d::Matrix2d()
{
}

Matrix2d::Matrix2d(std::size_t rows, std::size_t cols, std::initializer_list<std::initializer_list<double>> lst)
{
  std::size_t row = 0;

  for (const auto& l : lst)
  {
    std::vector<double> vec{ l };
    this->numbersArray.push_back(vec);
  }
}

double Matrix2d::getValue(std::size_t row, std::size_t col)
{
  return this->numbersArray[row][col];
}

std::vector<double> Matrix2d::toVector()
{
  std::vector<double> vec;

  for (const auto& row : this->numbersArray)
  {
    vec.insert(vec.end(), row.begin(), row.end());
  }

  return vec;
}

std::ostream& operator<<(std::ostream& os, const Matrix2d& matrix)
{
  for (const auto& row : matrix.numbersArray)
  {
    for (const auto& elem : row)
    {
      os << elem << " ";
    }
    os << std::endl;
  }

  return os;
}
