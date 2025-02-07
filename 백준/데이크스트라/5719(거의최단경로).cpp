//
// Created by 김석찬 on 2023/07/05.
//

#include<iostream>
#include<vector>
#include<queue>

#define INF 100000000

using namespace std;


vector<vector<pair<int, int>>> graph;
int dist[501];
bool visit[501][501];
vector<vector<int>> path;
int N, M, S, E, U, V, P;

void init1() {
    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
        for(int j=0; j<=N; j++){
            visit[i][j]=false;
        }
    }
}

void init2() {
    for (int i = 0; i <= N; i++) {
        dist[i] = INF;
    }
}

void sol1() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.push({0, S});
    dist[S] = 0;

    while (!Q.empty()) {

        int d = Q.top().first;
        int now = Q.top().second;

        Q.pop();

        if (dist[now] < d)continue;

        for (auto i: graph[now]) {

            int _d = d + i.second;
            int nxt = i.first;

            if (visit[now][nxt])continue;

            if (_d == dist[nxt]) {
                path[nxt].push_back(now);
            }

            if (_d < dist[nxt]) {
                path[nxt].clear();
                path[nxt].push_back(now);
                dist[nxt] = _d;
                Q.push({_d, nxt});
            }
        }
    }
}

void remove(int cur) {
    for (auto i: path[cur]) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j].first == cur && !visit[i][cur]) {
                visit[i][cur] = true;
                remove(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0)break;
        init1();
        cin >> S >> E;
        graph.resize(N + 1);
        path.resize(N+1);
        for (int i = 0; i < M; i++) {
            cin >> U >> V >> P;
            graph[U].emplace_back(V, P);
        }
        sol1();
        remove(E);
        init2();
        sol1();
        if(dist[E]==INF)cout<<"-1\n";
        else cout << dist[E] << '\n';

        path.clear();
        graph.clear();
    }
}
