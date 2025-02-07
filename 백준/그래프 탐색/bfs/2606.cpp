//
// Created by 김석찬 on 2022/11/16.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> v;
bool visit[101];
int t, s, i, o;

int bfs() {
    int cnt = 0;
    queue<int> Q;
    Q.push(1);
    visit[1] = true;
    while (!Q.empty()) {
        int number = Q.front();
        cnt += 1;
        Q.pop();
        for (int k = 0; k < v[number].size(); k++) {
            if (visit[v[number][k]])continue;
            visit[v[number][k]] = true;
            Q.push(v[number][k]);
        }
    }
    return cnt - 1;
}

int main() {
    cin >> t;
    v.resize(t + 1);
    cin >> s;
    for (int k = 0; k < s; k++) {
        cin >> i >> o;
        v[i].push_back(o);
        v[o].push_back(i);
    }
    cout << bfs();
}