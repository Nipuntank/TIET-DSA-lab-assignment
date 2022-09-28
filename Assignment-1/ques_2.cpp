#include <iostream>
using namespace std;
void display(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubble_sort(int *arr,int &n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void duplicate(int *arr, int &n)
{
    if(n==1 || n==0)
    {
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            for(int j=i+1;j<n;j++)
            {
                arr[j]=arr[j+1];
            }
            n--;
            i--;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before removal of duplicate element: ";
    display(arr, n);
    bubble_sort(arr,n);
    duplicate(arr,n);
    cout << "Array after removal of dupliactes elements: ";
    display(arr, n);
    return 0;
}