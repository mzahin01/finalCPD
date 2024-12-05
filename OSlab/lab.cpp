//بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
using namespace std;

int main() {
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
            cout << i + 1 << "\t" << burstTime[i] << "\t" << waitingTime[i] << "\t" << turnaroundTime[i] << endl;
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