//
// Created by 김석찬 on 2024/11/19.
//

#include<iostream>
#include <vector>
#include<stack>

using namespace std;


// 거리는 10억 이하
// 리터 당 가격도 10억 이하
// N의 크기는 10만 이하

int N;
vector<long> dis;


int main() {
    cin >> N;
    long a;
    for (int i = 0; i < N - 1; i++) {
        cin >> a;
        dis.push_back(a);
    }

    long ans=0;
    long pre=10000000000;
    for (int i = 0; i < N; i++) {
        cin >> a;
        if(i==N-1)break;
        if(a<pre){
            pre=a;
        }
        ans=ans+pre*dis[i];
    }
    cout<<ans;

}