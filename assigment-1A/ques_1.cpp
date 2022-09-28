#include <iostream>
using namespace std;
void display_matrix(int arr[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void diagonal_matrix(int arr[][10], int m, int n)
{
    int arr1[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                arr1[i][j] = arr[i][j];
            }
            else
            {
                arr1[i][j] = 0;
            }
        }
    }
    cout << "Diagonal matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }
}
void tridiagonal_matrix(int arr[][10], int m, int n)
{
    int arr2[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || j - i == 1 || i - j == 1)
            {
                arr2[i][j] = arr[i][j];
            }
            else
            {
                arr2[i][j] = 0;
            }
        }
    }
    cout << "Tri-Diagonal Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
}
void upper_triangular(int arr[][10], int m, int n)
{
    int arr3[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j > 0)
            {
                arr3[i][j] = 0;
            }
            else
            {
                arr3[i][j] = arr[i][j];
            }
        }
    }
    cout << "Upper Triangular Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}
void lower_triangular(int arr[][10], int m, int n)
{
    int arr3[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j - i > 0)
            {
                arr3[i][j] = 0;
            }
            else
            {
                arr3[i][j] = arr[i][j];
            }
        }
    }
    cout << "Lower Triangular Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}
void symmetric_matrix(int arr[][10], int m, int n)
{
    int arr5[m][n];
    if (m != n)
    {
        cout << "Not a square matrix:" << endl;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr5[i][j] = arr[j][i];
        }
    }
    int chk = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] - arr5[i][j] == 0)
            {
                chk++;
            }
        }
    }
    if (chk == m * n)
    {
        cout << "matrix is symmetric matrix" << endl;
    }
    else
    {
        cout << "Not a symmetric matrix" << endl;
    }
}
int main()
{
    int m, n;
    cout << "Enter the order of matrix:";
    cin >> m >> n;
    int arr[10][10];
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout<<"1.Diagonal Matrix"<<endl;
    cout<<"2.Tri-diagonal Matrix"<<endl;
    cout<<"3.Lower triangular Matrix"<<endl;
    cout<<"4.Upper triangular Matrix"<<endl;
    cout<<"5.Symmetric Matrix"<<endl;
    cout<<"Enter your choice"<<endl;
    int no;
    cin >> no;
    switch (no)
    {
    case 1:
    {
        diagonal_matrix(arr, m, n);
        cout << endl;
        break;
    }
    case 2:
    {
        tridiagonal_matrix(arr, m, n);
        cout << endl;
        break;
    }
    case 3:
    {
        upper_triangular(arr, m, n);
        cout << endl;
        break;
    }
    case 4:
    {
        lower_triangular(arr, m, n);
        cout << endl;
        break;
    }
    case 5:
    {
        symmetric_matrix(arr, m, n);
        cout << endl;
        break;
    }
    }

    return 0;
}