#include <iostream>
using namespace std;

// code written by https://github.com/rafu01
int main()
{
    int row = 3, column = 2;                            // defining the row and column size
    int matrix[row][column] = {{4, 5}, {6, 7}, {8, 9}}; // creating the matrix using 2d array
    int t_matrix[column][row];
    int r = 0, c = 0;                // counters for transpose matrix
    for (int i = 0; i < column; ++i) // for transpose of a matrix column becomes row and vice verse
    {
        c = 0;
        for (int j = 0; j < row; ++j)
        {
            t_matrix[r][c] = matrix[j][i]; // adding the elements to our transpose matrix
            c++;
        }
        r++;
    }
    for (int i = 0; i < column; ++i) // for printing the transpose matrix
    {
        for (int j = 0; j < row; j++)
            cout << t_matrix[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
// example:
/*  transpose of  4 5        4 6 8
                  6 7   -->  5 7 9
                  8 9 
    
*/