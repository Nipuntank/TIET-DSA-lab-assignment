#include <iostream>
using namespace std;
void heapify(int a[], int n, int i)
{
    int parent = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if (leftChild < n && a[leftChild] > a[parent])
        parent = leftChild;

    if (rightChild < n && a[rightChild] > a[parent])
        parent = rightChild;

    if (parent != i)
    {

        int temp = a[i];
        a[i] = a[parent];
        a[parent] = temp;

        heapify(a, n, parent);
    }
}
void heapSort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}
void printArr(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[] = {47, 9, 22, 42, 27, 25, 0};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are - \n";
    printArr(a, n);
    heapSort(a, n);
    cout << "\nAfter sorting array elements are - \n";
    printArr(a, n);
    return 0;
}