//
// Created by 김석찬 on 2023/02/01.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int N, M;
char map[11][11];
bool visit[11][11][11][11];

void move(int &RX, int &RY, int &dis, int &i) {
    while (map[RY + yn[i]][RX + xn[i]] != '#' && map[RY][RX] != 'O') {
        RX += xn[i];
        RY += yn[i];
        dis += 1;
    }
}

void bfs(int r_x, int r_y, int b_x, int b_y) {
    queue<pair<int, pair<pair<int, int>,pair<int,int>>>> Q;
    Q.push({0, {{r_x, r_y}, {b_x, b_y}}});
    visit[r_y][r_x][b_y][b_x] = true;
    while (!Q.empty()) {
        int rx = Q.front().second.first.first;
        int ry = Q.front().second.first.second;
        int bx = Q.front().second.second.first;
        int by = Q.front().second.second.second;
        int cnt = Q.front().first;
        Q.pop();
        if (cnt >= 10)break;
        for (int i = 0; i < 4; i++) {
            int nrx,nry,nbx,nby,rc, bc;
            nrx=rx;
            nry=ry;
            nbx=bx;
            nby=by;
            rc=0,bc=0;
            move(nrx, nry, rc, i);
            move(nbx, nby, bc, i);
//            cout<<nrx<<" " <<nry<<'\n';
            if (map[nby][nbx] == 'O')continue;
            if (map[nry][nrx] == 'O') {
                cout<<cnt + 1;
                return;
            }
            if (nrx == nbx && nry == nby) {
                if (bc > rc) {
                    nbx -= xn[i];
                    nby -= yn[i];
                } else {
                    nrx -= xn[i];
                    nry -= yn[i];
                }
            }
            if (visit[nry][nrx][nby][nbx])continue;
            visit[nry][nrx][nby][nbx] = true;
            Q.push({cnt + 1, {{nrx, nry}, {nbx, nby}}});
        }
    }
    cout<<-1;
}

void sol() {
    int x1, y1, x2, y2;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                x1 = j;
                y1 = i;
            } else if (map[i][j] == 'B') {
                x2 = j;
                y2 = i;
            }
        }
    }

    bfs(x1, y1, x2, y2);

}

int main() {
    sol();
}
