//
// Created by 김석찬 on 2022/11/03.
//

#include<iostream>
#include<queue>

using namespace std;

int xn[] = {-1, 1, 0, 0, 0, 0};
int yn[] = {0, 0, -1, 1, 0, 0};
int zn[] = {0, 0, 0, 0, -1, 1};

int M, N, H, all, result;
int tomato[101][101][101];
queue<pair<int, pair<int, pair<int, int>>>> Q;


void input() {
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1)Q.push({0, {i, {j, k}}});
                else if (tomato[i][j][k] == 0) all += 1;
            }
        }
    }
}

void bfs() {
    while (!Q.empty()) {
        int x = Q.front().second.second.second;
        int y = Q.front().second.second.first;
        int z = Q.front().second.first;
        int cnt = Q.front().first;
        Q.pop();
        for (int i = 0; i < 6; i++) {
            int Xn = x + xn[i];
            int Yn = y + yn[i];
            int Zn = z + zn[i];
            if (Zn < 0 || Xn < 0 || Yn < 0 || Zn >= H || Yn >= N || Xn >= M)continue;
            if (tomato[Zn][Yn][Xn] != 0)continue;
            tomato[Zn][Yn][Xn] = 1;
            Q.push({cnt + 1, {Zn, {Yn, Xn}}});
            all--;
            result = max(result, cnt + 1);
        }
    }
}

void sol() {
    if (all == 0)cout << result;
    else cout << "-1";
}


int main() {
    input();
    bfs();
    sol();
}