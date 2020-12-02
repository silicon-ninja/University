#include <iostream>
#include <thread>
#include <time.h>
#define rows 500
#define columns 500
#define threads_count 500
int matrixt1[rows][columns];
int matrixt2[rows][columns];
int matrixtadd[rows][columns];
using namespace std;

void *addition(int rownumber)
{
    for (int i = 0; i < columns; i++)
    {
        matrixtadd[rownumber][i] = matrixt1[rownumber][i] + matrixt2[rownumber][i];
    }
}

int main()
{
    thread threads[threads_count];
    int choice, i, j;
    srand(1);
    for (int a = 0; a < rows; a++)
    {
        for (int b = 0; b < columns; b++)
        {
            matrixt1[a][b] = rand() % 5;
            matrixt2[a][b] = rand() % 5;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        printf("Creating a thread in main %d \n", i + 1);
        for (int i = 0; i < rows; i++)
        {
            threads[i] = thread{&addition, i};
        }
        for (int i = 0; i < rows; i++)
        {
            threads[i].join();
        }
    }

    cout << "This is Matrix 1" << endl;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%3d", matrixt1[i][j]);
        }
        cout
            << endl;
    }
    cout
        << "This is Matrix 2" << endl;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%3d", matrixt2[i][j]);
        }
        cout << endl;
    }
    cout
        << "This is Addition of Matrix 1 and Matrix 2" << endl;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            matrixtadd[i][j] = matrixt1[i][j] + matrixt2[i][j];
            printf("%4d", matrixtadd[i][j]);
        }
        cout << endl;
    }
    return 0;
}
