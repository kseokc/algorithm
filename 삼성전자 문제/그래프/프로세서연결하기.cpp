//
// Created by 김석찬 on 2023/07/27.
//

#include <iostream>
#include<vector>

using namespace std;

int map[13][13];
int check[13][13];
vector<pair<int, int>> v;
int ans = 10000000;
int max_core;
pair<int, int> xy[4] = {{0,  -1},
                        {1,  0},
                        {0,  1},
                        {-1, 0}};


int T, N;


void solve(int num, int cnt, int length) {
    if (num == v.size()) {
        if (cnt > max_core) {
            ans = length;
            max_core = cnt;
        } else if (cnt == max_core) {
            ans = min(ans, length);
        }
        return;
    }

    for (int i = 0; i < 4; i++) {// 4방향으로 꼽는것
        int x = v[num].first;
        int y = v[num].second;

        int count = 0;
        bool ok = true;

        while (1) {
            x = x + xy[i].first;
            y = y + xy[i].second;
            if (y < 0 || y >= N || x < 0 || x >= N)break;
            if (map[y][x] == 2 || map[y][x] == 1) {
                ok = false;
                break;
            }
        }

        x = v[num].first;
        y = v[num].second;

        if (ok) {
            while (1) {
                x = x + xy[i].first;
                y = y + xy[i].second;
                if (y < 0 || y >= N || x < 0 || x >= N)break;
                map[y][x] = 2;
                count++;
            }
            solve(num + 1, cnt + 1, length + count);
            x = v[num].first;
            y = v[num].second;
            while (1) {
                x = x + xy[i].first;
                y = y + xy[i].second;
                if (y < 0 || y >= N || x < 0 || x >= N)break;
                map[y][x] = 0;
            }
        }
    }
    solve(num + 1, cnt, length);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        v.clear();
        max_core = 0;
        ans = 987654321;

        cin >> N;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (i == 0 || j == 0 || i == N - 1 || j == N - 1)continue;
                if (map[i][j] == 1)v.emplace_back(j, i);
            }
        }

        solve(0, 0, 0);
        cout << '#' << tc << " " << ans << '\n';
    }
}

