//
// Created by 김석찬 on 2024/01/28.
//

// 가장 가까우면 가장 위에 그리고 가장왼쪽에 있는 물고기를 먹는
//자신과 같은 크기의 물고기를 먹으면 크기가 1이 증가한다.

// 다 먹으면 다시 그 물고기 수만큼 먹어야하는것 같

#include <iostream>
#include <queue>

using namespace std;

int fish[21][21];
bool visit[21][21];
int N, ans;
pair<int, int> start;
pair<int, int> Size = {2, 0};
bool ok = false;
int xn[4] = {0, -1, 1, 0};
int yn[4] = {-1, 0, 0, 1};
queue<pair<int, pair<int, int>>> Q;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> fish[i][j];
            if (ok == false && fish[i][j] < 2)ok = true;
            if (fish[i][j] == 9) {
                fish[i][j] = 0;
                start = {j, i};
            }
        }
    }

}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visit[i][j] = false;
        }
    }
    while (!Q.empty()) {
        Q.pop();
    }

}

void sol() {
    Q.push({0, {start.first, start.second}});
    visit[start.second][start.first] = true;
    while (!Q.empty()) {
        int cnt = Q.front().first;
        int x = Q.front().second.first;
        int y = Q.front().second.second;
        Q.pop();
        if (fish[y][x] != 0 && fish[y][x] < Size.first) {
            int x_sol = x;
            int y_sol = y;
            while (!Q.empty()) {
                if (fish[Q.front().second.second][Q.front().second.first] != 0
                    && cnt == Q.front().first && fish[Q.front().second.second][Q.front().second.first] < Size.first) {
                    if (y_sol > Q.front().second.second) {
                        y_sol = Q.front().second.second;
                        x_sol = Q.front().second.first;
                    } else if (y_sol == Q.front().second.second && x_sol > Q.front().second.first) {
                        y_sol = Q.front().second.second;
                        x_sol = Q.front().second.first;
                    }
                }
                Q.pop();
            }
            Size.second++;
            ans += cnt;
            cnt=0;
            fish[y_sol][x_sol] = 0;
            x=x_sol;
            y=y_sol;
            init();
            Q.push({0, {x_sol, y_sol}});
            visit[y_sol][x_sol] = true;
            if (Size.first == Size.second) {
                Size.second = 0;
                Size.first += 1;
            }
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + xn[i];
            int yy = y + yn[i];
            if (visit[yy][xx] || xx >= N || yy >= N || xx < 0 || yy < 0)continue;
            if (fish[yy][xx] == Size.first || fish[yy][xx] == 0) { // 자리만 지나갈때
                Q.push({cnt + 1, {xx, yy}});
                visit[yy][xx] = true;
            } else if (fish[yy][xx] < Size.first) { // 물고기를 먹고 지나갈때
                Q.push({cnt + 1, {xx, yy}});
                visit[yy][xx] = true;
            }
        }
    }
}

int main() {
    input();
    if (!ok)return 0;
    sol();
    if (Size.first == 2 && Size.second == 0) {
        cout << 0;
    } else {
        cout << ans;
    }
}