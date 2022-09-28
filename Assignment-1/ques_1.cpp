#include <iostream>
using namespace std;
void Set_array(int *arr, int &n)
{
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void Display_array(int *arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Insert_array(int *arr, int &n, int index, int ele)
{
    cout << "Array after Inserting an element:";
    n = n + 1;
    for (int i = n - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = ele;
}
void Delete_array(int *arr, int &n, int index)
{
    cout << "Array after Deleting an element:";
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int Search_ele(int *arr, int &n, int ele)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n, ins_index, ins_ele, del_index, sea_ele;
    cout << "Enter the size of the array:";
    cin >> n;
    int arr[n];
    char c = 'y';
    int t;
    cout << "1.CREATE 2.DISPLAY 3.INSERT 4.DELETE 5.SEARCH 6.EXIT"<<endl;;
    while (c == 'y')
    {
        cout << "Enter your choice from above:";
        cin >> t;
        switch (t)
        {
        case 1:
        {
            Set_array(arr, n);
            break;
        }
        case 2:
        {
            Display_array(arr, n);
            break;
        }
        case 3:
        {
            cout << "Enter the element and index to be stored:";
            cin >> ins_ele >> ins_index;
            Insert_array(arr, n, ins_index, ins_ele);
            Display_array(arr, n);
            break;
        }
        case 4:
        {
            cout << "Enter the index to be deleted in the array: ";
            cin >> del_index;
            Delete_array(arr, n, del_index);
            Display_array(arr, n);
            break;
        }
        case 5:
        {
            cout << "Enter the element to be search: ";
            cin >> sea_ele;
            cout << "Element found at " << Search_ele(arr, n, sea_ele) << " index" << endl;
            break;
        }
        case 6:
        {
            exit(1);
            break;
        }
        default:
        {
            cout << "Error! Select from above options only :"<<endl;
        }
        }
        cout << "want to Continue y/n:";
        cin >> c;
    }

    return 0;
}