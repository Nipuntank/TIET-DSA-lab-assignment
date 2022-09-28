#include<iostream>
using namespace std;
void sum_row(int arr[][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum = sum+arr[i][j];
        }
        cout<<"Sum of "<<i<<"th row: "<<sum<<endl;
    }
}
void sum_coloumn(int arr[][10],int m,int n)
{
    for(int i=0;i<m;i++)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum = sum+arr[j][i];
        }
        cout<<"Sum of "<<i<<"th columns: "<<sum<<endl;
    }
}
int main()
{
    int n,m;
    cout<<"Enter the order of matrix:";
    cin>>m>>n;
    int arr[10][10];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    sum_row(arr,m,n);
    sum_coloumn(arr,m,n);
    return 0;
}