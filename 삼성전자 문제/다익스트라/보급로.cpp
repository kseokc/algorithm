//
// Created by 김석찬 on 2023/08/04.
//

#include<iostream>
#include<queue>

#define INF 987654321

using namespace std;

int map[101][101];
int dist[101][101];

pair<int, int> xy[4] = {{1,  0},
                        {-1, 0},
                        {0,  1},
                        {0,  -1}};

int T, N;

void dic() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;
    Q.push({0, {0, 0}});
    dist[0][0] = 0;

    while (!Q.empty()) {
        int d = Q.top().first;
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();
        if (d > dist[y][x])continue;

        if (x == N - 1 && y == N - 1) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + xy[i].first;
            int yy = y + xy[i].second;
            if (xx < 0 || yy < 0 || xx >= N || yy >= N)continue;

            int _d = d + map[yy][xx];
            if (_d < dist[yy][xx]) {
                dist[yy][xx] = _d;
                Q.push({_d, {xx, yy}});
            }
        }
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = INF;
        }
    }
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            for (int j = 0; j < N; j++) {
                map[i][j] = s[j] - '0';
            }
        }
        init();
        dic();
        cout << '#' << tc << ' ' << dist[N - 1][N - 1] << '\n';
    }
}