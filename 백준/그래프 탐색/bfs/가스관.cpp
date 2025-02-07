//
// Created by 김석찬 on 2023/02/28.
//

//
// Created by 김석찬 on 2022/07/26.
//

#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

priority_queue<long long> Maxpq;
priority_queue<long long> Minpq;
unordered_map<long long,long long>A;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long tc,k,number;
    char n;
    cin>>tc;
    while(tc--){

        Maxpq=priority_queue<long long>();
        Minpq=priority_queue<long long>();
        A.clear();

        cin>>k;
        while(k--){
            cin>>n;
            if(n=='I'){
                cin>>number;
                Maxpq.push(number);
                Minpq.push(-number);
                if(A.find(number)==A.end()){
                    A.insert({number,1});
                }
                else A.find(number)->second+=1;
            }else{
                cin>>number;
                if(number==1){
                    if(Maxpq.empty()){
                        continue;
                    }
                    while(A.find(Maxpq.top())->second==0){
                        Maxpq.pop();
                        if(Maxpq.empty())break;
                    }
                    if(Maxpq.empty()){
                        continue;
                    }
                    A.find(Maxpq.top())->second-=1;
                    Maxpq.pop();
                }else{
                    if(Minpq.empty()){
                        continue;
                    }
                    while(A.find(-Minpq.top())->second==0){
                        Minpq.pop();
                        if(Minpq.empty())break;
                    }
                    if(Minpq.empty()){
                        continue;
                    }
                    A.find(-Minpq.top())->second-=1;
                    Minpq.pop();
                }
            }

        }
        while(!Maxpq.empty()){
            if(A.find(Maxpq.top())->second!=0){
                cout<<Maxpq.top()<<" ";
                break;
            }
            Maxpq.pop();
        }
        while(!Minpq.empty()){
            if(A.find(-Minpq.top())->second!=0){
                cout<<-Minpq.top()<<"\n";
                break;
            }
            Minpq.pop();
        }

        if(Maxpq.empty() || Minpq.empty()){
            cout<<"EMPTY\n";
        }
    }
}