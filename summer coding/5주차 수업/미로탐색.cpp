//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
int N, M, number;
string S;
bool arr[100][100];
bool ver[100][100];
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

void bfs(int last_x, int last_y) {
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 1});
    ver[0][0] = true;
    while (!Q.empty()) {
        int x = Q.front().first.second;
        int y = Q.front().first.first;
        int cnt = Q.front().second;
        if (x == last_x && y == last_y) {
            cout << cnt;
            return;
        }
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y - yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N) continue;
            if (!arr[Y][X] || ver[Y][X])continue;
            Q.push({{Y, X}, cnt + 1});
            ver[Y][X] = true;
        }
    }
}

int main() {

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < M; j++) {
            arr[i][j] = (S[j] - '0');
        }
    }

    bfs(M - 1, N - 1);

}