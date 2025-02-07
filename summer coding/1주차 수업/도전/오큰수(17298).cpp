//
// Created by 김석찬 on 2022/07/22.
//

//오큰수
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int>big;
vector<int>arr;
vector<int>result;
int val,N;
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>val;
        arr.push_back(val);
    }

    for(int i=N-1; i>=0; i--){
        int num=arr[i];
        if(big.empty()){
            result.emplace_back(-1);
            big.push(num);
            continue;
        }
        int top=big.top();
        if(top>num){
            result.emplace_back(top);
            big.push(num);
        }
        else if(top<=num){
            while(big.top()<=num){
                big.pop();
                if(big.empty()){
                    break;
                }
            }
            if(big.empty()){
                result.emplace_back(-1);
                big.push(num);
            }
            else{
                result.emplace_back(big.top());
                big.push(num);
            }
        }
    }
    for(int i=N-1; i>=0; i--){
        cout<<result[i]<<" ";
    }
}