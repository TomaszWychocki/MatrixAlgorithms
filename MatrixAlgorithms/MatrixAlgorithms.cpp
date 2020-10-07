#include <iostream>
#include "Matrix2d.h"
#include <assert.h>

void TEST_001_toVector()
{
  Matrix2d mat(2, 3, { {2, 3, 4} , {5, 6, 7} });
  std::vector<double> expectedResult = { 2, 3, 4, 5, 6, 7 };
  assert(mat.toVector() == expectedResult);

  Matrix2d mat2(1, 3, { {5, 6, 7} });
  std::vector<double> expectedResult2 = { 5, 6, 7 };
  assert(mat2.toVector() == expectedResult2);

  Matrix2d mat3(3, 1, { {7}, {9}, {2} });
  std::vector<double> expectedResult3 = { 7, 9, 2 };
  assert(mat3.toVector() == expectedResult3);
}

int main()
{
  TEST_001_toVector();
}