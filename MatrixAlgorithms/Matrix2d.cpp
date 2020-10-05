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

Matrix2d::Matrix2d(const Matrix2d& matrix)
    : rows(matrix.numbersArray.size())
    , cols(matrix.numbersArray[0].size())
{
    for (const auto& row : matrix.numbersArray)
    {
        this->numbersArray.push_back(row);
    }
}

Matrix2d::Matrix2d(std::size_t rows, std::size_t cols, FillType fillType)
    : rows(rows)
    , cols(cols)
{
    if (fillType == FillType::IDENTITY && cols != rows)
    {
        throw Errors::MATRIX_MUST_BE_SQUARE;
    }

    switch (fillType)
    {
    case FillType::IDENTITY:
        for (std::size_t row = 0; row < rows; row++)
        {
            std::vector<double> vec(cols, 0.0);
            this->numbersArray.push_back(vec);

            for (std::size_t col = 0; col < cols; col++)
            {
                if (row == col)
                {
                    this->numbersArray[row][col] = 1.0;
                }
            }
        }
        break;

    case FillType::ZEROS:
        for (std::size_t row = 0; row < rows; row++)
        {
            std::vector<double> vec(cols, 0.0);
            this->numbersArray.push_back(vec);
        }
        break;

    case FillType::ONES:
        for (std::size_t row = 0; row < rows; row++)
        {
            std::vector<double> vec(cols, 1.0);
            this->numbersArray.push_back(vec);
        }
        break;
    }
}

bool Matrix2d::operator==(const Matrix2d& matrix) const
{
    return Matrix2d::areEqual(*this, matrix);
}

bool Matrix2d::operator!=(const Matrix2d& matrix) const
{
    return !Matrix2d::areEqual(*this, matrix);
}

Matrix2d Matrix2d::operator*(double number) const
{
    Matrix2d mat(*this);
    Matrix2d::multiply(mat, number);

    return mat;
}

Matrix2d& Matrix2d::operator*=(double number)
{
    Matrix2d::multiply(*this, number);
    return *this;
}

Matrix2d Matrix2d::operator-(const Matrix2d& matrix) const
{
    Matrix2d mat(*this);
    Matrix2d::subtract(mat, matrix);

    return mat;
}

Matrix2d& Matrix2d::operator-=(const Matrix2d& matrix)
{
    Matrix2d::subtract(*this, matrix);
    return *this;
}

Matrix2d Matrix2d::operator*(const Matrix2d& matrix)
{
    Matrix2d result(this->rows, matrix.cols, FillType::ZEROS);
    Matrix2d::multiply(result, *this, matrix);

    return result;
}

void  Matrix2d::operator*=(const Matrix2d& matrix)
{
    Matrix2d result(this->rows, matrix.cols, FillType::ZEROS);
    Matrix2d::multiply(result, *this, matrix);

    //modifying the first operand
    for (std::size_t i = 0; i < this->rows; i++)
    {
        this->numbersArray[i].clear();
    }

    this->numbersArray.clear();

    this->rows = result.rows;
    this->cols = result.cols;
    this->numbersArray = result.numbersArray;
}

double Matrix2d::getValue(std::size_t row, std::size_t col) const
{
    return this->numbersArray[row][col];
}

std::size_t Matrix2d::getRows() const
{
    return this->rows;
}

std::size_t Matrix2d::getCols() const
{
    return this->cols;
}

std::vector<double> Matrix2d::toVector() const
{
    std::vector<double> vec;

    for (const auto& row : this->numbersArray)
    {
        vec.insert(vec.end(), row.begin(), row.end());
    }

    return vec;
}

bool Matrix2d::areEqual(const Matrix2d& matrix1, const Matrix2d& matrix2)
{
    if (matrix1.cols != matrix2.getCols() || matrix1.rows != matrix2.getRows())
    {
        return false;
    }

    for (std::size_t row = 0; row < matrix1.rows; row++)
    {
        if (matrix1.numbersArray[row] != matrix2.numbersArray[row])
        {
            return false;
        }
    }

    return true;
}

void Matrix2d::multiply(Matrix2d& destMatrix, double number)
{
    for (std::size_t row = 0; row < destMatrix.rows; row++)
    {
        for (std::size_t col = 0; col < destMatrix.cols; col++)
        {
            destMatrix.numbersArray[row][col] *= number;
        }
    }
}

void Matrix2d::multiply(Matrix2d& destMatrix, const Matrix2d& matrix1, const Matrix2d& matrix2)
{
    //check for erranious input and throw error
    if (matrix1.cols != matrix2.rows)
    {
        //throw an error
        throw Errors::DIMENSIONAL_ERROR;
    }

    //now implement matrix multiplaication algorithm requires o(n^3) complexity
    for (std::size_t i = 0; i < matrix1.rows; i++)
    {
        for (std::size_t j = 0; j < matrix2.cols; j++)
        {
            double value = 0;

            for (std::size_t k = 0; k < matrix1.cols; k++)
            {
                value += matrix1.numbersArray[i][k] * matrix2.numbersArray[k][j];
            }

            destMatrix.numbersArray[i][j] = value;
        }
    }
}

void Matrix2d::subtract(Matrix2d& destMatrix, const Matrix2d& matrix)
{
    if (destMatrix.cols != matrix.getCols() || destMatrix.rows != matrix.getRows())
    {
        throw Errors::DIM_MUST_BE_EQUAL;
    }

    for (std::size_t row = 0; row < destMatrix.rows; row++)
    {
        for (std::size_t col = 0; col < destMatrix.cols; col++)
        {
            destMatrix.numbersArray[row][col] -= matrix.numbersArray[row][col];
        }
    }
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