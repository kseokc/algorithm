//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<queue>
#include<vector>

#define Max 1001
using namespace std;

int T, N, K, D_t, to, from, victory;
int Time[Max];
int dp[Max];
vector<vector<int>> graph;
queue<int> Q;
int in_degree[Max];


int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        graph.resize(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> D_t;
            Time[i] = D_t;
        }
        for (int i = 0; i < K; i++) {
            cin >> from >> to;
            graph[from].emplace_back(to);
            in_degree[to]++;
        }
        cin >> victory;
        for (int i = 1; i <= N; i++) {
            if (in_degree[i])continue;
            Q.push(i);
            dp[i] = Time[i];
        }

        while (!Q.empty()) {
            int build = Q.front();
            Q.pop();
            for (int i = 0; i < graph[build].size(); i++) {
                in_degree[graph[build][i]]--;
                if (!in_degree[graph[build][i]])Q.push(graph[build][i]);
                dp[graph[build][i]] = max(dp[graph[build][i]], dp[build] + Time[graph[build][i]]);
            }
        }

        cout << dp[victory] << '\n';

        for (int i = 0; i <= N; i++) {
            dp[i] = 0;
            Time[i] = 0;
            in_degree[i] = 0;
        }
        graph.clear();
    }
}