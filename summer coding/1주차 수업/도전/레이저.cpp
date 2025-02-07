//
// Created by 김석찬 on 2022/07/25.
//

#include<iostream>
#include<stack>
using namespace std;
int top[500000];
int result[500000];
stack<pair<int,int>> l;
int N,height;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>top[i];
    }
    for(int i=0; i<N; i++){
        if(l.empty()){
            l.push({top[i],i});
            result[i]=0;
        }
        else{
            if(l.top().first>top[i]){
                result[i]=l.top().second+1;
                l.push({top[i],i});
            }else{
                while(l.top().first<top[i]){
                    l.pop();
                    if(l.empty())break;
                }
                if(l.empty()){
                    l.push({top[i],i});
                    result[i]=0;
                    continue;
                }
                result[i]=l.top().second+1;
                l.push({top[i],i});
            }
        }
    }
    for(int i=0; i<N; i++){
        cout<<result[i]<<" ";
    }
}