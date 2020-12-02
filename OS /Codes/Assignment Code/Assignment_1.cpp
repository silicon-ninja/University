#include <iostream>
#include <time.h>
#include <thread>
using namespace std;
#define rows 10
#define columns 10
int matrixt1[rows][columns];
int matrixt2[rows][columns];
int matrixtadd[rows][columns];

void sequentialapproach(int m, int n)
{
  int matrix1[m][n];
  int matrix2[m][n];
  int matrixadd[m][n]; // declaration of matrix
  int i, j, k;
  srand(1); // seed value
  cout << "This is Matrix 1" << endl;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      matrix1[i][j] = rand() % 5;
      printf("%3d", matrix1[i][j]);
    }
    cout << endl;
  }
  cout << "This is Matrix 2" << endl;
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      matrix2[i][j] = rand() % 5;
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
}

void *addition(int rownumber)
{
  for (int i = 0; i < columns; i++)
  {
    matrixtadd[rownumber][i] = matrixt1[rownumber][i] + matrixt2[rownumber][i];
  }
  
}

int main()
{
  thread threads[100];
  int choice, i, j;
  cout << "K Srikanth 17ETCS002124" << endl;
  cout << "Select the Approach " << endl;
  cout << "Press 1 for Sequential Approach" << endl;
  cout << "Press 2 for Thread Approach " << endl;
  cin >> choice;
  
  switch (choice)
  {
  case 1:
    sequentialapproach(10, 10);
    break;
  case 2:
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
      printf("Creating a thread in main %d \n", i+1);
      for (int i = 0; i < 10; i++)
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
    break;
    default: cout << "Invalid Input"<<endl;
      break;
    }
  }