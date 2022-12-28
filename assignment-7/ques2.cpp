#include <iostream>
using namespace std;
#include<unordered_map>
void print(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
bool FindSumPair(int *arr,int n,int k)
{
    unordered_map<int,int>map;
    for(int i=0;i<n;i++)
    {
        int left = k-arr[i];
        if(map.find(left)!=map.end())
        {
            return true;
        }
        map[arr[i]]++;
    }
    return false;
}
int main()
{
    int n;
    int arr[100];
    cout << "Enter the size of the array:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr,n);
    int k;
    cout<<"Enter the value:";
    cin>>k;
    if(FindSumPair(arr,n,k))
    {
        cout<<"True";
    }
    else
    {
        cout<<"False";
    }
    return 0;
}