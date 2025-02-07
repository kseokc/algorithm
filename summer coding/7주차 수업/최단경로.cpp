//
// Created by 김석찬 on 2022/09/03.
//

#include<iostream>
#include<vector>
#include<queue>

#define INF 200001
#define Max 20001
using namespace std;


int v, e, v1, v2, w, strat;
int dist[Max];
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;


void set_dist() {
    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
}

void sol() {
    Q.push({0, strat});
    dist[strat] = 0;
    while (!Q.empty()) {
        int d = Q.top().first;
        int now = Q.top().second;

        Q.pop();

        if (d > dist[now])continue;

        for (auto i: graph[now]) {
            int now_ = i.first;
            int d_ = d + i.second;
            if (dist[now_] > d_) {
                dist[now_] = d_;
                Q.push({d_, now_});
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> v >> e >> strat;

    graph.resize(v + 1);

    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> w;
        graph[v1].emplace_back(v2, w);
    }

    set_dist();
    sol();

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF)cout << "INF\n";
        else cout << dist[i] << '\n';
    }
}
