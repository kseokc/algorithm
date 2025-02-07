//
// Created by 김석찬 on 2022/08/23.
//

#include<iostream>
#include<queue>

using namespace std;
int N, M;
string S;
bool vertex[1001][1001][2];
bool vertex_1[1001][1001];
bool wall[1001][1001];
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int bfs() {
    queue<pair<pair<int, int>, pair<bool, int>>> Q;
    Q.push({{1,     1},
            {false, 1}}); // {x,y}  {벽을 부셨는지의 여부, 이동한 칸}
    vertex[1][1][0] = true;
    while (!Q.empty()) {
        int x = Q.front().first.second;
        int y = Q.front().first.first;
        int cnt = Q.front().second.second;
        int brk = Q.front().second.first;
        Q.pop();
        if (x == M && y == N)return cnt;
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 1 || Y < 1 || X > M || Y > N)continue;
            if (brk) {
                if (vertex[Y][X][1])continue;
                if (wall[Y][X])continue;
                vertex[Y][X][1] = true;
                Q.push({{Y,   X},
                        {brk, cnt + 1}});
            } else {
                if (vertex[Y][X][0])continue;
                if (wall[Y][X]) {
                    vertex[Y][X][1] = true;
                    Q.push({{Y,    X},
                            {true, cnt + 1}});
                } else {
                    vertex[Y][X][0] = true;
                    Q.push({{Y,   X},
                            {brk, cnt + 1}});
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            if (S[j] == '1')wall[i][j + 1] = true;
        }
    }

    cout << bfs();
}