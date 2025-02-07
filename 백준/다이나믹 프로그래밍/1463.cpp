//
// Created by 김석찬 on 2022/10/26.
//

#include<iostream>

#define MAX 10000000
using namespace std;
int dp[MAX];
int N;

int main() {
    cin >> N;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[N];
}