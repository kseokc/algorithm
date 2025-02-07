//
// Created by 김석찬 on 2023/07/27.
//

#include<iostream>
#include<queue>

using namespace std;

int T, N, ans;
int map[301][301];
bool check[301][301];


int xn[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int yn[8] = {-1, 1, 0, 0, -1, -1, 1, 1};


int bfs(int a, int b) {
    int result = 0;
    queue<pair<int, int>> Q;
    Q.push({a, b});
    check[b][a] = true;
    result++;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = x + xn[i];
            int yy = y + yn[i];
            if (xx < 0 || xx >= N || yy < 0 || yy >= N)continue;
            if (check[yy][xx] || map[yy][xx] == 9)continue;
            if (map[yy][xx] == 0) {
                Q.push({xx, yy});
            }
            check[yy][xx] = true;
            result++;
        }
    }
    return result;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        char a;
        ans = 0;
        cin >> N;
        int noboom = N * N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> a;
                if (a == '*') {
                    noboom--;
                    map[i][j] = 9;
                    for (int k = 0; k < 8; k++) {
                        if (i + yn[k] < 0 || i + yn[k] >= N || j + xn[k] < 0 || j + xn[k] >= N)continue;
                        if (map[i + yn[k]][j + xn[k]] == 9)continue;
                        map[i + yn[k]][j + xn[k]]++;
                    }
                }
            }
        }


        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 0 && !check[i][j]) {
                    int result = bfs(j, i);
                    ans++;
                    noboom -= result;
                }
            }
        }


        cout << "#" << tc << " " << ans + noboom << "\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                check[i][j] = false;
                map[i][j] = 0;
            }
        }
    }
}