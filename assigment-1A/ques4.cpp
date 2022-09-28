#include <iostream>
using namespace std;
void saddle_point(int arr[][10], int m, int n)
{
    int i, j, k, min, max,pos[2][2];
    for (i = 0; i < m; i++)
    {
        min = arr[i][0];
        for (j = 0; j < m; j++)
        {
            if (min >= arr[i][j])
            {
                min = arr[i][j];
                pos[0][0] = i;
                pos[0][1] = j;
            }
        }
        j = pos[0][1];
        max = arr[0][j];
        for (k = 0; k < m; k++)
        {
            if (max <= arr[k][j])
            {
                max = arr[i][j];
                pos[1][0] = k;
                pos[1][1] = j;
            }
        }
        if (min == max)
        {
            if (pos[0][0] == pos[1][0] && pos[0][1] == pos[1][1])
            {
                cout <<"Saddle point("<< pos[0][0] << "," << pos[0][1] << "):" << max << endl;
            }
        }
    }
}
int main()
{
    int m,n;
    cout<<"Enter the number of rows and columns in 2D array:";
    cin>>m>>n;
    int arr[10][10];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    saddle_point(arr,m,n);

    return 0;
}