//
// Created by 김석찬 on 2023/08/03.
//

#include<iostream>
#include<stack>

using namespace std;
int dp[1001][1001];
int T;
string s1, s2;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {

        cin >> s1 >> s2;
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << "#" << tc << ' ' << dp[ s1.length()][s2.length()] << '\n';
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                dp[i][j] = 0;
            }
        }
    }
}