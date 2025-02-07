//
// Created by 김석찬 on 2022/07/25.
//
#include<iostream>
#include<stack>
using namespace std;
stack<char>prefix;
string express;
int main(){
    cin>>express;
    for(int i=0; i<express.length(); i++){
        if(express[i]-'A'>=0 && express[i]-'A'<=26){
            cout<<express[i];
        }
        else{
            if(prefix.empty()){
                prefix.push(express[i]);
            }
            else{
                if(express[i]==')'){
                    while(prefix.top()!='('){
                        cout<<prefix.top();
                        prefix.pop();
                    }
                    prefix.pop();
                }
                else if(express[i]=='('){
                    prefix.push(express[i]);
                }
                else if(express[i]=='*' || express[i]=='/'){
                    if(prefix.top()=='+' || prefix.top()=='-' || prefix.top()=='('){
                        prefix.push(express[i]);
                    }
                    else if(prefix.top()=='*' || prefix.top()=='/'){
                        while(prefix.top()=='*' || prefix.top()=='/' || prefix.top()=='('){
                            cout<<prefix.top();
                            prefix.pop();
                            if(prefix.empty())break;
                        }
                        prefix.push(express[i]);
                    }
                }
                else if(express[i]=='+'|| express[i]=='-'){
                    while(prefix.top()!='('){
                        cout<<prefix.top();
                        prefix.pop();
                        if(prefix.empty())break;
                    }
                    prefix.push(express[i]);
                }
            }
        }
    }
    while(!prefix.empty()){
        cout<<prefix.top();
        prefix.pop();
    }
}