/*
Matrix arithmetic using templates
*/

#include<iostream>
using namespace std;

template <class T>
class Matrix
{
    T mat[10][10];
    int row;
    int col;

    public:
    Matrix(){ row = 0; col = 0; }
    Matrix(int r, int c) { row = r; col = c; }
    void input();
    void display();
    Matrix<T> transpose();
    Matrix<T> sum(Matrix A);
    Matrix<T> sub(Matrix A);
    Matrix<T> operator *(Matrix A)
    {
        Matrix<T> result(row, col);
        for(int i = 0;i < row;i++)
        for(int j = 0;j < col;j++)
        {
        result.mat[i][j]=0;
        for(int k = 0;k < col;k++)
           result.mat[i][j] += mat[i][k] * A.mat[k][j];
        }
        return result;
    }

};

template <class T>
void Matrix<T>::input(){
    cout<<"Enter the number of rows and columns respectively: ";
    cin>>row>>col;
    cout<<endl;
    for(int i = 0;i < row;i++)
      for(int j = 0;j < col;j++)
      {
        cout<<"Enter element["<<i<<"]["<<j<<"]: ";
        cin>>mat[i][j];
        cout<<endl;
      }
}

template <class T>
void Matrix<T>::display(){
    cout<<endl;
    for(int i = 0;i < row;i++)
     {
      for(int j = 0;j < col;j++)
      {
        cout<<mat[i][j]<<" ";
      }
      cout<<endl;
     }
     cout<<endl;

}

template <class T>
Matrix<T> Matrix<T>::sum(Matrix A)
{
    Matrix<T> n;
    if(row != A.row && col != A.col)
    return n;

    Matrix<T> result(row, col);


    for(int i = 0;i < row;i++)
      for(int j = 0;j < col;j++)
      {
        result.mat[i][j] = mat[i][j] + A.mat[i][j];
      }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::sub(Matrix A)
{
    Matrix<T> n;
    if(row != A.row && col != A.col)
    return n;

    Matrix<T> result(row, col);


    for(int i = 0;i < row;i++)
      for(int j = 0;j < col;j++)
      {
        result.mat[i][j] = mat[i][j] - A.mat[i][j];
      }

    return result;
}

template <class T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> result(row, col);
    for(int i = 0;i < row;i++)
      for(int j = 0;j < col;j++)
      {
        result.mat[i][j] = mat[j][i];
      }

    return result;
}

int main()
{
    Matrix<int> A, B, C;
    A.input();
    cout<<"The first matrix is: \n";
    A.display();
    B.input();
    cout<<"The second matrix is: \n";
    B.display();
    C = A.sum(B);
    cout<<"The sum of the matrices is: \n";
    C.display();
    C = A.sub(B);
    cout<<"The subtraction of the matrices is: \n";
    C.display();
    C = A*B;
    cout<<"The multiplication of the matrices is: \n";
    C.display();
    C = A.transpose();
    cout<<"The transpose of the first matrix is: \n";
    C.display();

    return 0;
}
