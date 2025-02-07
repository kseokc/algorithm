//
// Created by 김석찬 on 2022/11/16.
//

//부모와 자식 사이를 1촌
// 부모와 나의 관계가 1촌임
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int n, p1, p2, m;

vector<vector<int>> v;
bool visit[101];

int bfs(int a, int b) {
    queue<pair<int, int>> Q;
    Q.push({a, 0});
    visit[a] = true;
    while (!Q.empty()) {
        int cnt = Q.front().second;
        int number = Q.front().first;
        if (number == b)return cnt;
        Q.pop();
        for (int i = 0; i < v[number].size(); i++) {
            if (visit[v[number][i]])continue;
            visit[v[number][i]] = true;
            Q.push({v[number][i], cnt + 1});
        }
    }
    return -1;
}

void input() {
    cin >> n >> p1 >> p2 >> m;
    v.resize(n + 1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

void sol() {
    input();
    cout << bfs(p1, p2);
}

int main() {
    sol();
}