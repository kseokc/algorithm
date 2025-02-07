//
// Created by 김석찬 on 2022/10/04.
//

// dfs를 이용해서 확인한다 . 뒤쪽 방향이 벽인 경우에는 작동을 종료한다.

#include<iostream>
#include<queue>

using namespace std;

int xn[] = {0, -1, 0, 1}; // 북, 서, 남, 동
int yn[] = {-1, 0, 1, 0};

int N, M, r, c, d, wall; //d:0 북쪽 , 1: 동 , 2, 남, 3 서
bool visit[51][51];
int MAP[51][51];
int dir[] = {0, 3, 2, 1};

int dfs() {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{c,      r},
            {dir[d], 1}});
    visit[r][c] = true;
    while (!Q.empty()) {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int dic = Q.front().second.first;
        int count = Q.front().second.second;
        Q.pop();
        bool can = true;

        for (int i = 1; i <= 4; i++) {
            int X = x + xn[(dic + i) % 4];
            int Y = y + yn[(dic + i) % 4];
            if (X <= 0 || X >= M - 1 || Y <= 0 || Y >= N - 1 || MAP[Y][X] == 1 || visit[Y][X])continue;
            Q.push({{X,             Y},
                    {(dic + i) % 4, count + 1}});
            visit[Y][X] = true;
            can = false;
            break;
        }

        if (can) {
            int X = x + xn[(dic + 2) % 4];
            int Y = y + yn[(dic + 2) % 4];
            if (MAP[Y][X] == 1 || Y <= 0 || X <= 0 || Y >= N - 1 || X >= M - 1) {
                return count;
            } else {
                if (visit[Y][X]) {
                    Q.push({{X,   Y},
                            {dic, count}});
                } else {
                    Q.push({{X,   Y},
                            {dic, count + 1}});
                    visit[Y][X] = true;
                }
            }
        }
    }

}

int main() {
    cin >> N >> M >> r >> c >> d;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> wall;
            MAP[i][j] = wall;
        }
    }
    cout << dfs();
}