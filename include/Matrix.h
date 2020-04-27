#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;
class Matrix
{
private:
    int row,col;
    int** data;// Pointer to 2D array
public:
    Matrix(int row,int col); //allocates memory for the matrix
    Matrix(const Matrix &m);
    void setrow(int x);
    void setcol(int x);
    void setdatafirsttime(bool deleteDataBeforeSetting);
    void setdata(int** x);
    int** getdata();
    int  getrow();
    int  getcol();
    Matrix operator+ (const Matrix& anotherDec); //overloaded +
    Matrix operator- (const Matrix& anotherDec); //overloaded -
    Matrix operator* (const Matrix& mat1);
    Matrix addScalar(int scalar); // Add a scalar
    Matrix subtractScalar(int scalar); // Subtract a scalar
    Matrix multiplyScalar(int scalar); // Multiply by a scalar
    Matrix transpose(); // Return new matrix with the transpose
    bool isSquare(); // True if square matrix
    bool isIdentity(); // True if square and identity friend
    friend ostream& operator<<(ostream& os, const Matrix& M1);
    ~Matrix();//de-allocates memory
};

#endif // MATRIX_H
