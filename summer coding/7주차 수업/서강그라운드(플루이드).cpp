//
// Created by 김석찬 on 2022/09/03.
//

//모든 정점에서의 경로를 알고싶기 때문에 벨만포드를 이용해서 문제를 해결한다.
// 인접 행렬을 이용해서 해결한다.
#include<iostream>
#include<vector>

#define Max 101
#define INF 10001

using namespace std;

int n, m, r, t, a, b, l;
int ans, MAX;

int dist[Max][Max];
int item[Max];

void set_dist() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
}


int main() {
    cin >> n >> m >> r;

    set_dist();

    for (int i = 1; i <= n; i++) {
        cin >> t;
        item[i] = t;
    }

    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        dist[a][b] = dist[b][a] = min(dist[a][b], l);
    }

    for (int i = 0; i <= n; i++)dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            MAX = item[i];
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                if (dist[i][j] != INF && i - j != 0 && dist[i][j] <= m) {
                    MAX += item[j];
                }
                ans = max(MAX, ans);
            }
        }
    }
    cout << ans;


}
