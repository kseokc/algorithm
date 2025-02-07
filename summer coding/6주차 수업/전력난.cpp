//
// Created by 김석찬 on 2022/08/28.
//

#include<iostream>
#include<queue>

using namespace std;
int parent[200001];
int N, M, x, y, z;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;

int find(int x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

void reset() {
    for (int i = 0; i <= M; i++) {
        parent[i] = i;
    }
}

int main() {
    while (1) {
        cin >> M >> N;
        reset();
        if (N == 0 && M == 0)break;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> x >> y >> z;
            ans += z;
            Q.push({z, {x, y}});
        }
        while (!Q.empty()) {
            int value = Q.top().first;
            int a = Q.top().second.first;
            int b = Q.top().second.second;
            Q.pop();
            if (find(a) == find(b))continue;
            Union(a, b);
            ans -= value;
        }
        cout << ans << '\n';
    }


}