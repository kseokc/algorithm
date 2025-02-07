//
// Created by 김석찬 on 2022/07/18.
//

//계단의 수는 300이하의 자연수
// 연속으로 3번계단을 오를수없다
//계단은 한칸 두칸 오를수있다.
// 계단을 오를 때 점수의 최대값을 구해라

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct score{
    int s;
    int idx;
    score(int s,int idx){
        this->s=s;
        this->idx=idx;
    }
    score(){
        this->s=-1;
        this->idx=-1;
    }
};
vector<score>arr[301];
int tc;
int v;

queue<pair<int,int>>q;

void bfs(int start,int end){
    q.push({start,0});
    while(!q.empty()){
        int score=q.front().second;
        int front=q.front().first;
        q.pop();
        for(auto i:arr[front]){
            q.push({i,arr[front][i]->s})
        }
    }
    return;
}
int main(){
    cin>>tc;
    for(int i=1; i<tc+1; i++){
        cin>>v;
        arr[i]=score(v,i);
    }
}