//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<vector>
#include<queue>

#define Max 10001
using namespace std;

int in_degree[Max];
int dp[Max];
int Time[Max];
queue<int> Q;
vector<vector<int>> graph;

int N, value, cnt, num, ans;

int main() {
    cin >> N;
    graph.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> value >> cnt;
        Time[i] = value;
        for (int j = 0; j < cnt; j++) {
            cin >> num;
            graph[num].emplace_back(i);
            in_degree[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] != 0)continue;
        Q.push(i);
        dp[i] = Time[i];
    }

    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        for (int i = 0; i < graph[front].size(); i++) {
            in_degree[graph[front][i]]--;
            if (!in_degree[graph[front][i]])Q.push(graph[front][i]);
            dp[graph[front][i]] = max(dp[graph[front][i]], dp[front] + Time[graph[front][i]]);
        }
    }

    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;

}