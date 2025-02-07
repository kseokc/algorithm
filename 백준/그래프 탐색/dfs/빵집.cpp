//
// Created by 김석찬 on 2023/06/28.
//

//오른쪽 오른쪽 대각선 오른쪽 아래 대각선
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int R, C, ans;
int map[10001][501];
bool visit[10001][501];

int xn[3] = {1, 1, 1};
int yn[3] = {-1, 0, 1};

bool dfs(int a, int b) {
    if (a == C - 1) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        int x = a + xn[i];
        int y = b + yn[i];
        if (x < 0 || y < 0 || x >= C || y >= R)continue;
        if (map[y][x] == 0 || visit[y][x])continue;
        visit[y][x] = true;
        if (dfs(x, y))return true;
    }
    return false;
}

void input() {
    cin >> R >> C;
    string s;
    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            if (s[j] == 'x')map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
}


void solve() {
    input();
    for (int i = 0; i < R; i++) {
        if (map[i][0] == 1) {
            if (dfs(0, i))ans++;
        }
    }
}

int main() {
    solve();
    cout << ans;
    return 0;
}