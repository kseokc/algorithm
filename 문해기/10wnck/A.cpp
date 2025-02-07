//
// Created by 김석찬 on 2024/12/18.
//

#include<iostream>
#include<queue>
using namespace std;

int T, N, K;

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin>>N>>K;
        queue<int>q;
        for(int i=0; i<N; i++){
            q.push(i+1);
        }
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();

            if(cnt==K){
                cout<<x<<" ";
                cnt=0;
                continue;
            }
            else q.push(x);
            cnt++;
        }
    }
}