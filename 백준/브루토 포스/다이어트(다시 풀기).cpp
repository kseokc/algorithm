//
// Created by 김석찬 on 2025/01/08.
//

#include<iostream>
#include<vector>

using namespace std;

#define INF 987654321

int N;
int Sum[4];
vector<vector<int>> v;
bool result_num[16];
bool result_num2[16];
int result=INF;
int result_size=INF;


void sol(int n,int price,vector<int> ans,int size) {
    if(n>=N){
        if(price>=result && result_size<=size)return;

        for(int i=0; i<4; i++){
            if(Sum[i]>ans[i])return;
        }
        for(int i=0; i<N; i++){
            result_num2[i]= result_num[i];
        }
        result=price;
        result_size=size;
        return;
    }
    for(int i=n; i<N; i++){
        for(int j=0; j<4; j++){
            ans[j]+=v[i][j];
        }
        result_num[i]=true;
        sol(i+1,price+v[i][4],ans,size+1);
        result_num[i]=false;
        for(int j=0; j<4; j++){
            ans[j]-=v[i][j];
        }
        sol(i+1,price,ans,size);
    }
}

int main() {

    cin >> N;
    v.resize(N + 1);
    for (int i = 0; i < 4; i++)cin >> Sum[i];


    int a;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a;
            v[i].push_back(a);
        }
    }
    vector<int>k(5,0);
    sol(0,0,k,0);
    if(result==INF)cout<<-1;
    else{
        cout<<result<<'\n';
        for(int i=0; i<15; i++){
            if(result_num2[i])cout<<i+1<<" ";
        }
    }


}