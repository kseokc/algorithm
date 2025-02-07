//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<vector>
#include<queue>

#define Max 1001
using namespace std;

int N, M, a, b, c, ans, brk;
int node[Max];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;


int find(int x) {
    if (x == node[x])return x;
    else {
        return node[x] = find(node[x]);
    }

}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    node[y] = x;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        node[i] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        Q.push({c, {a, b}});
    }
    while (!Q.empty()) {
        if (brk == N)break;
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int money = Q.top().first;
        Q.pop();
        if (find(x) == find(y))continue;
        Union(x, y);
        ans += money;
        brk += 1;
    }
    cout << ans;
}
