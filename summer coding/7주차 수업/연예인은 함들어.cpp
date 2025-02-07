//
// Created by 김석찬 on 2022/09/07.
//

#include<iostream>

#define INF 100000001
using namespace std;

int martix[102][102];

int V, M, a, b, c, J, S;

void set_martix() {
    for (int i = 1; i <= V + 1; i++) {
        for (int j = 1; j <= V + 1; j++) {
            martix[i][j] = INF;
        }
    }
}

int main() {
    cin >> V >> M;

    set_martix();

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        martix[a][b] = martix[b][a] = min(martix[a][b], c);
    }

    cin >> J >> S;

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                martix[i][j] = min(martix[i][j], martix[i][k] + martix[k][j]);

    int ans = V + 1;

    for (int i = 1; i <= V; i++) {
        if (i != J && i != S && martix[S][J] == martix[S][i] + martix[J][i] && martix[i][J] <= martix[i][S]) {
            if (martix[ans][J] > martix[i][J]) {
                ans = i;
            }
        }
    }

    if (ans == V + 1)cout << "-1";
    else cout << ans;
}