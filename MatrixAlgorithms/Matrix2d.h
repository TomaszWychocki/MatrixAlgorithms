#pragma once
#include <vector>
#include <iostream>

enum class FillType
{
    IDENTITY,
    ZEROS,
    ONES
};

enum class Errors
{
    MATRIX_MUST_BE_SQUARE,
    DIM_MUST_BE_EQUAL,
    DIMENSIONAL_ERROR
};

enum class ConcatSide
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Matrix2d
{
public:
    /*
     * CONSTRUCTOR
     */
    Matrix2d();
    Matrix2d(std::initializer_list<std::initializer_list<double>> lst);
    Matrix2d(const Matrix2d& matrix);
    Matrix2d(std::size_t row, std::size_t col, FillType fillType);

    /*
     * OPERATOR
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix2d& matrix);
    bool operator==(const Matrix2d& matrix) const;
    bool operator!=(const Matrix2d& matrix) const;
    Matrix2d operator*(double number) const;
    Matrix2d& operator*=(double number);
    Matrix2d operator-(const Matrix2d& matrix) const;
    Matrix2d& operator-=(const Matrix2d& matrix);
    Matrix2d operator*(const Matrix2d& matrix);
    void operator*=(const Matrix2d& matrix);

    /*
     * METHODS
     */
    double getValue(std::size_t row, std::size_t col) const;
    std::size_t getRows() const;
    std::size_t getCols() const;
    std::vector<double> toVector() const;
    Matrix2d& transpose();
    Matrix2d& concat(const Matrix2d& matrix, ConcatSide side);

private:
    /*
     * FIELDS
     */
    std::size_t rows;
    std::size_t cols;
    std::vector<std::vector<double>> numbersArray;

    /*
     * METHODS
     */
    static bool areEqual(const Matrix2d& matrix1, const Matrix2d& matrix2);
    static void multiply(Matrix2d& destMatrix, double number);
    static void multiply(Matrix2d& destMatrix, const Matrix2d& matrix1, const Matrix2d& matrix2);
    static void subtract(Matrix2d& destMatrix, const Matrix2d& matrix);
};