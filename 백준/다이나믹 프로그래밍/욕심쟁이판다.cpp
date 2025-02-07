//
// Created by 김석찬 on 2024/11/20.
//

#include <iostream>

using namespace std;

int N;
int arr[501][501];
int ans;
int dp[501][501];
int xn[4]={-1,1,0,0};
int yn[4]={0,0,1,-1};

int sol(int y, int x){
    int& ret =dp[y][x];
    if(ret!=0) return ret;

    for(int i=0; i<4; i++) {
        int _x = x + xn[i];
        int _y = y + yn[i];
        if (_x < 0 || _y < 0 || _x >= N || _y >= N) continue;
        if (arr[_y][_x] > arr[y][x]) {
            ret = max(ret, sol(_y, _x) + 1);
        }
    }
    if(ret == 0) {
        ret = 1;
    }

    return ret;
}


int main(){
    cin>>N;
    for (int i = 0; i <N ; i++) {
        for (int j = 0; j <N ; j++) {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i <N ; i++) {
        for (int j = 0; j <N ; j++) {
            ans=max(ans,sol(i,j));
        }
    }
    cout<<ans<<'\n';



}