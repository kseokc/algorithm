#include<iostream>
#include<queue>

using namespace std;

int N, M;
int total;
int map[51][51];
int visit[51][51];
queue<pair<int, int>> q;
pair<int, int> dis[8] = {{-1, 0},
                         {-1, -1},
                         {0,  -1},
                         {1,  -1},
                         {1,  0},
                         {1,  1},
                         {0,  1},
                         {-1, 1}};
pair<int, int> waterplus[4] = {{-1, -1},
                               {1,  -1},
                               {1,  1},
                               {-1, 1}}; // 물복사 능력에 의한 방향
int main() {
    // 구름이 이동해서 물의 양을 늘려주고 2이이상이 되면 물이 -2되고 구름이 사라진 자리가 아니라면 구름이 생긴다.
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    //(N, 1), (N, 2), (N-1, 1), (N-1, 2)
    q.push({0, N - 1});
    q.push({1, N - 1});
    q.push({0, N - 2});
    q.push({1, N - 2});
    int d, s;
    int cnt = 1;
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        int qSize = q.size();
        for (int j = 0; j < qSize; j++) {
            int xx = (q.front().first + s * (dis[d - 1].first) + s * N) % N;
            int yy = (q.front().second + s * (dis[d - 1].second) + s * N) % N;
            q.pop();
            q.push({xx, yy});
            map[yy][xx] += 1;
            visit[yy][xx] = i + 1;
        }
        qSize = q.size();
        for (int j = 0; j < qSize; j++) {
            int count = 4;
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int xx = waterplus[k].first + x;
                int yy = waterplus[k].second + y;
                if (xx < 0 || yy < 0 || xx >= N || yy >= N || map[yy][xx] == 0)count--;
            }
            map[y][x] += count;
            q.push({x, y});
        }
        while (!q.empty())q.pop();
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] >= 2 && visit[j][k] != cnt) {
                    map[j][k] -= 2;
                    q.push({k, j});
                }
            }

        }
        cnt++;
    }
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            total += map[j][k];
        }
    }
    cout << total;
}