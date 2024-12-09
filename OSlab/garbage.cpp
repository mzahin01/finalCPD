// arr[p[0].first - 1][3] = p[0].second;
      // for (int i = 0; i < n; i++) {
      //     arr[p[i].first - 1][2] = i + 1;
      // }
      // for (int i = 1; i < n; i++) {
      //     arr[p[i].first - 1][3] = arr[p[i - 1].first - 1][3] + p[i - 1].second;
      // }
      // for (int i = 0; i < n; i++) {
      //     arr[p[i].first - 1][4] = arr[p[i].first - 1][3] + p[i].second;
      // }

      // int totalWaitingTime = 0, totalTurnaroundTime = 0;
      // for (int i = 0; i < n; i++) {
      //     totalWaitingTime += arr[i][3] - arr[i][1];
      //     totalTurnaroundTime += arr[i][4] - arr[i][1];
      // }
      // int avgWaitingTime = totalWaitingTime / n;
      // int avgTurnaroundTime = totalTurnaroundTime / n;
      // cout << "Average Waiting Time: " << avgWaitingTime << endl;
      // cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;