//
// Created by 김석찬 on 2022/08/14.
//

#include<iostream>
#include<vector>

using namespace std;
vector<int> coin;
int dp[10001];
int M, N, value, tc;

int main() {
    cin >> tc;
    for (int i = 0; i < tc; i++) {

        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> value;
            coin.push_back(value);
        }

        cin >> M;
        dp[0] = 1;

        for (int j = 0; j < coin.size(); j++) {
            for (int k = coin[j]; k <= M; k++) {
                dp[k] = dp[k] + dp[k - coin[j]];
            }
        }

        cout << dp[M] << '\n';
        coin.clear();
        for (int j = 0; j <= M; j++) {
            dp[j] = 0;
        }
    }
}