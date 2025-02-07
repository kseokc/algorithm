//
// Created by 김석찬 on 2022/08/28.
//

#include<iostream>
#include<queue>

using namespace std;
long long parent[100001];
long long N, M, a, b, c, ans, cnt;
priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<>> Q;

void reset() {
    for (long long i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

long long find(long long x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(long long x, long long y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

int main() {
    cin >> N >> M;
    reset();
    for (long long i = 0; i < M; i++) {
        cin >> a >> b >> c;
        ans += c;
        Q.push({c, {a, b}});
    }
    while (!Q.empty()) {
        long long value = Q.top().first;
        long long x = Q.top().second.first;
        long long y = Q.top().second.second;
        Q.pop();
        if (find(x) == find(y))continue;
        Union(x, y);
        ans -= value;
        cnt++;
    }

    if (cnt == N - 1) {
        cout << ans;
    } else {
        cout << "-1";
    }
}
