//
// Created by 김석찬 on 2022/08/07.
//

#include<iostream>
#include<vector>
using namespace std;
vector<int> number;
int check[11];
vector<int> oper; // 0: +, 1: -, 2: *, 3: /
vector<int> arr;
int N,num,optr;
int MAX=-1000000000;
int MIN=1000000000;
void search(){
    if(arr.size()==N-1){
        int sum=number[0];
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==0){
                sum=sum+number[i+1];
            }
            else if(arr[i]==1){
                sum=sum-number[i+1];
            }
            else if(arr[i]==2){
                sum=sum*number[i+1];
            }
            else{
                sum=sum/number[i+1];
            }
        }
        MAX=max(MAX,sum);
        MIN=min(MIN,sum);
        return;
    }
    else{
        for(int i=0; i<N-1; i++){
            if(check[i])continue;
            check[i]=true;
            arr.push_back(oper[i]);
            search();
            arr.pop_back();
            check[i]=false;
        }
    }
    return;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        number.push_back(num);
    }
    for(int i=0; i<4; i++){
        cin>>optr;
        while(optr--){
            oper.push_back(i);
        }
    }
    search();
    cout<<MAX<<'\n'<<MIN;
}