//
// Created by 김석찬 on 2023/08/02.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int T, N;
long long X,Y;
double tex;
int parent[1001];
pair<long long, long long> V[1001];
long long dist[1001][1001];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> Q;

void reset() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        V[i] = {0, 0};
    }
}

int Find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y)return;
    parent[y] = x;
}

void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)dist[i][j] = 0;
            else {
                long long xx = (V[i].first - V[j].first) * (V[i].first - V[j].first);
                long long yy = (V[i].second - V[j].second) * (V[i].second - V[j].second);
                dist[i][j] = xx + yy;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            Q.push({dist[i][j], {j, i}});
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    cout<<fixed;
    cout.precision(0);
    for (int tc = 1; tc <= T; tc++) {

        cin >> N;
        reset();
        for (int i = 1; i <= N; i++) {
            cin >> X;
            V[i].first = X;
        }
        for (int i = 1; i <= N; i++) {
            cin >> Y;
            V[i].second = Y;
        }
        cin >> tex;

        solve();

        double ans = 0.;
        while (!Q.empty()) {
            long long dis = Q.top().first;
            int start = Q.top().second.first;
            int end = Q.top().second.second;
            Q.pop();

            if (Find(start) == Find(end))continue;
            Union(start, end);
            ans += (dis*tex);
        }
        cout << "#" << tc << " " << (ans) << '\n';
    }
}