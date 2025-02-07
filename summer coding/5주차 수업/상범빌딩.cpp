//
// Created by 김석찬 on 2022/08/22.
//

#include<iostream>
#include<queue>

using namespace std;
int L, R, C, s_x, s_y, s_z, l_x, l_y, l_z;
string S;
bool vertex[31][31][31];
int build[31][31][31];  // Z,y,x;
int xn[] = {0, 0, 0, 0, -1, 1};
int yn[] = {0, 0, -1, 1, 0, 0};
int zn[] = {-1, 1, 0, 0, 0, 0};

void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{s_z, s_y},
            {s_x, 0}});
    vertex[s_z][s_y][s_x] = true;
    while (!Q.empty()) {
        int x = Q.front().second.first;
        int y = Q.front().first.second;
        int z = Q.front().first.first;
        int cnt = Q.front().second.second;
        Q.pop();
        if (x == l_x && y == l_y && z == l_z) {
            cout << "Escaped in " << cnt << " minute(s)." << '\n';
            return;
        }
        for (int i = 0; i < 6; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            int Z = z + zn[i];
            if (X < 0 || Y < 0 || Z < 0 || X >= C || Y >= R || Z >= L)continue;
            if (vertex[Z][Y][X])continue;
            Q.push({{Z, Y},
                    {X, cnt + 1}});
            vertex[Z][Y][X] = true;
        }
    }
    cout << "Trapped!" << '\n';
    return;
}

void reset() {
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                vertex[i][j][k] = false;
            }
        }
    }
}

int main() {
    while (1) {
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)break;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> S;
                for (int k = 0; k < C; k++) {
                    if (S[k] == 'S') {
                        s_x = k;
                        s_y = j;
                        s_z = i;
                    } else if (S[k] == '#') {
                        vertex[i][j][k] = true;
                    } else if (S[k] == 'E') {
                        l_x = k;
                        l_y = j;
                        l_z = i;
                    }
                }
            }
        }
        bfs();
        reset();
    }

}