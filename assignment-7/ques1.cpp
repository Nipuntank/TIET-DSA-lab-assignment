#include<iostream>
#include<unordered_map>
using namespace std;
void print(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void MaximumFreq(int *arr,int n)
{
    unordered_map<int,int>map;
    int max=0,ele=arr[0];
    for(int i=0;i<n;i++)
    {
        map[arr[i]]++;
        if(map[arr[i]]>max)
        {
            max = map[arr[i]];
            ele=arr[i];
        }
    }
    cout<<"Maximum frequency is of number "<<ele<<" is "<<max<<endl;
}
int main()
{
    int n;
    int arr[100];
    cout<<"Enter the size of the array:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr,n);
    MaximumFreq(arr,n);
    return 0;
}