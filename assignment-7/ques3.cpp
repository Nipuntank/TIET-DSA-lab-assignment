#include <iostream>
#include<unordered_map>
using namespace std;
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Find(int *arr1,int n1,int *arr2,int n2)
{
    unordered_map<int,int>map;
    for(int i=0;i<n2;i++)
    {
        map[arr2[i]]++;
    }
    for(int i=0;i<n1;i++)
    {
        if(map.count(arr1[i])==0)
        {
            cout<<arr1[i]<<" ";
        }
    }
}
int main()
{
    int n1,n2;
    int arr1[100],arr2[100];
    cout<<"Enter the size of the array:";
    cin>>n1;
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the size of the array:";
    cin>>n2;
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    cout<<"Array 1:";
    print(arr1,n1);
    cout<<"Array 2:";
    print(arr2,n2);
    Find(arr1,n1,arr2,n2);
    return 0;
}