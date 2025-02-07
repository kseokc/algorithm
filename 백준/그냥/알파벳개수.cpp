//
// Created by 김석찬 on 2024/02/27.
//

#include<iostream>
#include <string>
using namespace std;


int main(){
    string s;
    cin>>s;
    for(int i=0; i<26; i++){
        char k='a';
        k+=i;
        int cnt=0;
        for(int j=0; (j=s.find(k,j))!=s.npos; j++){
            cnt+=1;
        }
        cout<<cnt<<" ";
    }
}