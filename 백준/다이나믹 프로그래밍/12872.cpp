//
// Created by 김석찬 on 2023/02/21.
//

#include<iostream>

using namespace std;

// 수빈이는 노래가 N개가 저장 되어있  p개의 노래를 들을려한다. 모든 노래ㅑ를 플레이 리스트에 추가해야한다.
//같은 노래를 추가하려면  적어도 사이에 M개의 노래가 있어야하낟.
// 수빈이가 만들수있는 플레리스트의 경우의 수
//1<N<100 0<M<N N<p<100

//수빈이가 1000000007 나눈 값을 구하낟.

//N M P 가 순서 대로 주어진다.


// i번째 노래를 들으면 i번째 노래는 P다음 부터 들을수있다.

int N, M, P;

long long dp[101][101];


void input() {
    cin >> N >> M >> P;
}

void sol() {
    input();

    dp[0][0] = 1;

    for (int i = 1; i <=N; i++) {
        for (int j = 1; j <= P; j++) {
            dp[i][j] += (dp[i - 1][j - 1] * (N - i + 1));
            dp[i][j] += (dp[i][j-1] * max(0, i - M));
            dp[i][j]%=1000000007;
        }
    }
    cout << dp[N][P];
}

int main() {
    sol();
}