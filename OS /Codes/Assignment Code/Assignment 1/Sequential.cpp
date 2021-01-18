#include <iostream>
#include <thread>
#include <time.h>
using namespace std;
// 17ETCS002124 K Srikanth
int main()
{
    cout << "**************** K Srikanth 17ETCS002124 ****************** " <<endl;
    cout <<endl;
    int m = 100, n = 100;
    int matrix1[m][n];
    int matrix2[m][n];
    int matrixadd[m][n]; 
    int i, j, k;
    srand(1); 

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


