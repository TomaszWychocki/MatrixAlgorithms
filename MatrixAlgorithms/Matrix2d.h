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
    MATRIX_MUST_BE_SQUARE
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
    void operator*=(double number);

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
    std::vector<std::vector<double>> numbersArray;

    /*
     * METHODS
     */
};