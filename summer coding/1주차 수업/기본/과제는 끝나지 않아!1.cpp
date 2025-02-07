//
// Created by 김석찬 on 2022/07/24.
//

#include<iostream>
#include<stack>
using namespace std;
stack<pair<int,int>> work;
int T,V,score,v1;
int result;
int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        cin>>v1;
        if(v1==1){
            cin>>score>>V;
            work.push({score,V-1});
            if(work.top().second==0){
                result+=work.top().first;
                work.pop();
            }
        }else{
            if(work.empty())continue;
            work.top().second-=1;
            if(work.top().second==0){
                result+=work.top().first;
                work.pop();
            }
        }
    }
    cout<<result;
}