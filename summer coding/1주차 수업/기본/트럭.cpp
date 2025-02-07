//
// Created by 김석찬 on 2022/07/24.
//

#include<iostream>
#include<queue>
using namespace std;
queue<int> bridge;
int arr[1000];
int main(){
    int n,w,L,truck;
    int time=1;
    cin>>n>>w>>L;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    bridge.push(arr[0]);
    int sum=arr[0];
    int idx=1;

    while(--n){
        if(sum+arr[idx]>L){
            while(sum+arr[idx]>L){
                sum-=bridge.front();
                bridge.pop();

            }
            time=time+w-bridge.size();
            bridge.push(arr[idx]);
            sum+=arr[idx];
        }else{
            time+=1;
            bridge.push(arr[idx]);
            sum+=arr[idx];
        }
        idx++;
    }
    cout<<time+w;
}