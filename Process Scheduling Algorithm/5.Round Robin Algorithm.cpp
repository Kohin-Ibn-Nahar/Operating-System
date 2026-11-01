#include<bits/stdc++.h>
using namespace std;

struct Process
{
    int pno;
    int at;
    int bt;
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

        p[i].rem = p[i].bt;
        p[i].rt = -1;
    }

    int tq;
    cout<<endl<<"Enter Time Quantum: ";
    cin>>tq;

    queue<int> q;

    int time = 0;
    int completed = 0;
    int added[n] = {0};

    while(completed < n)
    {
        for(int i = 0;i < n;i++)
        {
            if(p[i].at <= time && added[i] == 0)
            {
                q.push(i);
                added[i] = 1;
            }
        }

        if(q.empty())
        {
            time++;
            continue;
        }

        int pos = q.front();
        q.pop();

        if(p[pos].rt == -1)
        {
            p[pos].rt = time - p[pos].at;
        }

        if(p[pos].rem > tq)
        {
            time = time + tq;
            p[pos].rem = p[pos].rem - tq;
        }
        else
        {
            time = time + p[pos].rem;
            p[pos].rem = 0;
            p[pos].ct = time;
            completed++;
        }

        for(int i = 0;i < n;i++)
        {
            if(p[i].at <= time && added[i] == 0)
            {
                q.push(i);
                added[i] = 1;
            }
        }

        if(p[pos].rem > 0)
        {
            q.push(pos);
        }
    }

    cout<<endl<<endl;
    cout<<"Process\tAT\tBT\tCT\tTAT\tWT\tRT"<<endl;

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

        cout<<"P"<<p[i].pno<<"   \t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<tat<<"\t"<<wt<<"\t"<<p[i].rt<<endl;
    }

    cout<<endl;
    cout<<"Average TAT = "<<total_tat/n<<endl;
    cout<<"Average WT = "<<total_wt/n<<endl;
    cout<<"Average RT = "<<total_rt/n<<endl;

    return 0;
}
