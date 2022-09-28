#include<iostream>
using namespace std;
void spiral_print(int arr[][10],int m,int n)
{
    int rs=0,cs=0,re=m-1,ce=n-1,k=1;
    while(k<=n*m)
    {
        for(int i=cs;i<=ce;i++)
        {
            cout<<arr[rs][i]<<" ";
            k++;
        }
        rs++;
        for(int i=rs;i<=re;i++)
        {
            cout<<arr[i][ce]<<" ";
            k++;
        }
        ce--;
        for(int i=ce;i>=cs;i--)
        {
            cout<<arr[re][i]<<" ";
            k++;
        }
        re--;
        for(int i=re;i>=rs;i--)
        {
            cout<<arr[i][cs]<<" ";
            k++;
        }
        cs++;
    }
}
int main()
{
    int n,m;
    int arr[10][10];
    cout<<"Enter the order of matrix:";
    cin>>m>>n;
    cout<<"Enter the elements in the array"<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    spiral_print(arr,m,n);
    return 0;
}