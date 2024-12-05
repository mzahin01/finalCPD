//بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    int waitingTime[n], turnaroundTime[n], compTime[n];

    cout << "Enter the number of processes: ";
    cin >> n;
    int burstTime[n], arrivalTime[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for process " << i + 1 << ": ";
        cin >> arrivalTime[i];
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> burstTime[i];
    }
    waitingTime[0] = arrivalTime[0];
    turnaroundTime[0] = burstTime[0] - arrivalTime[0];
    compTime[0] = waitingTime[0] + burstTime[0];
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = max(0, (compTime[i - 1] - arrivalTime[i]));
        compTime[i] = compTime[i - 1] + burstTime[i];
        turnaroundTime[i] = compTime[i] - arrivalTime[i];
    }
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" << compTime[i] << "\n";
    }
}