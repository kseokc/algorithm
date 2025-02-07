//
// Created by 김석찬 on 2022/07/25.
//

#include<iostream>
#include<queue>
using namespace std;
int N,ceti,magic;
int giant;
int main(){
    priority_queue<int>pq;
    cin>>N>>ceti>>magic;
    for(int i=0; i<N; i++){
        cin>>giant;
        pq.push(giant);
    }

    int hmr;
    int count=0;

    while(1) {
        if (pq.top() >= ceti) {
            magic--;
            hmr = pq.top();
            pq.pop();

            if (hmr != 1) {
                count++;
                pq.push(hmr / 2);
            }else{
                pq.push(hmr);
            }
        }
        else {
            cout<<"YES\n"<<count;
            break;
        }

        if(magic==0){
            if(pq.top()<ceti){
                cout<<"YES\n"<<count;
                break;
            }else{
                cout<<"NO\n"<<pq.top();
                break;
            }
        }
    }
}