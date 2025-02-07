//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;
bool vertex[1000][1000];
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};
vector<pair<int, int>> arr;
queue<pair<int, pair<int, int>>> Q;
int N, M, tomato, can_tomato, cnt, c;

void bfs() {

    for (int i = 0; i < arr.size(); i++) {
        Q.push({0, {arr[i].first, arr[i].second}});
        vertex[arr[i].first][arr[i].second] = true;
        c++;
    }

    while (!Q.empty()) {
        int x = Q.front().second.second;
        int y = Q.front().second.first;
        cnt = Q.front().first;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (vertex[Y][X])continue;
            vertex[Y][X] = true;
            Q.push({cnt + 1, {Y, X}});
            c++;
        }
    }
}

bool availble() {
    return (c == can_tomato);
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato;
            if (tomato == 1)arr.emplace_back(i, j);

            if (tomato != -1) can_tomato++;
            else vertex[i][j] = true;
        }
    }

    bfs();
    if (availble())cout << cnt;
    else cout << -1;
}