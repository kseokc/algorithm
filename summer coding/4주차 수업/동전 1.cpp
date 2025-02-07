//
// Created by 김석찬 on 2022/08/13.
//

#include<iostream>
#include<vector>

#define Max 10001
using namespace std;
int dp[Max];
vector<int> money;
int N, k, won;

int main() {
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        cin >> won;
        money.push_back(won);
    }
    dp[0] = 1;
    for (int i = 0; i < money.size(); i++) {
        for (int j = money[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - money[i]];
        }
    }

    cout << dp[k];
}