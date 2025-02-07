//
// Created by 김석찬 on 2022/08/22.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int N, M, Max;
string S;
bool vertex[50][50];
bool vertex_1[50][50];
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int bfs(int s_x, int s_y) {
    int cnt = 0;
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{s_x, s_y}, 0});
    vertex[s_y][s_x] = true;
    while (!Q.empty()) {
        cnt = Q.front().second;
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (vertex[Y][X])continue;
            Q.push({{X, Y}, cnt + 1});
            vertex[Y][X] = true;
        }
    }
    return cnt;
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vertex_1[i][j])vertex[i][j] = true;
            else vertex[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == 'W') {
                vertex_1[i][j] = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            reset();
            if (vertex[i][j])continue;
            Max = max(Max, bfs(j, i));
        }
    }

    cout << Max;
}