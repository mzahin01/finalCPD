//بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
#define fr(v,p,q) for(int v=p;p<=q?v<=q:v>=q;p<=q?v+=1:v-=1)
#define shwp(p) for(auto &v:p){cout<<v.first<<" "<<v.second<<"\n";}
#define shw(v) for(auto &v1:v){cout<<v1<<" ";}nl;
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
#define sci(x) scanf("%d", &x)
#define linf (1ll << 62)
#define inf (1 << 30)
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"
#define all(p) (p).begin(),(p).end()
#define mx(_a) *max_element(all(_a))
#define mn(_a) *min_element(all(_a))
#define ll long long
#define vpii vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define vpic vector<pair<int,char> >

int main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        int waitingTime[n], turnaroundTime[n];

        cout << "Enter the number of processes: ";
        cin >> n;
        int burstTime[n];
        for (int i = 0; i < n; i++) {
            cout << "Enter burst time for process " << i + 1 << ": ";
            cin >> burstTime[i];
        }
        waitingTime[0] = 0;
        turnaroundTime[0] = burstTime[0];
        for (int i = 1; i < n; i++) {
            waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
            turnaroundTime[i] = waitingTime[i] + burstTime[i];
        }
        cout << "Process" << " " << "BurstTime" << " " << "WaitingTime" << " " << "TurnaroundTime" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "          " << burstTime[i] << "          " << waitingTime[i] << "       " << turnaroundTime[i] << endl;
        }
        ll totalWaitingTime = 0, totalTurnaroundTime = 0;
        for (int i = 0; i < n; i++) {
            totalWaitingTime += waitingTime[i];
            totalTurnaroundTime += turnaroundTime[i];
        }
        int avgWaitingTime = totalWaitingTime / n;
        int avgTurnaroundTime = totalTurnaroundTime / n;
        cout << "Average Waiting Time: " << avgWaitingTime << endl;
        cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    }
}