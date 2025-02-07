//
// Created by 김석찬 on 2022/08/27.
//
#include<iostream>
#include<queue>
#include<vector>

#define Max 1001
using namespace std;
int N, M, to, from;
int in_degree[Max];
vector<vector<int>> v;
queue<pair<int, int>> Q;
vector<int> ans;

int main() {
    cin >> N >> M;
    v.resize(N + 1);
    ans.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> from >> to;
        v[from].emplace_back(to);
        in_degree[to]++;
    }
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            Q.push({i, 1});
        }
    }
    while (!Q.empty()) {
        int front = Q.front().first;
        int term = Q.front().second;
        Q.pop();
        ans[front] = term;
        for (int i = 0; i < v[front].size(); i++) {
            in_degree[v[front][i]]--;
            if (in_degree[v[front][i]] == 0) {
                Q.push({v[front][i], term + 1});
            }
        }
    }
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}