#include <iostream>
using namespace std;
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n, at[20], bt[20], ct[20], tat[20], wt[20], atat, awt;
    cout << "enter the number of processes" << endl;
    cin >> n;
    // enter arrival time and burst time for data
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> at[i];
    }
    // sort the data by comparing their arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
            }
        }
    }
    // sort the data by comparing their burst time and arrival time
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[i] == at[j])
            {
                if (bt[i] > bt[j])
                {
                    swap(at[i], at[j]);
                    swap(bt[i], bt[j]);
                }
            }
        }
    }
    int temp;
    int value;
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    for (int i = 1; i < n; i++)
    {
        temp = ct[i - 1];
        int low = bt[i];
        for (int j = i; j <n; j++)
        {
            if (temp >= at[j] && low >= bt[j])
            {
                low = bt[j];
                value = j;
            }
        }
        ct[value] = temp + bt[value];
        tat[value] = ct[value] - at[value];
        wt[value] = tat[value] - bt[value];
    }
    // print the final result
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "1"
             << " " << at[i] << " " << bt[i] << " " << wt[i] << " " << tat[i] << endl;
    }
    return 0;
}