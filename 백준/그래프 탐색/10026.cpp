//
// Created by 김석찬 on 2022/09/26.
//

#include<iostream>
#include<queue>

#define N 101
using namespace std;

int xn[4] = {0, 0, -1, 1};
int yn[4] = {1, -1, 0, 0};

int MAP[N][N]; // 0 : R, 1 : G, 2: B
bool visit[N][N];
int RGB[4];

string S;
int n;

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = false;
        }
    }
}

void bfs(int i, int j, int k) {
    queue<pair<int, int>> Q;
    Q.push({j, k});
    while (!Q.empty()) {
        int x = Q.front().second;
        int y = Q.front().first;
        Q.pop();
        for (int p = 0; p < 4; p++) {
            int X = x + xn[p];
            int Y = y + yn[p];
            if (X < 0 || X >= n || Y < 0 || Y >= n)continue;
            if (i == 3) {
                if (visit[Y][X] || MAP[Y][X] == 2)continue;
            } else {
                if (visit[Y][X] || MAP[Y][X] != i)continue;
            }
            visit[Y][X] = true;
            Q.push({Y, X});
        }
    }
}

void find() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!visit[j][k]) {
                    if (i == 3) {
                        if (MAP[j][k] != 2) {
                            bfs(i, j, k);
                            RGB[i]++;
                        }
                    } else {
                        if (MAP[j][k] == i) {
                            bfs(i, j, k);
                            RGB[i]++;
                        }
                    }
                }
            }
        }
        reset();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> S;
        for (int j = 0; j < n; j++) {
            if (S[j] == 'R') {
                MAP[i][j] = 0;
            } else if (S[j] == 'G') {
                MAP[i][j] = 1;
            } else {
                MAP[i][j] = 2;
            }
        }
    }

    find();
    cout << RGB[0] + RGB[1] + RGB[2] << " " << RGB[3] + RGB[2];
}