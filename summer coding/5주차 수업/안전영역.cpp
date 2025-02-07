//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>

using namespace std;
int rain[100][100];
bool vertex[100][100];
bool graph[100][100];
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};
int height, N, Max_h, Max_cnt;

void dfs(int start_y, int start_x) {
    vertex[start_y][start_x] = true;
    for (int i = 0; i < 4; i++) {
        int X = start_x + xn[i];
        int Y = start_y + yn[i];
        if (X < 0 || Y < 0 || X >= N || Y >= N)continue;
        if (!graph[Y][X] || vertex[Y][X])continue;
        dfs(Y, X);
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
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height;
            rain[i][j] = height;
            Max_h = max(Max_h, height);
        }
    }

    for (int i = 0; i <= Max_h; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (rain[j][k] - i <= 0)graph[j][k] = false;
                else graph[j][k] = true;
            }
        }

        int cnt = 0;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (!graph[j][k] || vertex[j][k])continue;
                dfs(j, k);
                cnt++;
            }
        }

        Max_cnt = max(Max_cnt, cnt);
        reset();
    }

    cout << Max_cnt;
}