//
// Created by 김석찬 on 2022/08/23.
//

#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int Map[101][101];
bool visit[101][101];
bool number[100];
int N, num;
int c = 1;
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

void bfs(int s_x, int s_y) {
    queue<pair<int, int>> Q;
    Q.push({s_x, s_y});
    visit[s_y][s_x] = true;
    Map[s_y][s_x] = c;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= N || y >= N || visit[Y][X])continue;
            if (Map[Y][X] == 0)continue;
            visit[Y][X] = true;
            Q.push({X, Y});
            Map[Y][X] = c;
        }
    }
    c++;
}

int bfs_1(int s_x, int s_y, int t) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> Q;
    Q.push({0, {s_x, s_y}});
    visit[s_y][s_x] = true;
    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int cnt = Q.top().first;
        Q.pop();
        if (Map[y][x] != 0 && Map[y][x] != t) {
            return cnt;
        }
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= N || Y >= N)continue;
            if (visit[Y][X])continue;
            if (Map[Y][X] == 0) {
                visit[Y][X] = true;
                Q.push({cnt + 1, {X, Y}});
            } else {
                visit[Y][X] = true;
                Q.push({cnt, {X, Y}});
            }
        }
    }
}

void reset() {
    memset(visit, 0, sizeof(visit));
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            Map[i][j] = num;
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] || Map[i][j] == 0)continue;
            bfs(j, i);
        }
    }

    reset();

    int Min = 201;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Map[i][j] == 0)continue;
            if (number[Map[i][j]])continue;
            number[Map[i][j]] = true;
            Min = min(Min, bfs_1(j, i, Map[i][j]));
            reset();
        }
    }
    cout << Min;
}