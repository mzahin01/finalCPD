#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int pid;         // Process ID
    int at;          // Arrival Time
    int bt;          // Burst Time
    int ct;          // Completion Time
    int tat;         // Turnaround Time
    int wt;          // Waiting Time
};

// Comparator for sorting by arrival time, then by burst time
bool compareArrival(const Process& a, const Process& b) {
    if (a.at == b.at)
        return a.bt < b.bt;
    return a.at < b.at;
}

// Comparator for sorting by burst time (used during execution)
bool compareBurst(const Process& a, const Process& b) {
    return a.bt < b.bt;
}

void calculateSJF(vector<Process>& processes, int n) {
    sort(processes.begin(), processes.end(), compareArrival); // Sort by arrival time
    int currentTime = 0;
    vector<bool> completed(n, false); // Track completed processes
    int completedCount = 0;

    while (completedCount < n) {
        // Find the process with the shortest burst time among the arrived processes
        vector<Process> readyQueue;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && processes[i].at <= currentTime) {
                readyQueue.push_back(processes[i]);
            }
        }

        if (!readyQueue.empty()) {
            sort(readyQueue.begin(), readyQueue.end(), compareBurst);
            int selectedPid = readyQueue[0].pid;

            // Execute the process
            for (int i = 0; i < n; i++) {
                if (processes[i].pid == selectedPid) {
                    currentTime += processes[i].bt;
                    processes[i].ct = currentTime;
                    processes[i].tat = processes[i].ct - processes[i].at;
                    processes[i].wt = processes[i].tat - processes[i].bt;
                    completed[i] = true;
                    completedCount++;
                    break;
                }
            }
        }
        else {
            currentTime++; // Increment time if no process is ready
        }
    }

    // Calculate average WT and TAT
    float avgWT = 0, avgTAT = 0;
    for (const auto& p : processes) {
        avgWT += p.wt;
        avgTAT += p.tat;
    }
    avgWT /= n;
    avgTAT /= n;

    // Display the results
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }
    cout << "Average Waiting Time: " << avgWT << endl;
    cout << "Average Turnaround Time: " << avgTAT << endl;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Process ID starts from 1
        cout << "Enter Arrival Time and Burst Time for Process " << processes[i].pid << ": ";
        cin >> processes[i].at >> processes[i].bt;
    }
    cout << endl;
    calculateSJF(processes, n);

    return 0;
}