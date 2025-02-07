//
// Created by 김석찬 on 2022/08/27.
//



#include<iostream>
#include<vector>
#include<queue>



#define Max 1001
using namespace std;

priority_queue<int,vector<int>,greater<int>>q;


int f(int x, int y){
    int mod=x%y;
    if(mod==0){
        return y;
    }
    f(y,mod);
}

int parent[Max];
int N, M, v_1, v_2, K, cnt, ans;
vector<pair<int, pair<int, int>>> v;

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

void reset() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        cin >> v_1 >> v_2;
        v.push_back({i, {v_1, v_2}});
    }
    int count = 0;
    while (K != count) {
        reset();
        cnt = 0;
        ans = 0;
        for (int i = count; i < v.size(); i++) {
            int x = v[i].second.first;
            int y = v[i].second.second;
            int value = v[i].first;
            if (find(x) == find(y))continue;
            Union(x, y);
            cnt++;
            ans += value;
        }
        if (cnt == N - 1) {
            cout << ans << " ";
        } else {
            cout << "0 ";
        }
        count++;
    }
}