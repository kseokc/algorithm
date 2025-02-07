//
// Created by 김석찬 on 2025/01/15.
//

#include<iostream>
#include<vector>
#include <queue>
#include "cmath"
#include "algorithm"
#include <map>

#define INF 987654321
using namespace std;

int N, M;
int arr[11][11];

bool visit[11][11];
int test[11][11];
int chk[11][11];
vector<vector<pair<int, int>>> v;

int xn[4] = {0, 0, -1, 1};
int YYn[4] = {-1, 1, 0, 0};

int result[7][7];
int parent[7];

void init() {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            result[i][j] = INF;
        }
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    parent[y] = x;
}


void bfs(int a, int b, int cnt) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visit[b][a] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + xn[i];
            int yy = y + YYn[i];
            if (xx < 0 || yy < 0 || xx >= M || yy >= N)continue;
            if (visit[yy][xx])continue;
            arr[y][x] = cnt;
            if (arr[yy][xx] == 0) {
                v[cnt].push_back({x, y});
                continue;
            }
            q.push({xx, yy});
            visit[yy][xx] = true;
        }
    }
}

void sol(int cnt) {
    for (int j = 0; j < v[cnt].size(); j++) {
        for (int i = 0; i < 4; i++) {
            int x = v[cnt][j].first;
            int y = v[cnt][j].second;
            int a = 0;
            while (1) {
                x = x + xn[i];
                y = y + YYn[i];
                if (x < 0 || y < 0 || x >= M || y >= N)break;
                if (arr[y][x] == cnt)break;
                if (arr[y][x] != cnt && arr[y][x] != 0) {
                    if (a >= result[cnt][arr[y][x]] || a<2)break;
                    result[cnt][arr[y][x]] = a;
                    break;
                }
                a++;
            }
        }
    }
}

int main() {
    cin >> N >> M;
    init();
    v.resize(7);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visit[i][j] || arr[i][j] == 0)continue;
            bfs(j, i, cnt);
            cnt++;
        }
    }


    for (int i = 1; i < cnt; i++) {
        sol(i);
    }

    vector<pair<int, pair<int, int>>> ans;

    for (int i = 1; i < cnt; i++) {
        for (int j = 1; j < cnt; j++) {
            if (result[i][j] == INF)continue;
            ans.push_back({result[i][j], {i, j}});
        }
    }

    sort(ans.begin(), ans.end());
    int cost = 0;
    int num=0;
    for (int i = 0; i < ans.size(); i++) {
        if (find(ans[i].second.first) == find(ans[i].second.second))continue;
        Union(ans[i].second.first, ans[i].second.second);
        num+=1;
        cost += ans[i].first;
    }

    if(num<cnt-2)cout<<-1;
    else cout<<cost;

}