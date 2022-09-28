#include<iostream>
using namespace std;
int Binary_search(int *arr,int &n,int ele)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid =(start+end)/2;
        if(arr[mid]==ele)
        {
            return mid;
        }
        else
        if(arr[mid]>ele)
        {
            end = mid-1;
        }
        else
        {
            start =mid+1;
        }

    }
    return -1;
}
int main()
{
    int n,ele;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the elements to be search: ";
    cin>>ele;
    cout<<"Element found at "<<Binary_search(arr,n,ele)+1<<" position";

    return 0;
}