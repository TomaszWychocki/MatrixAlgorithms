#include <iostream>
#include "Matrix2d.h"
#include <assert.h>

void TEST_001_toVector()
{
  Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
  std::vector<double> expectedResult = { 2, 3, 4, 5, 6, 7 };
  assert(mat.toVector() == expectedResult);

  Matrix2d mat2 = { {5, 6, 7} };
  std::vector<double> expectedResult2 = { 5, 6, 7 };
  assert(mat2.toVector() == expectedResult2);

  Matrix2d mat3 = { {7}, {9}, {2} };
  std::vector<double> expectedResult3 = { 7, 9, 2 };
  assert(mat3.toVector() == expectedResult3);
}

void TEST_002_getCols()
{
  Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
  assert(mat.getCols() == 3);

  Matrix2d mat2 = { {5, 6, 7} };
  assert(mat2.getCols() == 3);

  Matrix2d mat3 = { {7}, {9}, {2} };
  assert(mat3.getCols() == 1);
}

void TEST_003_getRows()
{
  Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
  assert(mat.getRows() == 2);

  Matrix2d mat2 = { {5, 6, 7} };
  assert(mat2.getRows() == 1);

  Matrix2d mat3 = { {7}, {9}, {2} };
  assert(mat3.getRows() == 3);
}

int main()
{
  TEST_001_toVector();
  TEST_002_getCols();
  TEST_003_getRows();
}