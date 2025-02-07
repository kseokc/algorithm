//
// Created by 김석찬 on 2022/08/16.
//

#include<iostream>

using namespace std;

long long dp[101][21];
long long arr[100];
long long N, number;

int main() {
    cin >> N;

    for (int i = 1; i < N + 1; i++) {
        cin >> number;
        arr[i] = number;
    }

    dp[1][arr[1]] = 1;

    for (int i = 2; i < N; i++) {
        for (int j = 0; j < 21; j++) {
            if (dp[i - 1][j] == 0)continue;
            if (j + arr[i] > 20) {
                dp[i][j - arr[i]] = dp[i][j - arr[i]] + dp[i - 1][j];
            } else if (j - arr[i] < 0) {
                dp[i][j + arr[i]] = dp[i][j + arr[i]] + dp[i - 1][j];
            } else {
                dp[i][j - arr[i]] = dp[i][j - arr[i]] + dp[i - 1][j];
                dp[i][j + arr[i]] = dp[i][j + arr[i]] + dp[i - 1][j];
            }
        }
    }

    cout << dp[N - 1][arr[N]];

}