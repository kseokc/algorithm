//
// Created by 김석찬 on 2022/08/07.
//
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N, K;
vector<int> day;
int kit;
bool check[8];
vector<int> arr;
int cnt;

void search(){
    if(N==arr.size()){
        int sum = 0;
        bool can = true;
        for (int i = 0; i < N; i++) {
            sum = sum + arr[i] - K;
            if (sum < 0) {
                can = false;
            }
        }
        if (can) cnt++;

        return;
    }
    else{
        for(int i=0; i<N; i++){
            if(check[i])continue;
            arr.push_back(day[i]);
            check[i]=true;
            search();
            check[i]= false;
            arr.pop_back();
        }
    }
    return;
}


int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> kit;
        day.push_back(kit);
    }
    search();
    cout << cnt;
}
