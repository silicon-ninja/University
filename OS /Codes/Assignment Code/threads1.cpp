
#include <iostream>
#include <thread>
#include <time.h>
using namespace std;
// void sequentialapproach(int m, int n)
// {
//     int matrix1[m][n];
//     int matrix2[m][n];
//     int matrixadd[m][n]; // declaration of matrix
//     int i, j, k;
//     srand(1); // seed value

//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             matrix1[i][j] = rand() % 5;
//             matrix2[i][j] = rand() % 5;
//         }

//     }
//     cout << "This is Matrix 1" << endl;
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             printf("%3d", matrix1[i][j]);
//         }
//         cout << endl;
//     }

//     cout << "This is Matrix 2" << endl;
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {

//             printf("%3d", matrix2[i][j]);
//         }
//         cout << endl;
//     }
//     cout << "This is Addition of Matrix 1 and Matrix 2" << endl;
//     for (i = 0; i < m; i++)
//     {
//         for (j = 0; j < n; j++)
//         {
//             matrixadd[i][j] = matrix1[i][j] + matrix2[i][j];
//             printf("%4d", matrixadd[i][j]);
//         }
//         cout << endl;
//     }
// }

int main()
{
    int m = 500, n = 500;
    int matrix1[m][n];
    int matrix2[m][n];
    int matrixadd[m][n]; // declaration of matrix
    int i, j, k;
    srand(1); // seed value

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 5;
            matrix2[i][j] = rand() % 5;
        }
    }
    cout << "This is Matrix 1" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%3d", matrix1[i][j]);
        }
        cout << endl;
    }

    cout << "This is Matrix 2" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {

            printf("%3d", matrix2[i][j]);
        }
        cout << endl;
    }
    cout << "This is Addition of Matrix 1 and Matrix 2" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrixadd[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%4d", matrixadd[i][j]);
        }
        cout << endl;
    }
    return 0;
}