#include<iostream>
#include<vector>


using namespace std;

int N, L, R;
long dp[101][101][101]; // 왼쪽에서 보이는 건물의 수 오른쪽에서 보이는 건물의 수

void input() {
    cin >> N >> L >> R;
}

void solve() {
    dp[1][1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            for (int k = 1; k <= R; k++) {
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + dp[i - 1][j][k] * (i - 2);
                dp[i][j][k] %= 1000000007;
            }
        }
    }
}


int main() {
    input();
    solve();
    cout << dp[N][L][R];
}