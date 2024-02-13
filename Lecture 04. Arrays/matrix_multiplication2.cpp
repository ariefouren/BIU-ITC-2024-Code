#include <iostream>
#include <iomanip>      // std::setw()
using namespace std; 

const int MAX_ROWS = 10;    // maximum number of rows
const int MAX_COLS = 10;    // maximum number of columns

const int WIDTH = 5;  // width of matrix element in output (for setw())

// 
void print_matrix(double A[MAX_ROWS][MAX_COLS], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(WIDTH) << A[i][j];  
        }
        cout << endl;
    }
}

void matrix_mult(   double A[MAX_ROWS][MAX_COLS],
                    double B[MAX_ROWS][MAX_COLS],
                    double C[MAX_ROWS][MAX_COLS],
                    int m,   // num of rows of matrix A
                    int n,     // num columns of matrix A, rows of B
                    int p      // num of columns of B  
                    )
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < p; j++)
        {
            C[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int m = 4;  // rows in A
    int n = 2;  // columns in A
    int p = 3;  // columns in B
    double A[MAX_COLS][MAX_ROWS] = {    {1, 2}, 
                                        {3, 4}, 
                                        {5, 6},
                                        {7, 8}   };

    double B[MAX_COLS][MAX_ROWS] = {    {1,2,3}, 
                                        {5,6,7}
    };

    double C[MAX_COLS][MAX_ROWS];
    
    // print matrices
    cout << "Matrix A:" << endl;
    print_matrix(A, m, n); 

    cout << "Matrix B:" << endl;
    print_matrix(B, n, p);

    cout << "Matrix C = A * B:" << endl;
    matrix_mult(A, B, C, m, n, p  );
    print_matrix(C, m, p);

    return 0;
}