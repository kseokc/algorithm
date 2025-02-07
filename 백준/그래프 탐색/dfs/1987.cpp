//
// Created by 김석찬 on 2023/06/28.
//

#include<iostream>

using namespace std;

int R, C, ans;
char board[20][20];
bool visit[26];


int xn[] = {0, 0, 1, -1};
int yn[] = {-1, 1, 0, 0};

void dfs(int x, int y, int cnt) {
    ans = max(cnt, ans);
    for (int i = 0; i < 4; i++) {
        int nxt_x = x + xn[i];
        int nxt_y = y + yn[i];
        if (nxt_x < 0 || nxt_y < 0 || nxt_x >= C || nxt_y >= R)continue;
        if (visit[board[nxt_y][nxt_x] - 'A'])continue;
        visit[board[nxt_y][nxt_x] - 'A'] = true;
        dfs(nxt_x, nxt_y, cnt + 1);
        visit[board[nxt_y][nxt_x] - 'A'] = false;
    }
}

void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            board[i][j] = s[j];
        }
    }
    visit[board[0][0] - 'A'] = true;
}

int main() {
    input();
    dfs(0, 0, 0);
    cout << ans + 1;

}