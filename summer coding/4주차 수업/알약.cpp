//
// Created by 김석찬 on 2022/08/17.
//

#include<iostream>

using namespace std;
long long N;
long long dp[31][31];

int main() {

    while (1) {
        cin >> N;
        dp[0][1] = 1;
        dp[0][0] = 1;
        if (N == 0)break;

        for (long long i = 1; i <= N; i++) {
            for (long long j = 0; j <= i; j++) {
                if (j - 1 < 0) {
                    dp[j][i] = dp[j][i - 1];
                } else if (j - 1 > i) {
                    dp[j][i] = dp[j - 1][i];
                } else {
                    dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
                }
            }
        }

        cout << dp[N][N] << '\n';

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                dp[i][j] = 0;
            }
        }
    }
}