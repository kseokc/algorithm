//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<queue>

using namespace std;
int ck[300][300];
bool vertex[300][300];
int xn[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int yn[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int tc, N, cur_x, cur_y, last_x, last_y;

int bfs(int l_y, int l_x) {
    queue<pair<int, pair<int, int>>> Q;
    Q.push({0, {cur_x, cur_y}});
    vertex[cur_y][cur_x] = true;
    while (!Q.empty()) {
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        int cnt = Q.front().first;
        Q.pop();
        if (x == l_x && y == l_y)return cnt;
        for (int i = 0; i < 8; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= N || Y >= N)continue;
            if (vertex[Y][X])continue;
            Q.push({cnt + 1, {X, Y}});
            vertex[Y][X] = true;
        }
    }
}

void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vertex[i][j] = false;
        }
    }
}

int main() {
    cin >> tc;
    while (tc--) {
        cin >> N;
        cin >> cur_x >> cur_y >> last_x >> last_y;
        cout << bfs(last_y, last_x) << '\n';
        reset();
    }
}