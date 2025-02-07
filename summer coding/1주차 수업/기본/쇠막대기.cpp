//
// Created by 김석찬 on 2022/07/22.
//

#include<iostream>
#include<stack>
using namespace std;
string val;
stack<char>arr;

int main(){
    cin>>val;
    int count=0;
    for(int i=0; i<val.length(); i++){
        if(val[i]=='('){
            count++;
            arr.push('(');
        }
        else{
            if(val[i-1]=='('){
                arr.pop();
                count+=arr.size();
                count--;
            }
            else{
                arr.pop();
            }
        }
    }
    cout<<count;

}