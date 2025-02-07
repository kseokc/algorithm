#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<int>> dp(M+1, vector<int>(N+1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= M; i++) {
            for (int j = 0; j <= N; j++) {
                long long sum = 0;

                int limit = min(K, j);
                for (int x = 0; x <= limit; x++) {
                    sum += dp[i-1][j-x];
                }
                dp[i][j] = sum % MOD;
            }
        }

        int totalCount = 0;
        for (int j = 0; j <= N; j++) {
            totalCount = (totalCount + dp[M][j]) % MOD;
        }

        int invalidCount = 0;
        for (int i = 0; i <= K; i++) {
            if (i * M <= N) {
                invalidCount++;
            }
        }

        int answer = (totalCount - invalidCount + MOD) % MOD;
        cout << answer << "\n";
    }

    return 0;
}
