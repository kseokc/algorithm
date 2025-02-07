//
// Created by 김석찬 on 2022/08/14.
//

#include<iostream>

using namespace std;
int dp[502];
int arr[502];
int dp_2[502];
int N, number, Max;

int main() {
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> number;
            arr[j] = number;
        }
        for (int j = 1; j <= i; j++) {
            if (count % 2 == 0) {
                dp[j] = max(dp_2[j - 1], dp_2[j]) + arr[j];
                Max = max(Max, dp[j]);
            } else {
                dp_2[j] = max(dp[j - 1], dp[j]) + arr[j];
                Max = max(Max, dp_2[j]);
            }
        }
        count++;
    }
    cout << Max;
}