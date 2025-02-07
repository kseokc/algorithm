//
// Created by 김석찬 on 2022/09/07.
//

#include<iostream>
#include<queue>
#include<vector>

#define Max 50001
#define INF 50000001
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
int N, M, A, B, C;
int dist[Max];
vector<vector<pair<int, int>>> v;


void sol() {
    Q.push({0, 1});
    while (!Q.empty()) {
        int now = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if (now == N)return;
        if (dist[now] < d)continue;
        for (auto i: v[now]) {
            int v_now = i.first;
            int v_d = i.second;
            if (dist[v_now] > v_d + d) {
                dist[v_now] = v_d + d;
                Q.push({d + v_d, v_now});
            }
        }
    }
}

void set_dist() {
    for (int i = 2; i <= N; i++) {
        dist[i] = INF;
    }
}

int main() {
    cin >> N >> M;
    v.resize(N + 1);
    set_dist();
    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
    }
    sol();
    cout << dist[N];
}