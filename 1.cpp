#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int max = 10;
    double A[10][10];
    double x[10];
    double y[10];
    cout << "Si" << endl;
    for(int i = 0; i < max; i++)
    {
      y[i] = 0;
    }

    for(int i = 0; i < max; i++)
    {
      x[i] = rand();
      cout << x[i] << "-";
    }
    cout << endl << endl;


    for(int i= 0; i < max; i++)
    {
      for(int j = 0; j < max; j++)
        {
          A[i][j] = rand();
          cout << A[i][j] << "-";
        }
        cout << endl;
    }
  
  

    for(int j = 0; j < max; j++)
    {
      for(int i = 0; i < max; i++)
        {
          y[i] += A[i][j] * x[j];
        }
    }
  
    for(int i = 0; i < max; i++)
    {
      y[i] = 0;
    }

   for(int i= 0; i < max; i++)
    {
      for(int j = 0; j < max; j++)
        {
          y[i] += A[i][j] * x[j];
        }
    }
  
}
