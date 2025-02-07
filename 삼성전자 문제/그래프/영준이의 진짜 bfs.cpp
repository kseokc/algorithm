#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int T, N;
vector<int> path;
vector<vector<int>> graph;
bool visit[100001];
int visit2[100001];

void bfs1() {
    queue<int> Q;
    Q.push(1);
    path.push_back(1);
    visit[1] = true;
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (auto i: graph[cur]) {
            if (visit[i])continue;
            Q.push(i);
            visit[i] = true;
            path.push_back(i);
        }
    }
}

int bfs2(int start, int end) {
    queue<pair<int, int>> Q;
    Q.push({start, 0});
    visit2[start] = start;
    while (!Q.empty()) {
        int cnt = Q.front().second;
        int cur = Q.front().first;
        if (end == cur)return cnt;
        Q.pop();
        for (auto i: graph[cur]) {
            if (visit2[i] == start)continue;
            Q.push({i, cnt + 1});
            visit2[i] = start;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        graph.resize(N + 1);
        int parent;
        for (int i = 2; i <= N; i++) {
            cin >> parent;
            graph[i].push_back(parent);
            graph[parent].push_back(i);
        }

        bfs1();

        int result = 0;

        for (int i = 1; i < N; i++) {
            result += bfs2(path[i - 1], path[i]);
        }

        cout << "#" << tc << " " << result << '\n';

        graph.clear();
        path.clear();
        memset(visit2, 0, sizeof(visit2));
        memset(visit, false, sizeof(visit));
    }

}