#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n][6], tt = 0;
        vector<pair<int, int>> arrival(n);
        vector<pair<int, int>> burst(n);
        tuple<int, int, int> p[n];
        cout << "Enter the arrival & burst times for " << n << " processes:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Process " << i + 1 << " Arrival Time: ";
            cin >> arr[i][1];
            arrival[i] = { i + 1, arr[i][1] };
            cout << "Process " << i + 1 << " Burst Time: ";
            cin >> arr[i][2];
            burst[i] = { i + 1, arr[i][2] };
            p[i] = { i + 1, arr[i][1], arr[i][2] };

        }
        cout << endl;
        sort(arrival.begin(), arrival.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
            });
        sort(burst.begin(), burst.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
            });
        tt = arrival[0].second;
        int i = 0;
        while (tt >= get<1>(p[i])) {
            i++;
        }
        sort(p, p + i, [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b);
            });






        for (int i = 1; i < n; i++) {
            arr[arrival[i].first - 1][3] = arr[arrival[i - 1].first - 1][3] + burst[i].second;
        }




        cout << "Process" << " " << "AT" << " " << "BT" << " " << "CT" << " " << "TT" << " " << "WT" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "\t" << arr[i][1] << "  " << arr[i][2] << "  " << arr[i][3] << "  " << arr[i][4] << "  " << arr[i][5] << endl;
        }


    }
}