//
// Created by 김석찬 on 2023/02/14.
//

#include <string>
#include <vector>
// 코딩력 , 알고력0 이상의 정수

using namespace std;
int dp[151][151];
int solution(int alp, int cop, vector<vector<int>> problems) {

    // 알고력만 높일때 필요한 시간 1,0,1
    // 코딩력만 높일때 필요한 시간 0,1,1
    // 문제를 풀때 필요한 시간 problem[i][2], problem[i][3], problem[i][4]
    // -> 필요한 조건 problem[i][0], problem[i][1]


    int goal_a=0;
    int goal_c=0;

    for(int i=0; i<problems.size(); i++){
        goal_a=max(problems[i][0],goal_a);
        goal_c=max(problems[i][1],goal_c);
    }

    if(goal_a<=alp && goal_c<=cop)return 0;

    if(goal_a <= alp){
        alp=goal_a;
    }
    if(goal_c <= cop){
        cop=goal_c;
    }

    for(int i=0; i<151; i++){
        for(int j=0; j<151; j++){
            dp[i][j]=123213;
        }
    }


    dp[alp][cop]=0;

    for(int i=alp; i<=goal_a; i++){
        for(int j=cop; j<=goal_c; j++){

            dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);

            for(auto p:problems){
                if(p[0]<=i && p[1]<=j){
                    if(p[2]+i>goal_a && p[3]+j>goal_c){
                        dp[goal_a][goal_c]=min(dp[goal_a][goal_c],dp[i][j]+p[4]);
                    }
                    else if(p[2]+i>goal_a){
                        dp[goal_a][j+p[3]]=min(dp[goal_a][j+p[3]],dp[i][j]+p[4]);
                    }
                    else if(p[3]+j>goal_c){
                        dp[i+p[2]][goal_c]=min(dp[i+p[2]][goal_c],dp[i][j]+p[4]);
                    }
                    else if(p[3]+j<=goal_c && p[2]+i<=goal_a){
                        dp[i+p[2]][j+p[3]]=min(dp[i+p[2]][j+p[3]],dp[i][j]+p[4]);
                    }
                }
            }
        }
    }



    return dp[goal_a][goal_c];
}