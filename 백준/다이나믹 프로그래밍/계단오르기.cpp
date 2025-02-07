//
// Created by 김석찬 on 2023/06/28.
//

#include<iostream>

using namespace std;

int dp[301];
int point[301];

int N;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> point[i];
    }
}

void solve() {
    dp[0] = point[0];
    dp[1] = point[0] + point[1];
    dp[2] = max(point[0] + point[2], point[1] + point[2]);

    for (int i = 3; i < N; i++) {
        dp[i] = max(point[i] + dp[i - 2], point[i] + point[i - 1] + dp[i - 3]);
    }
}

int main() {
    input();
    solve();
    cout << dp[N - 1];
}