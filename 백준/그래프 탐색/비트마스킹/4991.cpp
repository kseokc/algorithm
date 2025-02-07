//
// Created by 김석찬 on 2023/02/03.
//

#include<iostream>
#include<queue>
#include<cstring>


using namespace std;

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int w, h;
int trash[21][21];
char map[21][21];
bool visit[21][21][1025];

pair<int, int> robot;

int bfs(int cnt) {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{(1 << cnt) - 1, 0},
            {robot.first,    robot.second}});
    visit[robot.second][robot.first][(1 << cnt) - 1] = true;
    while (!Q.empty()) {
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        int curcnt = Q.front().first.first;
        int dist = Q.front().first.second;
        Q.pop();
        if (curcnt == 0)return dist;
        for (int i = 0; i < 4; i++) {
            int xx = x + xn[i];
            int yy = y + yn[i];

            if (xx < 0 || yy < 0 || xx >= w || yy >= h || map[yy][xx] == 'x')continue;

            int nextcnt = curcnt;

                if (curcnt & trash[yy][xx]) nextcnt = (curcnt ^ trash[yy][xx]);

            if (visit[yy][xx][nextcnt])continue;

            Q.push({{nextcnt, dist + 1},
                    {xx,      yy}});

            visit[yy][xx][nextcnt] = true;
        }
    }
    return -1;
}

void sol() {
    while (1) {
        int cnt = 0;
        cin >> w >> h;
        memset(visit, false, sizeof(visit));
        if (w == 0 && h == 0)return;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
                trash[i][j] = 0;
                if (map[i][j] == '*') {
                    trash[i][j] = 1 << cnt;
                    cnt++;
                } else if (map[i][j] == 'o')robot = {j, i};
            }
        }


        cout << bfs(cnt) << '\n';
    }

}

int main() {
    sol();
}