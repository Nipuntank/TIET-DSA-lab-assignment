#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void display(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void bubble_sort(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
int main()
{
    int n;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n];
    cout << "Enter the element in the array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Array before sorting: ";
    display(arr, n);
    bubble_sort(arr, n);
    cout << endl
         << "Array after sorting: ";
    display(arr, n);
    return 0;
}