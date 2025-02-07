//
// Created by 김석찬 on 2023/07/06.
//

#include<iostream>
#include<stack>

using namespace std;

stack<pair<int,int>> homework;
int tc, cmd, score, Time,ans;

int main(){
    cin>>tc;
    while(tc--){
        cin>>cmd;
        if(cmd==1){
            cin>>score>>Time;
            homework.push({score,Time});
        }
        if(homework.empty())continue;
        homework.top().second--;
        if(homework.top().second==0){
            ans+=homework.top().first;
            homework.pop();
        }
    }
    cout<<ans;
}