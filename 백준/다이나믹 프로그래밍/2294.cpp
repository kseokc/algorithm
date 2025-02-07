//
// Created by 김석찬 on 2022/11/01.
//

#include<iostream>
#include<vector>

using namespace std;
vector<int> v;
int dp[10001];
int k, n, value;

void set_dp(int size) {
    for (int i = 1; i <= size; i++) {
        dp[i] = 1000001;
    }
}

int main() {
    dp[0] = 0;
    cin >> n >> k;
    set_dp(k);
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
    for (int j = 0; j < v.size(); j++) {
        for (int i = v[j]; i <= k; i++) {
            dp[i] = min(dp[i], dp[i - v[j]] + 1);
        }
    }

    if (dp[k] == 1000001 ? cout << -1 : cout << dp[k]);
}
