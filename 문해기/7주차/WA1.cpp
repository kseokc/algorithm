//
// Created by 김석찬 on 2024/12/18.
//

#include<iostream>
#include <queue>
using namespace std;

int N,M;
int s_x,s_y,e_x,e_y;
int T;
char arr[1001][1001];
int xn[]={0,0,-1,1};
int yn[]={-1,1,0,0};


int sol(){
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{s_x,s_y}});
    arr[s_y][s_x]='X';
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int cnt=q.front().first;

        q.pop();
        if(x==e_x && y==e_y)return cnt;
        for(int i=0; i<4; i++){

            int x_=x+xn[i];
            int y_=y+yn[i];
            if(x_<0 || y_<0 || x_>=N || y_>=M)continue;

            if(arr[y_][x_]=='X')continue;
            q.push({cnt+1,{x_,y_}});
            arr[y_][x_]='X';
        }
    }
    return -1;
}

int main(){
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>N>>M;
        cin>>s_x>>s_y>>e_x>>e_y;
        s_y=M-1-s_y;
        e_y=M-1-e_y;
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                cin>>arr[i][j];
            }
        }


        cout<<sol()<<'\n';
    }
}