//
// Created by 김석찬 on 2022/08/17.
//
#include<iostream>

using namespace std;
int dp[1001];
int arr[1001];
int N, number, MAX;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> number;
        arr[i] = number;
    }
    for (int i = 1; i <= N; i++) {
        int Max = 0;
        for (int j = 1; j < i; j++) {
            if (arr[j] < arr[i]) {
                Max = max(Max, dp[j]);
            }
        }
        dp[i] = Max + 1;
        MAX = max(MAX, dp[i]);
    }
    cout << MAX;
}
