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

    int time = 0;
    int completed = 0;

    while(completed < n)
    {
        int pos = -1;

        for(int i = 0;i < n;i++)
        {
            if(p[i].at <= time && p[i].ct == 0)
            {
                if(pos == -1 || p[i].bt < p[pos].bt)
                {
                    pos = i;
                }
            }
        }

        if(pos == -1)
        {
            time++;
        }
        else
        {
            time = time + p[pos].bt;
            p[pos].ct = time;
            completed++;
        }
    }

    cout<<endl<<endl;
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;

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
