//
// Created by 김석찬 on 2024/11/19.
//

#include<iostream>

using namespace std;

int N,M;
int arr[501][501];
int visit[501][501];
int xn[4]={-1,1,0,0};
int yn[4]={0,0,-1,1};
int ans;

void sol(int x,int y,int cnt,int score){
    if(cnt==4){
        ans=max(ans,score);
    }else{
        for(int i=0; i<4; i++){

        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }


    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            sol(j,i,1,arr[i][j]);

        }
    }

    cout<<ans;
}