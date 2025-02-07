//
// Created by 김석찬 on 2023/08/02.
//

//모든 도시를 연결하는 고속도로를 만들려고한다.
//최소 비용을 이용해서 연결을 하고싶어한다.
//어떤 도시끼리는 직접이을수 없을수있다.


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, T, M, s, e, c;
int parent[50001];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> Q;


void reset() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int Find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int xx = Find(x);
    int yy = Find(y);
    if (xx == yy)return;
    parent[yy] = xx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> c;
            Q.push({c, {s, e}});
        }
        reset();
        long long ans = 0;
        while (!Q.empty()) {
            long long dis = Q.top().first;
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            Q.pop();
            if (Find(x) == Find(y))continue;
            Union(x, y);
            ans += dis;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}