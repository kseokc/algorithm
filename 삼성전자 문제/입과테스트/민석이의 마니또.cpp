//
// Created by 김석찬 on 2023/07/09.
//

#include<iostream>
#include <vector>
#include<queue>

#define MAX 1000000000

using namespace std;

vector<vector<pair<int, int>>> V;

int dist[401];
int T;
int N, M;
int a, b, c;


void init() {
    for (int i = 1; i <= N; i++)dist[i] = MAX;
}

int bfs(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.push({0, start});

    while (!Q.empty()) {
        int cur = Q.top().second;
        int value = Q.top().first;

        Q.pop();

        if (value > dist[cur])continue;

        if (cur == start && dist[cur] != MAX)return value;

        for (auto i: V[cur]) {
            int now_ = i.first;
            int d_ = value + i.second;
            if (dist[now_] > d_) {
                dist[now_] = d_;
                Q.push({d_, now_});
            }
        }
    }

    return MAX;
}

void input() {
    cin >> N >> M;
    V.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        V[a].emplace_back(b, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for (int j = 1; j <= T; j++) {
        input();
        int ans = MAX;
        for (int i = 1; i <= N; i++) {
            if (V[i].empty())continue;
            init();
            ans = min(ans, bfs(i));
        }

        if (ans == MAX)cout <<'#'<< j <<" -1\n";
        else cout <<'#'<< j << " " << ans << "\n";
        V.clear();
    }
}