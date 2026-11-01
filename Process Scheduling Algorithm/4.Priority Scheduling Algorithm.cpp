#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pno;
    int at;
    int bt;
    int priority;
    int ct;
    int rt;
    int rem;
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
        cout<<"Enter Priority: ";
        cin>>p[i].priority;

        p[i].rem = p[i].bt;
        p[i].rt = -1;
    }

    int time = 0;
    int completed = 0;

    while(completed < n)
    {
        int pos = -1;

        for(int i = 0;i < n;i++)
        {
            if(p[i].at <= time && p[i].rem > 0)
            {
                if(pos == -1 || p[i].priority > p[pos].priority)
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
            if(p[pos].rt == -1)
            {
                p[pos].rt = time - p[pos].at;
            }

            p[pos].rem--;
            time++;

            if(p[pos].rem == 0)
            {
                p[pos].ct = time;
                completed++;
            }
        }
    }

    cout<<endl<<endl;
    cout<<"Process\tAT\tBT\tPriority\tCT\tTAT\tWT\tRT"<<endl;

    float total_tat = 0;
    float total_wt = 0;
    float total_rt = 0;

    for(int i = 0;i < n;i++)
    {
        int tat = p[i].ct - p[i].at;
        int wt = tat - p[i].bt;

        total_tat = total_tat + tat;
        total_wt = total_wt + wt;
        total_rt = total_rt + p[i].rt;

        cout<<"P"<<p[i].pno<<"   \t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].priority<<"\t\t"<<p[i].ct<<"\t"<<tat<<"\t"<<wt<<"\t"<<p[i].rt<<endl;
    }

    cout<<endl;
    cout<<"Average TAT = "<<total_tat/n<<endl;
    cout<<"Average WT = "<<total_wt/n<<endl;
    cout<<"Average RT = "<<total_rt/n<<endl;

    return 0;
}
