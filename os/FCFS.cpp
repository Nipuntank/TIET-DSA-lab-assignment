#include<iostream>
using namespace std;
void waitingTime(int *process,int *wt,int *bt,int n)
{
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
}
void TAT(int *process,int *wt,int *bt,int n,int *tat)
{
    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }
}
void avgTime(int *process,int n,int *bt)
{
    int wt[n],tat[n];
    int total_wt=0,total_tat=0;
    waitingTime(process,wt,bt,n);
    TAT(process,wt,bt,n,tat);
    cout<<"Process  "<<" Burst time "<<" Waiting time "<<" TAT \n";
    for(int i=0;i<n;i++)
    {
        total_wt +=wt[i];
        total_tat+=tat[i];
        cout << " " << i+1 << "\t\t" << bt[i] <<"\t "<< wt[i] <<"\t\t " << tat[i] <<endl;
    }
    float avgwt = total_wt/(float)n;
    float avgtat = total_tat/(float)n;
    cout<<"avg wt:"<<avgwt<<endl;
    cout<<"avg wt:"<<avgtat<<endl;
}
int main()
{
    int process[]={1,2,3};
    int n = sizeof(process)/sizeof(process[0]);
    int burstTime[] = {7,3,1};
    avgTime(process,n,burstTime);
}
