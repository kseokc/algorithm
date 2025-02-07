//
// Created by 김석찬 on 2023/11/25.
//

#include <iostream>
#include <vector>

#define MOD 10007
using namespace std;

int solution(int n, vector<int> tops) {
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= 1; ++j) {
            if (tops[i] == 0) { //없을때
                if (j == 0) {
                    dp[i][j] = ((dp[i + 1][0] * 2 % MOD) + dp[i + 1][1]) % MOD;
                } else {
                    dp[i][j] = ((dp[i + 1][0] % MOD) + dp[i + 1][1]) % MOD;
                }
            } else {
                if (j == 0) {
                    dp[i][j] = ((dp[i + 1][0] * 3 % MOD) + dp[i + 1][1]) % MOD;
                } else {
                    dp[i][j] = ((dp[i + 1][0] * 2 % MOD) + dp[i + 1][1]) % MOD;
                }
            }
        }
    }
    int answer = dp[0][0];
    return answer;
}