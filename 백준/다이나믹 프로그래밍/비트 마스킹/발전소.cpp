//
// Created by 김석찬 on 2023/07/09.
//

//발전소를 고치는 최소값을 구해라
//발전소의 개수 N이 주어진다. 1<=N<=16
//i번째 발전소를 이용해서 j번째의 발전소를 고칠수있다. i번째 줄의 있는 발전
//발전소가 켜저있으면 Y 꺼져있으면 N
//적어도 P개의 발전소가 고장 나있지 않도록 구하는 프로그램을 작성해라 고치는 비용의 최솟값 0<=p<=N
//불가능 한 경우에는 -1을 출력한다.

#include<iostream>

#define MAX 17
using namespace std;

string cmd;
int N, P;
int first;
int arr[MAX][MAX];
int dp[(1 << 16) - 1];

void init() {
    fill(dp, dp + ((1 << 16) - 1), 100000000);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)cin >> arr[i][j];
    }
    cin >> cmd >> P;
}

int count(int x) {
    int count = 0;
    while (x != 0) {
        if (x & 1)count++;
        x /= 2;
    }
    return count;
}


int dfs(int bit) {
    if (count(bit) == P) {
        return 0;
    }
    if (dp[bit] != 100000000)return dp[bit];

    for (int i = 0; i < N; i++) {
        if ((bit & 1 << i) == 0)continue;
        for (int j = 0; j < N; j++) {
            if ((bit & 1 << j) == 0) {
                dp[bit] = min(dp[bit], arr[i][j] + dfs(bit | 1 << j));
            }
        }
    }
    return dp[bit];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    input();
    init();
    for (int i = 0; i < cmd.length(); i++) {
        if (cmd[i] == 'Y') {
            first += (1 << i);
        }
    }

    if (count(first) >= P) {
        cout << '0';
        return 0;
    }

    int ans=dfs(first);
    if(ans==100000000)cout<<"-1";
    else cout<<ans;


}