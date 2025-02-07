//
// Created by 김석찬 on 2023/02/14.
//

#include <string>
#include <vector>
#include<queue>
using namespace std;

long long dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {


    for(int i=0; i<puddles.size(); i++){
        dp[puddles[i][0]][puddles[i][1]]=-1;
    }

    bool ok=false;
    for(int i=1; i<=m; i++){
        if(dp[i][1]==-1 || ok){
            dp[i][1]=-1;
            ok=true;
        }
        else dp[i][1]=1;
    }

    ok=false;

    for(int i=1; i<=n; i++){
        if(dp[1][i]==-1 || ok){
            dp[1][i]=-1;
            ok=true;
        }
        else dp[1][i]=1;
    }




    for(int i=2; i<=m; i++){
        for(int j=2; j<=n; j++){
            if(dp[i][j]==-1)continue;
            if(dp[i-1][j]==-1 && dp[i][j-1]==-1){
                dp[i][j]=-1;
            }
            else if(dp[i-1][j]==-1){
                dp[i][j]=dp[i][j-1];
                dp[i][j]%=1000000007;
            }
            else if(dp[i][j-1]==-1){
                dp[i][j]=dp[i-1][j];
                dp[i][j]%=1000000007;
            }
            else {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                dp[i][j]%=1000000007;
            }
        }
    }
    if(dp[m][n] == -1)dp[m][n]=0;
    return dp[m][n];
}