//
// Created by 김석찬 on 2022/08/23.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M, v, Sum, Max;

bool vertex[8][8];
bool wall[8][8];
bool Vi[8][8];

vector<pair<int, int>> pos;
vector<pair<int, int>> vilous;

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};


int bfs() {
    int cnt = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < 3; i++) {
        vertex[pos[i].first][pos[i].second] = true;
    }

    for (int i = 0; i < vilous.size(); i++) {
        Q.push({vilous[i].first, vilous[i].second});
    }

    while (!Q.empty()) {
        int x = Q.front().second;
        int y = Q.front().first;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (vertex[Y][X] || wall[Y][X] || Vi[Y][X])continue;
            vertex[Y][X] = true;
            Q.push({Y, X});
            cnt++;
        }
    }
    return cnt;
}

void reset() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vertex[i][j] = false;
        }
    }
}


void Sol(int n, int k) {
    if (n == 3) {
        Max = max(Sum - bfs(), Max);
        reset();
        return;
    }
    if (k >= N * M)return;
    if (wall[k / M][k % M] || Vi[k / M][k % M]) {
        Sol(n, k + 1);
    } else {
        pos.emplace_back(k / M, k % M);
        Sol(n + 1, k + 1);
        pos.pop_back();
        Sol(n, k + 1);
    }


}


int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> v;
            if (v == 2 || v == 0) {
                if (v == 2) {
                    vilous.emplace_back(i, j);
                    Vi[i][j] = true;
                } else if (v == 0) {
                    Sum++;
                }
            } else {
                wall[i][j] = true;
            }
        }
    }
    Sol(0, 0);
    cout << Max - 3;
}