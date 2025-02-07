//
// Created by 김석찬 on 2022/09/03.
//

#include<iostream>

#define Max 101
#define INF 10000001
using namespace std;

int dist[Max][Max];

int n, m, a, b, c;

void set_dist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
}

int main() {
    cin >> n >> m;

    set_dist();

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(c, dist[a][b]);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF || i == j)cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
}