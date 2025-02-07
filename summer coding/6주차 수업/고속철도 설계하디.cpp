//
// Created by 김석찬 on 2022/08/28.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int parent[201];
int N, money, ans, cnt;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;
vector<pair<int, int>> sol;

void reset() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

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
    cin >> N;
    reset();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> money;
            if (j <= i)continue;
            if (money < 0) {
                ans += -money;
                if (find(i) == find(j))continue;
                Union(i, j);
                cnt++;
            } else {
                Q.push({money, {i, j}});
            }
        }
    }

    while (!Q.empty()) {
        int value = Q.top().first;
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();
        if (find(x) == find(y))continue;
        Union(x, y);
        ans += value;
        sol.emplace_back(x, y);
    }

    cout << ans << " " << sol.size() << '\n';
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].first << " " << sol[i].second << '\n';
    }
}