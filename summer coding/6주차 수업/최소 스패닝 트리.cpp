//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define Max 10001
using namespace std;
int V, E, A, B, C, ans, Size;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;
int parent[Max];

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

int main() {
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        Q.push({C, {A, B}});
    }

    while (Size != V && !Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int value = Q.top().first;
        Q.pop();
        if (find(x) == find(y))continue;
        Union(x, y);
        ans += value;
        Size += 1;
    }

    cout << ans;
}