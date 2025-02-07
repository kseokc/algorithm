//
// Created by 김석찬 on 2022/08/14.
//

#include<iostream>

#define mod 10007
using namespace std;
int N;
int dp[1001];

int main() {
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        for (int j = 1; j <= 2; j++) {
            dp[i] = dp[i] + dp[i - j];
            dp[i] = dp[i] % mod;
        }
    }
    cout << dp[N];
}