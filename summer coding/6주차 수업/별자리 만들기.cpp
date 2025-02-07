//
// Created by 김석찬 on 2022/08/28.
//

#include<iostream>
#include<queue>
#include<vector>
#include<cmath>

using namespace std;

priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> Q;
vector<pair<int, pair<double, double>>> arr;
vector<pair<int, pair<double, double>>> INput;
int n;
double a, b, ans;
int parent[101];

int find(int x) {
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

void sol(int k) {
    if (arr.size() == 2) {
        Q.push({sqrt(pow(arr[0].second.first - arr[1].second.first, 2)
                     + pow(arr[0].second.second - arr[1].second.second, 2)), {arr[0].first, arr[1].first}});
        return;
    }
    if (k >= n)return;
    else {
        arr.push_back({INput[k].first, {INput[k].second.first, INput[k].second.second}});
        sol(k + 1);
        arr.pop_back();
        sol(k + 1);
    }
}

void reset() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        INput.push_back({i + 1, {a, b}});
    }
    sol(0);
    reset();
    while (!Q.empty()) {
        double dis = Q.top().first;
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        Q.pop();
        if (find(x) == find(y))continue;
        Union(x, y);
        ans += dis;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
}