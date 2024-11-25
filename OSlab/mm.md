# Lab Report : First - Come, First - Served(FCFS) Scheduling Algorithm

-- -

## * *Title : **
Implementation of the FCFS Scheduling Algorithm in C++

-- -

## * *Objective : **
To implement the First - Come, First - Served(FCFS) CPU scheduling algorithm and calculate the Waiting Time, Turnaround Time, and Completion Time for a given set of processes.

-- -

## * *Introduction : **
The * *First - Come, First - Served(FCFS) * *scheduling algorithm is one of the simplest types of CPU scheduling techniques.In FCFS, the process that arrives first is executed first.This algorithm is non - preemptive and operates in a queue - like structure.

-- -

## * *Algorithm : **
1. Take the number of processes as input.
2. For each process, input the** Arrival Time** and **Burst Time** .
3. Initialize the Waiting Time of the first process to its Arrival Time.
4. For each subsequent process :
-Calculate Waiting Time based on the completion of the previous process.
- Calculate Completion Time by adding Burst Time to the previous Completion Time.
- Calculate Turnaround Time as the difference between Completion Time and Arrival Time.
5. Output all calculated metrics in tabular form.

-- -

## * *Code:**
```cpp
// بِسْمِ ٱللَّهِ ٱلرَّحْمَـٰنِ ٱلرَّحِيمِ
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
```

-- -

## * *Explanation of Code : **
1. * *Input Section : **
-The code begins by taking the number of processes `n` as input.
- For each process, the** Arrival Time** and **Burst Time** are input.

2. * *Initialization:**
-The Waiting Time for the first process is initialized as its Arrival Time.
- Completion Time and Turnaround Time for the first process are calculated accordingly.

3. * *Computation Loop : **
-For subsequent processes :
-**Waiting Time * *: Calculated as the difference between the Completion Time of the previous process and the Arrival Time of the current process.
- **Completion Time * *: Updated by adding the Burst Time to the previous Completion Time.
- **Turnaround Time * *: Computed as the difference between Completion Time and Arrival Time.

4. * *Output Section : **
-Displays all metrics(Process, Arrival Time, Burst Time, Waiting Time, Turnaround Time, Completion Time) in a tabular format.

-- -

## * *Sample Output : **
**Input : **
```
Enter the number of processes : 3
Enter arrival time for process 1 : 0
Enter burst time for process 1 : 5
Enter arrival time for process 2 : 2
Enter burst time for process 2 : 3
Enter arrival time for process 3 : 3
Enter burst time for process 3 : 8
```

* *Output:**
```
Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time	Completion Time
1	0		5		0		5		5
2	2		3		3		6		8
3	3		8		5		13		16
```

-- -

## * *Conclusion:**
The FCFS scheduling algorithm is implemented successfully in C++.The program calculates the Waiting Time, Turnaround Time, and Completion Time for each process based on their order of arrival.

-- -

## * *Key Observations : **
1. FCFS may lead to the * *Convoy Effect**, where shorter processes have to wait for longer ones.
2. It is simple and easy to implement but not the most efficient algorithm.

-- -

## * *References:**
-Operating System Concepts by Abraham Silberschatz
- Online C++ documentation
- Classroom lecture notes