#include "Matrix.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>

 Matrix::Matrix(int row,int col)//constructor that allocates memory for the matrix
    {
        data = new int*[row];
        for(int i = 0; i < row; ++i)
            {
                data[i] = new int[col];
            }
        setrow(row);
        setcol(col);

    }
Matrix::Matrix(const Matrix &m)//copy constructor
    {

        row=m.row;
        col=m.col;
        data=new int*[row];
        for(int i=0; i<row;i++)
        {
            data[i]=new int[col];
        }
        for(int i=0; i<row; i++)
        {
            for(int j=0;j<col;j++)
            {
                data[i][j]=m.data[i][j];
            }
        }
    }
Matrix::~Matrix()//destructor that deallocates memory for the matrix
    {
        for(int i=0;i<row;i++)
            delete []data[i];
        delete []data;
    }
void Matrix::setrow(int x)
    {
        row=x;
    }
void Matrix::setcol(int x)
    {
        col=x;
    }
void Matrix::setdata(int**x)
{
    for(int i=0;i<row;i++)
        delete []data[i];
    delete []data;
    data = new int*[row];
    for(int i = 0; i < row; ++i)
        {
            data[i] = new int[col];
        }
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    data[i][j]=x[i][j];
                }
        }

}
int Matrix::getrow()
{
    return row;
}
int Matrix::getcol()
{
    return col;
}
int** Matrix::getdata()
{

    return data;
}
void Matrix::setdatafirsttime(bool deleteDataBeforeSetting)//sets data manually
{
    if(deleteDataBeforeSetting)
    {
        for(int i=0;i<row;i++)
        delete []data[i];
    delete []data;
    data = new int*[row];
    for(int i = 0; i < row; ++i)
        {
            data[i] = new int[col];
        }
    }
   for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>data[i][j];
            }
        }
}
Matrix Matrix:: operator+ (const Matrix& mat1)
{
    Matrix temp=mat1;
    int** result=temp.getdata();
    if(row==temp.getrow()&&col==temp.getcol())
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                result[i][j]+=data[i][j];
            }
        }
         Matrix Myresult(row,col);
         Myresult.setdata(result);
         return Myresult;
    }
    else{
        cout<<"cant add"<<endl;
        return *this;}

}
Matrix Matrix:: operator- (const Matrix& mat1)
{
    Matrix temp=mat1;
    int** result=temp.getdata();
    if(row==temp.getrow()&&col==temp.getcol())
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<row;j++)
            {
                result[i][j]=data[i][j]-result[i][j];
            }
        }
         Matrix Myresult(row,col);
         Myresult.setdata(result);
         return Myresult;
    }
    else
    {
         cout<<"cant subtract"<<endl;
         return *this;}
}
Matrix Matrix:: operator* (const Matrix& mat1)
{
    Matrix temp=mat1;
    int** result;
    result = new int*[row];
    for(int i = 0; i < row; ++i)
        {
            result[i] = new int[temp.getcol()];
        }
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<temp.getcol();j++)
                {
                    result[i][j]=0;
                }
        }

    int** tempData=temp.getdata();
    if(col==temp.getrow())
    {
        for(int i=0;i<row;i++){
            for(int j=0;j<temp.getcol();j++){
                for(int z=0;z<col;z++)
                {
                    result[i][j]+=data[i][z]*tempData[z][j];
                }
    }
    }
    Matrix Myresult(row,temp.getcol());
    Myresult.setdata(result);
    for(int i=0;i<row;i++)
        delete []result[i];
    delete []result;
    return Myresult;

    }
    else
    {
        cout<<"cant multiply"<<endl;
        return *this;
    }

}
Matrix Matrix::addScalar(int scalar)//add a scalar and returns same matrix after operation
{
     for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    data[i][j]+=scalar;
                }
        }
    return *this;
}
Matrix Matrix::subtractScalar(int scalar)//subtract a scalar and returns same matrix after operation
{
     for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    data[i][j]-=scalar;
                }
        }
    return *this;
}
Matrix Matrix::multiplyScalar(int scalar)//multiply a scalar and returns same matrix after operation
{
     for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    data[i][j]*=scalar;
                }
        }
    return *this;
}
Matrix Matrix::transpose()// Return new matrix with the transpose
{

     int** result;
    result = new int*[col];
    for(int i = 0; i < col; ++i)
        {
            result[i] = new int[row];
        }

    for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
                {
                    result[i][j]=data[j][i];
                }
        }
    Matrix Myresult(col,row);
    Myresult.setdata(result);
    return Myresult;
}
bool Matrix::isSquare()//true if row==col
{
    if(row==col)
        return true;
    else
        return false;

}
bool Matrix::isIdentity()//true if identity
{
    if(isSquare()==false)
    {
        return false;
    }

    for(int i=0;i<row;i++)
    {
        if(data[i][i]!=1)
        {
            return false;
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i!=j)
            {
                if(data[i][j]!=0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

