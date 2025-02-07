//
// Created by 김석찬 on 2023/01/05.
//

#include<iostream>
#include<vector>

#define Maxtime 10001
#define Maxsubject 102
using namespace std;

int subjectnumber;
int total_time;

int score[Maxtime];
vector<pair<int, int>> my;

int dp[Maxsubject][Maxtime];

void sol() {
    for (int i = 1; i <= subjectnumber; i++) {
        int s_time = my[i].first;
        int s_score = my[i].second;
        for (int j = 0; j <= total_time; j++) {
            if (s_time > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s_time] + s_score);
        }
    }
}

void input() {
    cin >> subjectnumber >> total_time;
    my.emplace_back(0, 0);
    for (int i = 0; i < subjectnumber; i++) {
        int a, b;  //공부시간, 얻을수있는 점수
        cin >> a >> b;
        my.emplace_back(a, b);
    }
}

int main() {
    input();
    sol();
    cout << dp[subjectnumber][total_time];
}
