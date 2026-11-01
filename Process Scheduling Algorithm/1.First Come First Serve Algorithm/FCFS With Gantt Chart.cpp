#include<bits/stdc++.h>
using namespace std;
struct Process
{
    int pno;
    int at;
    int bt;
    int ct;
};
int main()
{
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    Process p[n];
    for(int i = 0;i < n;i++)
    {
        cout<<endl<<"Enter Process Number: ";
        cin>>p[i].pno;
        cout<<"Enter Arrival Time: ";
        cin>>p[i].at;
        cout<<"Enter Burst Time: ";
        cin>>p[i].bt;
    }
    sort(p,p + n,[](Process a,Process b)
    {
        return a.at < b.at;
    });
    int time = 0;
    for(int i = 0;i < n;i++)
    {
        if(time < p[i].at)
        {
            time = p[i].at;
        }
        time = time + p[i].bt;
        p[i].ct = time;
    }
    cout<<endl<<endl<<"Gantt Chart:"<<endl;
    cout<<"-------";
    for(int i = 0;i < n;i++)
    {
        if(i == 0 && p[i].at > 0)
        {
            cout<<"--------";
        }
        cout<<"-------";
    }
    cout<<endl<<"|";
    if(p[0].at>0)
    {
        cout<<"IDLE |";
    }
    for(int i = 0;i < n;i++)
    {
        cout<<"  P"<<p[i].pno<<" |";

        if(i < n-1 && p[i].ct < p[i+1].at)
        {
            cout<<"IDLE |";
        }
    }
    cout<<endl;
    cout<<"-------";
    for(int i = 0;i < n;i++)
    {
        if(i == 0 && p[i].at > 0)
        {
            cout<<"--------";
        }
        cout<<"-------";
    }
    cout<<endl;
    cout<<"0";
    if(p[0].at > 0)
    {
        cout<<"       "<<p[0].at;
    }
    for(int i = 0;i < n;i++)
    {
        cout<<"     "<<p[i].ct;
        if(i < n-1 && p[i].ct < p[i+1].at)
        {
            cout<<"     "<<p[i+1].at;
        }
    }
    cout<<endl<<endl<<"Process\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;
    float total_tat = 0;
    float total_wt = 0;
    float total_rt = 0;
    for(int i = 0;i < n;i++)
    {
        int tat = p[i].ct-p[i].at;
        int wt = tat-p[i].bt;
        int rt = tat-p[i].bt;
        total_tat = total_tat + tat;
        total_wt = total_wt + wt;
        total_rt = total_rt + rt;
        cout<<"P"<<p[i].pno<<"   \t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<tat<<"\t"<<wt<<"\t"<<rt<<endl;
    }
    cout<<endl;
    cout<<"Average TAT = "<<total_tat/n<<endl;
    cout<<"Average WT = "<<total_wt/n<<endl;
    cout<<"Average RT = "<<total_rt/n<<endl;
    return 0;
}
