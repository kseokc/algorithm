//
// Created by 김석찬 on 2023/02/05.
//

#include<iostream>
#include<cstring>
#define INF 900000000
using namespace std;

int N, town;

int map[17][17];
int curmap[17][1 << 17];

int dfs(int cur_bit, int first) {
    if (cur_bit == town) {
        if (map[first][0] == 0)return INF;
        return map[first][0];
    }

    if(curmap[first][cur_bit] != -1) return curmap[first][cur_bit];
    curmap[first][cur_bit] = INF;

    for (int i = 0; i < N; i++) {
        if (map[first][i] == 0)continue;
        if (cur_bit & 1 << i)continue;
        curmap[first][cur_bit] = min(curmap[first][cur_bit], map[first][i] + dfs(cur_bit | (1 << i), i));
    }
    return curmap[first][cur_bit];
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

}


void solve() {
    input();
    memset(curmap,-1,sizeof(curmap));
    town = (1 << N) - 1;
    cout << dfs(1, 0) << '\n';
}

int main() {
    solve();
}