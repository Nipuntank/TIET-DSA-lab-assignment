#include <iostream>
using namespace std;
int maxrqd[100][100] ,allocated[100][100], need[100][100], avail[100];
int p, r;

int main()
{
    int i, j;
    cout << "Deadlock Detection Algorithm\n\n";
    
     //Input
    cout << "Enter the no of Processes\t";
    cin >> p;
    cout << "Enter the no of resources\t";
    cin >> r;
    cout << "Enter the Max instances required of each resource for each process \n from P1 to P"<<p<<"\n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> maxrqd[i][j];
        }
    }
    cout << "Enter the instances  allocated of each resource  for  each process \n";
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> allocated[i][j];
        }
    }
    cout << "Enter available resources\n";
    for (j = 0; j < r; j++)
    {
        cin >> avail[j];
    }


    //Display
    cout << "Process\t Allocated\t Max Required\t Available\t";
    for (i = 0; i < p; i++)
    {
        cout << "\nP" << i + 1 << "\t ";
        for (j = 0; j < r; j++)
        {
            cout << allocated[i][j] << " ";
        }
        cout << "\t\t";
        for (j = 0; j < r; j++)
        {
            cout << maxrqd[i][j] << " ";
        }
        cout << "\t\t";
        if (i == 0)
        {
            for (j = 0; j < r; j++)
                cout << avail[j] << " ";
        }
    }
    
    //cal
    int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
    int deadlocked[100];
    int safe[100];
    
    for (i = 0; i < p; i++)
    {
        finish[i] = 0;
    }
    
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = maxrqd[i][j] - allocated[i][j];
        }
    }
    while (flag)
    {
        flag = 0;
        for (i = 0; i < p; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            avail[k] += allocated[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        
                        if (finish[i] == 1)
                        {
                            i = p;
                        }
                    }
                }
            }
        }
    }
    j = 0;
    flag = 0;
    for (i = 0; i < p; i++)
    {
        if (finish[i] == 0)
        {
            deadlocked[j] = i;
            j++;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "\n\nSystem is in Deadlock and the Deadlocked processes are\n";
        for (i = 0; i < p; i++)
        {
            cout << "P" << deadlocked[i] << "\t";
        }
    }
    else
    {
        cout << "\nNo Deadlock";
    }

    return 0;
}