//
// Created by 김석찬 on 2022/07/24.
//

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> eorl;
queue<int> wnf;

int main(){
    int N;
    int num;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        wnf.push(num);
    }
    int count=1;
    while(1) {
        if(!wnf.empty()&&!eorl.empty()){
            if(wnf.front()==count || eorl.top()==count){
                if(wnf.front()==count){
                    wnf.pop();
                }else{
                    eorl.pop();
                }
                count++;
            }else{
                eorl.push(wnf.front());
                wnf.pop();  // 2
            }
        }
        else if(!wnf.empty() && eorl.empty()){
            if(wnf.front()==count){
                count++;
                wnf.pop();
            }else{
                eorl.push(wnf.front());  // 1
                wnf.pop();
            }
        }else if(!eorl.empty() && wnf.empty()){
            if(eorl.top()!=count){
                cout<<"Sad";
                break;
            }else{
                count++;
                eorl.pop();
            }
        }else{
            cout<<"Nice";
            break;
        }
    }

}

