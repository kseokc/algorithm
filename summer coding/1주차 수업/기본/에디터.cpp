//
// Created by 김석찬 on 2022/07/23.
//

#include<iostream>
#include<list>
using namespace std;
list<char> editor;
string S;
char val,edi;
int tc;
int main(){
    cin>>S;
    for(int i=0; i<S.length(); i++){
        editor.push_back(S[i]);
    }

    cin>>tc;

    auto itr1=editor.end();
    auto itr2=editor.end();

    while(tc--){
        cin>>edi;
        if(edi=='L'){
            if(itr1==editor.begin())continue;
            itr1--;
            itr2--;
        }else if(edi=='D'){
            if(itr1==editor.end())continue;
            itr1++;
            itr2++;
        }else if(edi=='B'){
            if(itr1==editor.begin())continue;
            editor.erase(--itr1); // 감소연산자를 이상하게 사용했어요
            itr1=itr2;
        }else if(edi=='P'){
            cin>>val;
            editor.insert(itr1,val);
        }
    }
    for(auto iter=editor.begin(); iter!=editor.end(); iter++){
        cout<<*iter;
    }
}