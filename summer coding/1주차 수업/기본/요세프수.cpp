//
// Created by 김석찬 on 2022/07/25.
//

#include<iostream>
using namespace std;
int arr[5000];
int main(){
    int N,K;
    cin>>N>>K;
    int count=N;
    int idx=K-1;
    cout<<"<";
    while(--count){
        cout<<idx+1<<", ";
        int shift=0;
        arr[idx]=1;
        while(shift!=K){
            idx=(idx+1)%N;
            if(arr[idx]==0){
                shift++;
            }
        }
    }
    cout<<idx+1<<">";

}