//
// Created by 김석찬 on 2022/10/26.
//

#include<iostream>
#define MAX 11
using namespace std;
int T,n;
int dp[11];
int main(){
    cin>>T;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<MAX; i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    while(T--){
        cin>>n;
        cout<<dp[n]<<'\n';
    }

}