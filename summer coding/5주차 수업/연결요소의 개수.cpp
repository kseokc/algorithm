//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<vector>

using namespace std;

vector<int> graph[1001];
int vertex[1001];
int N, M, ver1, ver2;
int cnt;

void dfs(int strat) {
    vertex[strat] = true;
    for (int i = 0; i < graph[strat].size(); i++) {
        if (vertex[graph[strat][i]])continue;
        dfs(graph[strat][i]);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> ver1 >> ver2;
        graph[ver1].push_back(ver2);
        graph[ver2].push_back(ver1);
    }
    for (int i = 1; i <= N; i++) {
        if (vertex[i])continue;
        dfs(i);
        cnt++;
    }
    cout << cnt;
}