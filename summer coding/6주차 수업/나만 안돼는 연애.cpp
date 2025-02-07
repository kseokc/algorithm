//
// Created by 김석찬 on 2022/08/28.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int gender[1001];
int parent[1001];
int N, M, u, v, d, ans, cnt;
char S;

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;

void reset() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

int main() {
    cin >> N >> M;
    reset();
    for (int i = 1; i <= N; i++) {
        cin >> S;
        if (S == 'M')gender[i] = 1;
        else gender[i] = 0;
    }
    for (int i = 1; i <= M; i++) {
        cin >> u >> v >> d;
        Q.push({d, {u, v}});
    }

    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int dis = Q.top().first;
        Q.pop();
        if (gender[x] == gender[y])continue;
        if (find(x) == find(y))continue;
        Union(x, y);
        ans += dis;
        cnt++;
    }
    if(cnt==N-1){
        cout << ans;
    }else{
        cout<<"-1";
    }

}