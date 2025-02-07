//
// Created by 김석찬 on 2022/11/17.
//

#include<iostream>
#include<queue>

using namespace std;
int x, y;
bool visit[100001];

int dfs(int goal) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    Q.push({0, x});
    visit[x] = true;

    while (!Q.empty()) {
        int cnt = Q.top().first;
        int number = Q.top().second;
        if (number == goal)return cnt;
        Q.pop();
        int go[] = {1, -1, number};
        for (int i = 0; i < 3; i++) {
            int num = number + go[i];
            if (num > 100000 || num < 0 || visit[num])continue;
            visit[num]=true;
            Q.push({cnt + 1, num});

        }
    }
}

int main() {
    cin >> x >> y;
    cout << dfs(y);
}