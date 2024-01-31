#include <iostream>
#include <iomanip>      // std::setw()

using namespace std; 

const int M = 2;    // number of rows in matrix
const int N = 3;    // number of columns in matrix

const int WIDTH = 4;  // width of matrix element in output (for setw())

// function that adds two matrices
void add_matrices(double A[M][N], double B[M][N], double C[M][N])
{
    // add matrices
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }

    }
}


int main()
{
    
    double A[M][N] = { {1,2,3}, 
                       {4,5,6}
    };

    double B[M][N] = {  {10,10,10}, 
                        {20,20,20}
    };

    double C[M][N];

    // add matrices
    add_matrices(A, B, C);

    // print matrices
    cout << "Matrix A:" << endl;
    print_matrix(A);

    cout << "Matrix B:" << endl;
    print_matrix(B);

    cout << "Matrix C = A + B:" << endl;
    print_matrix(C);
     
    system("pause");
    return 0;
}
