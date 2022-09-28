#include<iostream>
using namespace std;
void spiral_matrix(int arr[][10],int m,int n)
{
    int rs=0,cs=0,re=m-1,ce=n-1,k=1;
    while(k<=n*m)
    {
        for(int i=cs;i<=ce;i++)
        {
            arr[rs][i]=k;
            k++;
        }
        rs++;
        for(int i=rs;i<=re;i++)
        {
            arr[i][ce]=k;
            k++;
        }
        ce--;
        for(int i=ce;i>=cs;i--)
        {
            arr[re][i]=k;
            k++;
        }
        re--;
        for(int i=re;i>=rs;i--)
        {
            arr[i][cs]=k;
            k++;
        }
        cs++;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int m,n;
    int arr[10][10];
    cout<<"Enter the order of matrix:";
    cin>>m>>n;
    spiral_matrix(arr,m,n);
    return 0;
}