#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001][100];
int weight[100];
int value[100];
int T, N, M;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	while(T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> weight[i];
			dp[0][i] = 0;
		}
		for (int i = 0; i < N; i++) {
			cin >> value[i];
		}

		for (int m = 1; m <= M; m++) {
			for (int i = 0; i < N; i++) {
				if (m < weight[i]) {
					if (i == 0) {
						dp[m][i] = 0;
					}
					else {
						dp[m][i] = dp[m][i - 1];
					}
				}
				else {
					if (i == 0) {
						dp[m][i] = value[i];
					}
					else {
						dp[m][i] = max(dp[m - weight[i]][i - 1] + value[i], dp[m][i - 1]);
					}
				}
			}
		}
		cout << dp[M][N - 1] << '\n';
	}
}