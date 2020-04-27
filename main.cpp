#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include "Matrix.h"
#include"MatrixCalculator.h"
int main()
{
    MatrixCalculator calc;
    calc.MainMenu();
    return 0;
}
ostream& operator<<(ostream& os, const Matrix& mat)
{
     for(int i=0;i<mat.row;i++)
    {
        for(int j=0;j<mat.col;j++)
        {
            cout<<mat.data[i][j]<<" ";
        }
    cout<<endl;
    }
}
