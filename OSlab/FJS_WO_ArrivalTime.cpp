#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n][4];
        vector<pair<int, int>> p(n);
        cout << "Enter the burst times for " << n << " processes:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "P" << i + 1 << ": ";
            cin >> p[i].second;
            arr[i][1] = p[i].second;
            arr[i][0] = i + 1;
            p[i].first = i + 1;
        }
        cout << endl;
        sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
            });
        arr[p[0].first - 1][3] = p[0].second;
        for (int i = 1; i < n; i++) {
            arr[p[i].first - 1][3] = arr[p[i - 1].first - 1][3] + p[i].second;
        }
        arr[p[0].first - 1][2] = 0;
        for (int i = 1; i < n; i++) {
            arr[p[i].first - 1][2] = arr[p[i].first - 1][3] - arr[p[i].first - 1][1];
        }
        cout << "Process" << " " << "BurstTime" << " " << "WaitingTime" << " " << "TurnaroundTime" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i][0] << "\t" << arr[i][1] << "\t" << arr[i][2] << "\t" << arr[i][3] << endl;
        }


    }
}