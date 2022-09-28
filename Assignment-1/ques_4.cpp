#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void Reverse_array(int *arr, int &n)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }
}
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
void transpose_matrix(int input[][10], int m, int n)
{
    if (m != n)
    {
        swap(&m, &n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << input[j][i] << " ";
        }
        cout << endl;
    }
}
void matrix_multi(int arr1[][10], int arr2[][10], int m1, int n1, int m2, int n2)
{
    int arr3[m1][n2];
    if (n1 != m2)
    {
        cout << "Invalid!";
    }
    else
    {
        for (int i = 0; i < m1; i++)
        {

            for (int j = 0; j < n2; j++)
            {
                arr3[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    arr3[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                cout << arr3[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    
    cout << "1.Reverse the elements of an array" << endl;
    cout << "2.Find the matrix multiplication" << endl;
    cout << "3.Find the Transpose of a Matrix" << endl;
    cout<<endl;
    cout << "Enter the operation which u have to peform : " ;
    int no;
    cin >> no;
    switch (no)
    {
    case 1:
    {
        int a;
        cout << "Enter the size of the array: ";
        cin >> a;
        int arr[a];
        cout << "Enter the elements int the array:";
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }
        cout << "Array before:";
        display(arr, a);
        Reverse_array(arr, a);
        cout << "Array after:";
        display(arr, a);
        break;
    }
    case 2:
    {
        int m1, m2, n1, n2;
        int arr1[10][10], arr2[10][10];
        cout << "Enter the order of first matrix:";
        cin >> m1 >> n1;
        cout << "Enter the elements in the first matrix :";
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                cin >> arr1[i][j];
            }
        }
        cout << "Enter the order of second matrix:";
        cin >> m2 >> n2;
        cout << "Enter the elements in the second matrix :";
        for (int i = 0; i < m2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                cin >> arr2[i][j];
            }
        }
        cout << "Matrix-1:" << endl;
        display_matrix(arr1, m1, n1);
        cout << endl;
        cout << "Matrix-2:" << endl;
        display_matrix(arr2, m2, n2);
        cout << endl;
        cout << "Matrix after multiplication:" << endl;
        matrix_multi(arr1, arr2, m1, n1, m2, n2);
        break;
    }
    case 3:
    {
        int m, n;
        cout << endl
             << "Enter the order of matrix :";
        cin >> m >> n;
        int input[10][10];
        cout << "Enter the elements in the matrix :";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> input[i][j];
            }
        }
        cout << "Enter matrix is:" << endl;
        display_matrix(input, m, n);
        cout << "transpose of the Enterd matrix:" << endl;
        transpose_matrix(input, m, n);
        break;
    }
    }

    return 0;
}