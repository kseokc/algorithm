//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<queue>
#include<vector>

#define Max 1001
using namespace std;

int N, M, cnt, to, from;
bool sol = true;
vector<vector<int>> graph;
int in_degree[Max];
int parent[Max];
vector<int> ans;
queue<int> Q;

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> cnt;
        from = 0;
        for (int j = 0; j < cnt; j++) {
            cin >> to;
            if (from != 0) {
                graph[from].emplace_back(to);
                in_degree[to]++;
            }
            from = to;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] != 0)continue;
        Q.push(i);
        ans.emplace_back(i);
    }

    while (!Q.empty()) {
        int front = Q.front();
        Q.pop();
        for (int i = 0; i < graph[front].size(); i++) {
            in_degree[graph[front][i]]--;
            if (in_degree[graph[front][i]] == 0) {
                Q.push(graph[front][i]);
                ans.emplace_back(graph[front][i]);
            }
        }
    }
    if (ans.size() == N) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << '\n';
        }
    } else {
        cout << "0";
    }

}