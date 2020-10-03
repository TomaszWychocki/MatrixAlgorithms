#include "Matrix2d.h"
#include <vector>

Matrix2d::Matrix2d()
  : rows(0)
  , cols(0)
{
}

Matrix2d::Matrix2d(std::initializer_list<std::initializer_list<double>> lst)
  : rows(lst.size())
  , cols(static_cast<std::initializer_list<double>>(*lst.begin()).size())
{
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

std::size_t Matrix2d::getRows()
{
  return this->rows;
}

std::size_t Matrix2d::getCols()
{
  return this->cols;
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
