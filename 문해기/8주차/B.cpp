//
// Created by 김석찬 on 2024/12/18.
//

#include<iostream>
using namespace std;

int T;

int dp[3002][3002];

int  main(){
    cin>>T;
    for(int t=0; t<T; t++){
        string a,b;
        cin>>a>>b;

        int k=max(a.length(),b.length());

        for(int i=0; i<k+1; i++){
            dp[i][0]=i;
            dp[0][i]=i;
        }

        for(int i=1; i<a.length()+1; i++){
            for(int j=1; j<b.length()+1; j++){

                if(a[i-1]!=b[j-1]){
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    dp[i][j]+=1;
                }else{
                    dp[i][j]=dp[i-1][j-1];
                }

            }

        }

        cout<<dp[a.length()][b.length()]<<'\n';
    }
}