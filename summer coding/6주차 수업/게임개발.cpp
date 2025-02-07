//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, T, num, Max;
vector<vector<int>> graph;
int in_degree[501];
int Time[501];
int dp[501];
queue<int> Q;

int main() {
    cin >> N;
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T;
        Time[i] = T;
        while (1) {
            cin >> num;
            if (num == -1)break;
            graph[num].emplace_back(i);
            in_degree[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            Q.push(i);
            dp[i] = Time[i];
        }
    }

    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        for (int i = 0; i < graph[front].size(); i++) {
            in_degree[graph[front][i]]--;
            if (in_degree[graph[front][i]] == 0) {
                Q.push(graph[front][i]);
            }
            dp[graph[front][i]] = max(dp[graph[front][i]], dp[front] + Time[graph[front][i]]);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << '\n';
    }
}