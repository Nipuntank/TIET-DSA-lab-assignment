#include<iostream>
using namespace std;

int missing(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>i+1)
        {
            return i+1;
        }
    }
    return -1;
}
int missing_no(int *arr,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum =sum+arr[i];
    }
    int sum_pd= ((n+1)*n)/2;
    int miss=sum-sum_pd;
    return miss;
}

// with another approach

/*int missing_xor(int *arr,int n)
{
    int x=0;
    for(int i=0;i<n;i++)
    {
        x = x ^ arr[i];
    }
    for(int i=1;i<=n+1;i++)
    {
        x = x ^ i;
    }
    return x;
}*/
int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Mising number in the array: "<<missing(arr,n)<<endl;
    return 0;
}