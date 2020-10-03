#include <iostream>
#include "Matrix2d.h"
#include <assert.h>

void TEST_001_toVector()
{
  std::size_t R = 2, C = 3;
  Matrix2d mat(R, C, { {2, 3, 4} , {5, 6, 7} });
  std::vector<double> expectedResult = { 2, 3, 4, 5, 6, 7 };
  assert(mat.toVector() == expectedResult);
  
  for(std::size_t i =  0; i < R; ++i)
    for(std::size_t j = 0; j < C; ++j)
        assert(mat.getValue(i, j) == expectedResult[i * C + j]);

  R = 1, C = 3;
  Matrix2d mat2(R, C, { {5, 6, 7} });
  std::vector<double> expectedResult2 = { 5, 6, 7 };
  assert(mat2.toVector() == expectedResult2);
  
  for(std::size_t i =  0; i < R; ++i)
    for(std::size_t j = 0; j < C; ++j)
        assert(mat2.getValue(i, j) == expectedResult2[i * C + j]);

  R = 3, C = 1;
  Matrix2d mat3(R, C, { {7}, {9}, {2} });
  std::vector<double> expectedResult3 = { 7, 9, 2 };
  assert(mat3.toVector() == expectedResult3);
  
  for(std::size_t i =  0; i < R; ++i)
    for(std::size_t j = 0; j < C; ++j)
        assert(mat3.getValue(i, j) == expectedResult3[i * C + j]);
}

int main()
{
  TEST_001_toVector();
}
