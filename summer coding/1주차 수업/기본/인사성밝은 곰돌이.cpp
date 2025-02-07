//
// Created by 김석찬 on 2022/07/24.
//

#include<iostream>
#include<set>
using namespace std;
int tc;
int main(){
    set<string>A;
    cin>>tc;
    string person;
    int count=0;
    while(tc--){
        cin>>person;
        if(person=="ENTER"){
            A.erase(A.begin(),A.end());
        }
        else if(A.find(person)==A.end()){
            A.insert(person);
            count++;
        }
    }
    cout<<count;
}