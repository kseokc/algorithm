//
// Created by 김석찬 on 2022/10/26.
//

#include<iostream>

#define MAX 1001
using namespace std;

int N;
int dp[MAX][3];
int in[MAX][3];
int result = 1000001;

void sol() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = in[i][j] + min(dp[i - 1][(j + 1) % 3], dp[i - 1][((j + 2) % 3)]);
        }
    }

    for (int i = 0; i < 3; i++) {
        result = min(dp[N][i], result);
    }
}

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> in[i][j];
        }
    }
}

int main() {
    input();
    sol();
    cout << result;
}