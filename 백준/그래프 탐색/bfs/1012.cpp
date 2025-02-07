//
// Created by 김석찬 on 2022/11/17.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int tc, M, N, K, x, y;
int result;
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int garden[51][51];

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    garden[i][j] = 2;
    while (!Q.empty()) {
        int X = Q.front().second;
        int Y = Q.front().first;
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int Xn = X + xn[k];
            int Yn = Y + yn[k];
            if (Xn < 0 || Yn < 0 || Xn >= M || Yn >= N)continue;
            if (garden[Yn][Xn] == 1) {
                garden[Yn][Xn] = 2;
                Q.push({Yn, Xn});
            }
        }
    }
}

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        garden[y][x] = 1;
    }
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            garden[i][j] = 0;
        }
    }
    result = 0;
}

void sol() {
    cin >> tc;
    while (tc--) {
        input();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (garden[i][j] == 1) {
                    bfs(i, j);
                    result += 1;
                }
            }
        }
        cout << result << '\n';
        reset();
    }
}

int main() {
    sol();
}