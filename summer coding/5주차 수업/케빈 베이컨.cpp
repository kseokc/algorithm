//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> Friend[101];
bool vertex[101];
int v, e, v2, v1, Sum, Min_p;
int Min = 100000;

int bfs(int strat, int last) {
    queue<pair<int, int>> Q;
    Q.push({strat, 0});
    vertex[strat] = true;
    while (!Q.empty()) {
        int number = Q.front().first;
        int cnt = Q.front().second;
        Q.pop();
        if (number == last)return cnt;
        for (int i = 0; i < Friend[number].size(); i++) {
            if (vertex[Friend[number][i]])continue;
            Q.push({Friend[number][i], cnt + 1});
            vertex[Friend[number][i]] = true;
        }
    }
}

void reset() {
    for (int i = 1; i <= v; i++) {
        vertex[i] = false;
    }
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2;
        Friend[v1].push_back(v2);
        Friend[v2].push_back(v1);
    }
    for (int i = 1; i <= v; i++) {
        Sum = 0;
        for (int j = 1; j <= v; j++) {
            if (j == i)continue;
            Sum += bfs(i, j);
            reset();
        }
        if (Min > Sum) {
            Min = Sum;
            Min_p = i;
        }
    }
    cout << Min_p;
}