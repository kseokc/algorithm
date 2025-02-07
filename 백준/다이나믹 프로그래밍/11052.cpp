//
// Created by 김석찬 on 2022/11/03.
//

#include<iostream>
#include<vector>

#define MAX 10000001
using namespace std;

int dp[MAX];
int N, p;
vector<int> v;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p;
        v.push_back(p);
    }
}

void sol() {
    for (int i = 1; i <= v.size(); i++) {
        for (int j = i; j <= N; j++) {
            dp[j] = max(dp[j], dp[j - i] + v[i - 1]);
        }
    }
}

int main() {
    input();
    sol();
    cout << dp[N];
}