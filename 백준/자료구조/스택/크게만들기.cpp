//
// Created by 김석찬 on 2023/07/06.
//

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N, K;
string number;
stack<char>S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K >> number;

    for(int i=0; i<N; i++){
        if(K==0){
            S.push(number[i]);
            continue;
        }
        if(S.empty())S.push(number[i]);
        else if(S.top()>=number[i])S.push(number[i]);
        else {
            while(!S.empty() && S.top()<(number[i]) && K!=0){
                S.pop();
                K--;
            }
            S.push(number[i]);
        }
    }

    stack<char>result;

    while(!S.empty()){
        if(K==0){
            result.push(S.top());
        }else{
            K--;
        }
        S.pop();
    }
    while(!result.empty()){
        cout<<result.top();
        result.pop();
    }

}
