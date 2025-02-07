//
// Created by 김석찬 on 2023/11/21.
//

//초기에 입력값으로 알고력과 코딩력이 입력으로 주어진다.
// problem은 {필요알고력, 필요코딩력, 발전알고력, 발전코딩력, 시간} 150,150,30,30,100
// 모든 문제를 풀수있게 하는 최소의 시간

// 내가 만들어야하는건 결국에는 알고력이 제일 높은 문제와 코딩력이 제일 높은 문제를 확인하고 그것을 해결하기위해서 로직을 설정해야한다.
// 코딩력과 알고력은 늘릴수있고 1을 늘리기 위해서는 1의 시간이 필요로한다.

#include <string>
#include <vector>
#include<iostream>

#define Max 1000000000
using namespace std;

int dp[200][200];

void initDp(int alp, int cop) {
    for (int i = alp; i < 191; i++) {
        for (int j = cop; j < 191; j++) {
            dp[i][j] = Max;
        }
    }
    dp[alp][cop] = 0;
    for (int i = alp; i < 191; i++) {
        for (int j = cop; j < 191; j++) {
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        }
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    // 풀수있는 문제들을 제거.
    initDp(alp, cop);
    dp[alp][cop] = 0;
    int copMax = 0;
    int alpMax = 0;
    for (auto i: problems) {
        copMax = max(i[1], copMax);
        alpMax = max(i[0], alpMax);
    }
    for (int i = alp; i <= alpMax; i++) {
        for (int j = cop; j <= copMax; j++) {
            for (auto p: problems) {
                if (p[0] <= i && p[1] <= j) { // 현재 볼 수 있는것 을 풀수있다는 가정
                    if(dp[i][j]+p[4]<dp[i+p[2]][j+p[3]]){
                        dp[i + p[2]][j + p[3]]=dp[i][j]+p[4];
                        for(int k=i+p[2]; k<alpMax+31; k++){
                            for(int d=j+p[3]; d<copMax+31; d++){
                                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
                                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
                            }
                        }
                    }
                    dp[i + p[2]][j + p[3]] = min(dp[i][j] + p[4], dp[i + p[2]][j + p[3]]);
                }
            }
        }
    }

    int answer = 1000000000; // 최소 시간
    for (int i = alpMax; i < alpMax + 31; i++) {
        for (int j = copMax; j < copMax + 31; j++) {
            answer = min(dp[i][j], answer);
//            cout << dp[i][j] << ' ';
        }
//        cout << '\n';
    }
    return answer;
}

int main() {
    //{{0,  0,  2, 1, 2},
    //                             {4,  5,  3, 1, 2},
    //                             {4,  11, 4, 0, 2},
    //                             {10, 4,  0, 4, 2}}
    vector<vector<int>> v = {{10, 15, 2, 1, 2},
                             {20, 20, 3, 3, 4}};
    cout << solution(10, 10, v);
}
