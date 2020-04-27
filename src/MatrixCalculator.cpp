#include "MatrixCalculator.h"
void MatrixCalculator::MainMenu()
{
    cout<<"please enter row of first matrix"<<endl;
    int row;
    cin>>row;
    cout<<"please enter column of first matrix"<<endl;
    int col;
    cin>>col;
    cout<<"please enter the elements of the first matrix"<<endl;
    Matrix m1(row,col);
    m1.setdatafirsttime(false);
    cout<<"please enter row of second matrix"<<endl;
    cin>>row;
    cout<<"please enter column of second matrix"<<endl;
    cin>>col;
    cout<<"please enter the elements of the second matrix"<<endl;
    Matrix m2(row,col);
    m2.setdatafirsttime(false);
    bool IsProgramRuning=true;
    while(IsProgramRuning)
    {
        cout<<"please choose an operation from the following:"<<endl<<"1:Add the two matrices"<<endl<<"2:Subtract the two matrices"<<endl;
        cout<<"3:Multiply the two matrices"<<endl<<"4:Add scalar to all elements of a matrix"<<endl<<"5:Subtract scalar to all elements of a matrix"<<endl;
        cout<<"6:Multiply scalar to all elements of a matrix"<<endl<<"7:Find the transpose of the matrix"<<endl<<"8:Check if the matrix is square"<<endl;
        cout<<"9:Check if the matrix is identity"<<endl<<"10: change first matrix"<<endl<<"11: change second matrix"<<endl<<"12:End the program";
        string operation;
        cin>>operation;
        if (operation=="1")
        {
            Matrix result =m1+m2;
            cout<<result;

        }
        else if (operation=="2")
        {
            Matrix result =m1-m2;
            cout<<result;

        }
         else if (operation=="3")
        {
            Matrix result =m1*m2;
            cout<<result;
        }
         else if (operation=="4")
        {
            cout<<"write 1 if you want to add a scalar to the first matrix"<<endl<<"write 2 if you want to add a scalar to the second matrix"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m1.addScalar(scalar);
                cout<<m1;
            }
            else if (temp=="2")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m2.addScalar(scalar);
                cout<<m2;
            }
            else
                cout<<"invalid input"<<endl;

        }
         else if (operation=="5")
        {
             cout<<"write 1 if you want to subtract a scalar from the first matrix"<<endl<<"write 2 if you want to subtract a scalar from the second matrix"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m1.subtractScalar(scalar);
                cout<<m1;
            }
            else if (temp=="2")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m2.subtractScalar(scalar);
                cout<<m2;
            }
            else
                cout<<"invalid input"<<endl;


        }
         else if (operation=="6")
        {
             cout<<"write 1 if you want to multiply a scalar to the first matrix"<<endl<<"write 2 if you want to multiply a scalar to the second matrix"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m1.multiplyScalar(scalar);
                cout<<m1;
            }
            else if (temp=="2")
            {
                cout<<"insert the scalar number"<<endl;
                int scalar;
                cin>>scalar;
                m2.multiplyScalar(scalar);
                cout<<m2;
            }
            else
                cout<<"invalid input"<<endl;

        }
         else if (operation=="7")
        {
             cout<<"write 1 if you want to find the transpose of the first matrix"<<endl<<"write 2 if you want to find the transpose of the second matrix"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
               Matrix result =m1.transpose();
               cout<<result;
            }
            else if (temp=="2")
            {
               Matrix result =m2.transpose();
               cout<<result;
            }
            else
                cout<<"invalid input"<<endl;
        }
         else if (operation=="8")
        {
            cout<<"write 1 if you want to find if the first matrix is square"<<endl<<"write 2 if you want to find if the second matrix is square"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
                if(m1.isSquare())
                {
                    cout<<"The matrix is a square"<<endl;
                }
                else
                    cout<<"The matrix is not a square"<<endl;
            }
            else if (temp=="2")
            {
            if(m2.isSquare())
                {
                    cout<<"The matrix is a square"<<endl;
                }
                else
                    cout<<"The matrix is not a square"<<endl;
            }
            else
                cout<<"invalid input"<<endl;
        }
         else if (operation=="9")
        {
            cout<<"write 1 if you want to find if the first matrix is an identity matrix"<<endl<<"write 2 if you want to find if the second matrix is an identity matrix"<<endl;
            string temp;
            cin>>temp;
            if(temp=="1")
            {
                if(m1.isIdentity())
                {
                    cout<<"The matrix is an identity matrix"<<endl;
                }
                else
                    cout<<"The matrix is not an identity matrix"<<endl;
            }
            else if (temp=="2")
            {
            if(m2.isIdentity())
                {
                    cout<<"The matrix is an identity matrix"<<endl;
                }
                else
                    cout<<"The matrix is not an identity matrix"<<endl;
            }
            else
                cout<<"invalid input"<<endl;

        }
         else if (operation=="10")
        {
                cout<<"please enter row of first matrix"<<endl;
                cin>>row;
                cout<<"please enter column of first matrix"<<endl;
                cin>>col;
                cout<<"please enter the elements of the first matrix"<<endl;
                m1.setrow(row);
                m1.setcol(col);
                m1.setdatafirsttime(true);
        }
        else if (operation=="11")
        {
                cout<<"please enter row of second matrix"<<endl;
                cin>>row;
                cout<<"please enter column of second matrix"<<endl;
                cin>>col;
                cout<<"please enter the elements of the second matrix"<<endl;
                m2.setrow(row);
                m2.setcol(col);
                m2.setdatafirsttime(true);
        }
        else if (operation=="12")
        {
            IsProgramRuning=false;
        }
        else
        {
            cout<<"please insert a number between 1 and 12"<<endl;
        }

    }
}
