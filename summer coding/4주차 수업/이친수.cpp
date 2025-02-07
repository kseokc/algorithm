//
// Created by 김석찬 on 2022/08/13.
//

#include<iostream>

using namespace std;
long long dp[91];
long long find_prinary(long long n){
    if(n==0 || n==1 || n==2)return dp[n]=1;
    if(dp[n])return dp[n];
    return dp[n]= find_prinary(n-1)+ find_prinary(n-2);

}
int main() {
    long long n;
    cin >> n;
    cout << find_prinary(n);
}