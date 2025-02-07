//
// Created by 김석찬 on 2023/03/04.
//

#include<iostream>
#define MOD 1000000003
using namespace std;

int dp[1001][1001];

int N, K;

void input() {
    cin >> N >> K;
}

void sol() {
    input();

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][0]=1;
            dp[i][1]=i;
        }
    }

    for(int i=2; i<=N; i++){  // 총 갯수
        for(int j=1; j<=K; j++){ // 지금까지 쓰인 색의 수를 j라고 하고// j번째 색을 선택하고 안하고
            dp[i][j]=dp[i-2][j-1]+dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }
    //i번째 색을 선택  j개만큼의 색깔이 선택되었을때
    cout<<(dp[N-1][K]+dp[N-3][K-1])%MOD<<'\n';
}

int main(){
    sol();
}