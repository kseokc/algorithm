//
// Created by 김석찬 on 2025/02/03.
//

#include<iostream>
#include <vector>

using namespace std;


int N, M;
vector<int> v;
bool visit[9];

void sol(int size, int num) {
    if (num > N + 1 || size>M)return;
    if (size == M) {
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<'\n';
    }
    for (int i = 1; i <= N; i++) {
        if(visit[i])continue;
        v.push_back(i);
        visit[i]=true;
        sol(size+1,i+1);
        visit[i]=false;
        v.pop_back();
    }


}

int main() {
    cin >> N >> M;
    sol(0, 1);
}