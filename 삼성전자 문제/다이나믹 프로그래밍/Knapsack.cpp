//
// Created by 김석찬 on 2023/08/04.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N, K, T;
vector<pair<int, int>> V;
int dp[101][1001];

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        int v, c;
        V.emplace_back(0, 0);
        for (int i = 0; i < N; i++) {
            cin >> v >> c;
            V.emplace_back(v, c);
        }
        //가치는 v이고 부피는 c 부피가 c가 넘지않고 v의 합이 최대가 되게 해야함


        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= K; i++) {
                if (i < V[j].first) {
                    dp[j][i] = dp[j - 1][i];
                } else {
                    dp[j][i] = max(dp[j - 1][i - V[j].first] + V[j].second, dp[j - 1][i]);
                }
            }
        }


        cout << '#' << tc << " " << dp[N][K] << '\n';

        V.clear();
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = 0;
            }
        }
    }
}