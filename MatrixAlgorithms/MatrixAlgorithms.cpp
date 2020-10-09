#include <iostream>
#include "Matrix2d.h"
#include <assert.h>

void TEST_001_toVector();
void TEST_002_getCols();
void TEST_003_getRows();
void TEST_004_equality();
void TEST_005_scalarMultiplication();
void TEST_006_matrix_ones();
void TEST_007_matrix_zeros();
void TEST_008_matrix_identity();
void TEST_009_matrix_mult();
void TEST_010_matrix_mult_assign();
void TEST_011_matrix_mult();
void TEST_012_matrix_mult_assign();
void TEST_013_matrix_mult();
void TEST_014_matrix_mult_assign();
void TEST_015_matrix_mult();
void TEST_016_subtraction();
void TEST_017_subtraction_2();
void TEST_018_operations_chain();
void TEST_019_transpose();
void TEST_020_matrix_concat();
void TEST_021_determinant();
void TEST_022_getValue();

int main()
{
    TEST_001_toVector();
    TEST_002_getCols();
    TEST_003_getRows();
    TEST_004_equality();
    TEST_005_scalarMultiplication();
    TEST_006_matrix_ones();
    TEST_007_matrix_zeros();
    TEST_008_matrix_identity();
    TEST_009_matrix_mult();
    TEST_010_matrix_mult_assign();
    TEST_011_matrix_mult();
    TEST_012_matrix_mult_assign();
    TEST_013_matrix_mult();
    TEST_014_matrix_mult_assign();
    TEST_015_matrix_mult();
    TEST_016_subtraction();
    TEST_017_subtraction_2();
    TEST_018_operations_chain();
    TEST_019_transpose();
    TEST_020_matrix_concat();
    TEST_021_determinant();
    TEST_022_getValue();
}

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

void TEST_004_equality()
{
    Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat2 = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat3 = { {7}, {9}, {2} };

    assert(mat == mat2);
    assert(mat != mat3);
}

void TEST_005_scalarMultiplication()
{
    Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d expectedResult = { {12, 18, 24} , {30, 36, 42} };
    Matrix2d result = mat * 6;

    assert(expectedResult == result);

    Matrix2d mat1 = { {2, 3, 4} };
    Matrix2d expectedResult1 = { {10, 15, 20} };
    Matrix2d result1 = mat1 * 5;

    assert(expectedResult1 == result1);

    Matrix2d mat2 = { {2}, {5} };
    Matrix2d expectedResult2 = { {4}, {10} };
    Matrix2d result2 = mat2 * 2;

    assert(expectedResult2 == result2);

    Matrix2d mat3 = { {2, 3, 4} };
    Matrix2d expectedResult3 = { {10, 15, 20} };
    mat3 *= 5;

    assert(expectedResult3 == mat3);

    Matrix2d mat4 = { {2}, {5} };
    Matrix2d expectedResult4 = { {4}, {10} };
    mat4 *= 2;

    assert(expectedResult4 == mat4);
}

void TEST_006_matrix_ones()
{
    Matrix2d mat(4, 5, FillType::ONES);
    Matrix2d expectedResult = { {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1} };
    assert(mat == expectedResult);

    Matrix2d mat2(2, 2, FillType::ONES);
    Matrix2d expectedResult2 = { {1, 1}, {1, 1} };
    assert(mat2 == expectedResult2);

    Matrix2d mat3(1, 1, FillType::ONES);
    Matrix2d expectedResult3 = { {1} };
    assert(mat3 == expectedResult3);
}

void TEST_007_matrix_zeros()
{
    Matrix2d mat(4, 5, FillType::ZEROS);
    Matrix2d expectedResult = { {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0} };
    assert(mat == expectedResult);

    Matrix2d mat2(2, 2, FillType::ZEROS);
    Matrix2d expectedResult2 = { {0, 0}, {0, 0} };
    assert(mat2 == expectedResult2);

    Matrix2d mat3(1, 1, FillType::ZEROS);
    Matrix2d expectedResult3 = { {0} };
    assert(mat3 == expectedResult3);
}

void TEST_008_matrix_identity()
{
    Matrix2d mat(4, 4, FillType::IDENTITY);
    Matrix2d expectedResult = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
    assert(mat == expectedResult);

    Matrix2d mat2(2, 2, FillType::IDENTITY);
    Matrix2d expectedResult2 = { {1, 0}, {0, 1} };
    assert(mat2 == expectedResult2);

    Matrix2d mat3(1, 1, FillType::IDENTITY);
    Matrix2d expectedResult3 = { {1} };
    assert(mat3 == expectedResult3);

    bool isException = false;
    try
    {
        Matrix2d mat4(4, 2, FillType::IDENTITY);
    }
    catch (Errors err)
    {
        if (err == Errors::MATRIX_MUST_BE_SQUARE)
        {
            isException = true;
        }
    }
    assert(isException);
}

void TEST_009_matrix_mult()
{
    Matrix2d mat1(3, 2, FillType::ONES);
    Matrix2d mat2(2, 3, FillType::ONES);
    Matrix2d expectedResult = { {2,2,2},{2,2,2},{2,2,2} };
    Matrix2d result = mat1 * mat2;
    assert(result == expectedResult);
}

void TEST_010_matrix_mult_assign()
{
    Matrix2d mat1(3, 2, FillType::ONES);
    Matrix2d mat2(2, 3, FillType::ONES);
    Matrix2d expectedResult = { {2,2,2},{2,2,2},{2,2,2} };
    mat1 *= mat2;
    assert(mat1 == expectedResult);
}

void TEST_011_matrix_mult()
{
    Matrix2d mat1(3, 3, FillType::ONES);
    Matrix2d mat2(2, 3, FillType::ONES);
    Matrix2d expectedResult = { {2,2,2},{2,2,2},{2,2,2} };

    bool isException = false;
    try
    {
        Matrix2d result = mat1 * mat2;
    }
    catch (Errors err)
    {
        if (err == Errors::DIMENSIONAL_ERROR)
        {
            isException = true;
        }

    }
    assert(isException);
}

void TEST_012_matrix_mult_assign()
{
    Matrix2d mat1(3, 3, FillType::ONES);
    Matrix2d mat2(2, 3, FillType::ONES);
    Matrix2d expectedResult = { {2,2,2},{2,2,2},{2,2,2} };

    bool isException = false;
    try
    {
        mat1 *= mat2;
    }
    catch (Errors err)
    {
        if (err == Errors::DIMENSIONAL_ERROR)
        {
            isException = true;
        }

    }
    assert(isException);
}

void TEST_013_matrix_mult()
{
    Matrix2d mat1 = { {1,2,3},{4,5,6} };
    Matrix2d mat2 = { {10,11},{20,21},{30,31} };
    Matrix2d expectedResult = { {140,146},{320,335} };
    Matrix2d result = mat1 * mat2;
    assert(result == expectedResult);
}

void TEST_014_matrix_mult_assign()
{
    Matrix2d mat1 = { {1,8,7,3},{5,4,3,1} };
    Matrix2d mat2 = { {8},{7},{4},{2} };
    Matrix2d expectedResult = { {98},{82} };
    mat1 *= mat2;
    assert(mat1 == expectedResult);
}

void TEST_015_matrix_mult()
{
    Matrix2d mat1 = { {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4} };
    Matrix2d mat2 = { {8},{7},{4},{2} };
    Matrix2d expectedResult = { {98},{82} };
    mat1 *= mat2;
    bool isException = false;
    try
    {
        Matrix2d result = mat1 * mat2;
    }
    catch (Errors err)
    {
        if (err == Errors::DIMENSIONAL_ERROR)
        {
            isException = true;
        }

    }
    assert(isException);
}

void TEST_016_subtraction()
{
    Matrix2d mat1 = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat2 = { {5, 2, 1} , {5, 8, 10} };
    Matrix2d mat1_copy = { mat1 };
    Matrix2d mat2_copy = { mat2 };
    Matrix2d expectedResult1 = { {-3, 1, 3} , {0, -2, -3} };
    Matrix2d expectedResult2 = { {3, -1, -3} , {0, 2, 3} };
    Matrix2d result1 = mat1 - mat2;
    Matrix2d result2 = mat2 - mat1;

    assert(mat1 == mat1_copy);
    assert(mat2 == mat2_copy);
    assert(result1 == expectedResult1);
    assert(result2 == expectedResult2);

    bool isException = false;
    try
    {
        Matrix2d mat3(3, 3, FillType::ONES);
        Matrix2d mat4(4, 3, FillType::ONES);
        Matrix2d result3 = mat3 - mat4;
    }
    catch (Errors err)
    {
        if (err == Errors::DIM_MUST_BE_EQUAL)
        {
            isException = true;
        }
    }
    assert(isException);
}

void TEST_017_subtraction_2()
{
    Matrix2d mat1 = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat2 = { {5, 2, 1} , {5, 8, 10} };
    Matrix2d mat2_copy = { mat2 };
    Matrix2d expectedResult1 = { {-3, 1, 3} , {0, -2, -3} };
    mat1 -= mat2;

    assert(mat1 == expectedResult1);
    assert(mat2 == mat2_copy);

    Matrix2d mat3 = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat4 = { {5, 2, 1} , {5, 8, 10} };
    Matrix2d mat3_copy = { mat3 };
    Matrix2d expectedResult2 = { {3, -1, -3} , {0, 2, 3} };
    mat4 -= mat3;

    assert(mat4 == expectedResult2);
    assert(mat3 == mat3_copy);

    bool isException = false;
    try
    {
        Matrix2d mat5(3, 3, FillType::ONES);
        Matrix2d mat6(4, 3, FillType::ONES);
        mat5 -= mat6;
    }
    catch (Errors err)
    {
        if (err == Errors::DIM_MUST_BE_EQUAL)
        {
            isException = true;
        }
    }
    assert(isException);
}

void TEST_018_operations_chain()
{
    Matrix2d mat1 = { {2, 3, 4} , {5, 6, 7} };
    Matrix2d mat2 = { {5, 2, 1} , {5, 8, 10} };
    Matrix2d mat3 = { {10, 11} , {20, 21} , {30, 31} };
    Matrix2d expectedResult1 = { {80, 81} , {-130, -135} };

    Matrix2d result = (mat1 - mat2) * mat3;
    assert(result == expectedResult1);
}

void TEST_019_transpose()
{
    Matrix2d mat1 = {{2, 3, 4, 8} , {5, 6, 7, 9}};
    Matrix2d expected1 = { {2, 5} , {3, 6} , {4, 7} , {8, 9} };
    assert(mat1.transpose() == expected1);

    Matrix2d mat2 = {{7} , {9} , {2}};
    Matrix2d expected2 = { {7, 9, 2} };
    assert(mat2.transpose() == expected2);
}

void TEST_020_matrix_concat()
{
    Matrix2d mat1 = { {2, 3} , {5, 6} };
    Matrix2d mat2 = { {6, 7} , {4, 1} , {7, 9} };
    Matrix2d mat3 = { {5, 1, 4} , {6, 8, 1} };

    Matrix2d result1 = { mat1 };
    result1.concat(mat2, ConcatSide::UP);
    Matrix2d expected1 = { {6, 7} , {4, 1} , {7, 9} , {2, 3} , {5, 6} };
    assert(result1 == expected1);

    Matrix2d result2 = { mat1 };
    result2.concat(mat2, ConcatSide::DOWN);
    Matrix2d expected2 = { {2, 3} , {5, 6} , {6, 7} , {4, 1} , {7, 9} };
    assert(result2 == expected2);

    Matrix2d result3 = { mat1 };
    result3.concat(mat3, ConcatSide::LEFT);
    Matrix2d expected3 = { {5, 1, 4, 2, 3} , {6, 8, 1, 5, 6} };
    assert(result3 == expected3);

    Matrix2d result4 = { mat1 };
    result4.concat(mat3, ConcatSide::RIGHT);
    Matrix2d expected4 = { {2, 3, 5, 1, 4} , {5, 6, 6, 8, 1} };
    assert(result4 == expected4);

    bool isException = false;
    try
    {
        Matrix2d result5 = { mat1 };
        result5.concat(mat3, ConcatSide::DOWN);
    }
    catch (Errors err)
    {
        if (err == Errors::DIMENSIONAL_ERROR)
        {
            isException = true;
        }
    }
    assert(isException);

    isException = false;
    try
    {
        Matrix2d result5 = { mat1 };
        result5.concat(mat2, ConcatSide::LEFT);
    }
    catch (Errors err)
    {
        if (err == Errors::DIMENSIONAL_ERROR)
        {
            isException = true;
        }
    }
    assert(isException);
}

void TEST_021_determinant()
{
    Matrix2d mat = { {2, 3, 4, 5} , {5, 6, 7, 2} , {6, 1, 7, 3} , {6, 3, 8, 1} };
    assert(static_cast<int>(mat.getDeterminant()) == 132);

    Matrix2d mat2 = { { 1,  3,  0, -1} ,  { 0,  2,  1,  3} ,  { 3,  1,  2,  1} ,  {-1,  2,  0,  3} };
    assert(static_cast<int>(mat2.getDeterminant()) == 14);

    bool isException = false;
    try
    {
        Matrix2d mat3(4, 3, FillType::ONES);
        mat3.getDeterminant();
    }
    catch (Errors err)
    {
        if (err == Errors::MATRIX_MUST_BE_SQUARE)
        {
            isException = true;
        }
    }
    assert(isException);
}

void TEST_022_getValue()
{
    std::size_t R = 2, C = 3;
    Matrix2d mat = { {2, 3, 4} , {5, 6, 7} };
    std::vector<int> expectedResult = { 2, 3, 4, 5, 6, 7 };

    for(std::size_t i =  0; i < R; ++i)
    {
        for(std::size_t j = 0; j < C; ++j)
        {
            assert(static_cast<int>(mat.getValue(i, j)) == expectedResult[i * C + j]);
        }
    }

    R = 1, C = 3;
    Matrix2d mat2 = { {5, 6, 7} };
    std::vector<int> expectedResult2 = { 5, 6, 7 };

    for(std::size_t i =  0; i < R; ++i)
    {
        for(std::size_t j = 0; j < C; ++j)
        {
            assert(static_cast<int>(mat2.getValue(i, j)) == expectedResult2[i * C + j]);
        }
    }

    R = 3, C = 1;
    Matrix2d mat3 = { {7}, {9}, {2} };
    std::vector<int> expectedResult3 = { 7, 9, 2 };

    for(std::size_t i =  0; i < R; ++i)
    {
        for(std::size_t j = 0; j < C; ++j)
        {
            assert(static_cast<int>(mat3.getValue(i, j)) == expectedResult3[i * C + j]);
        }
    }
}
