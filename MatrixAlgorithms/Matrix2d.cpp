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
    if (this->cols != matrix.getCols() || this->rows != matrix.getRows())
    {
        return false;
    }

    for (std::size_t row = 0; row < this->rows; row++)
    {
        if (matrix.numbersArray[row] != this->numbersArray[row])
        {
            return false;
        }
    }

    return true;
}

bool Matrix2d::operator!=(const Matrix2d& matrix) const
{
    if (this->cols != matrix.getCols() || this->rows != matrix.getRows())
    {
        return true;
    }

    for (std::size_t row = 0; row < this->rows; row++)
    {
        if (matrix.numbersArray[row] != this->numbersArray[row])
        {
            return true;
        }
    }

    return false;
}

Matrix2d Matrix2d::operator*(double number) const
{
    Matrix2d mat(*this);

    for (std::size_t row = 0; row < mat.rows; row++)
    {
        for (std::size_t col = 0; col < mat.cols; col++)
        {
            mat.numbersArray[row][col] *= number;
        }
    }

    return mat;
}

void Matrix2d::operator*=(double number)
{
    for (std::size_t row = 0; row < this->rows; row++)
    {
        for (std::size_t col = 0; col < this->cols; col++)
        {
            this->numbersArray[row][col] *= number;
        }
    }
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