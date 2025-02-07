//
// Created by 김석찬 on 2022/08/13.
//

#include<iostream>
#include<algorithm>

#define Max 17
using namespace std;
int dp[Max];
int T[Max];
int p, t, day, MAX;

int main() {
    cin >> day;
    for (int i = 1; i < day + 1; i++) {
        cin >> t >> p;
        if (i + t > day + 1)continue;
        for (int j = i + t; j <= day + 1; j++) {
            dp[j] = max(dp[j], dp[i] + p);
        }
    }
    sort(dp, dp + Max, greater<int>());
    cout << dp[0];
}