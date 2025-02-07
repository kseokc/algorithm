//
// Created by 김석찬 on 2022/08/14.
//

#include<iostream>

using namespace std;
int dp[1002];
int arr[1002];
int N, number, tc;

int main() {
    cin >> tc;
    while (tc--) {
        cin >> N;
        int Max = -10000000;
        for (int i = 1; i <= N; i++) {
            cin >> number;
            arr[i] = number;
        }
        for (int i = 1; i <= N; i++) {
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
            Max = max(Max, dp[i]);
        }

        cout << Max << '\n';

        for (int i = 1; i <= N; i++) {
            arr[i] = 0;
            dp[i] = 0;
        }
    }
}