//
// Created by 김석찬 on 2024/04/01.
//

//학자는 n개의 대학에서 오퍼가 왔고, d일안에 와서 강의를 하면,p만큼의 금액을받는다.
// 이때 학자가 순회공연을 했을때 가장 많이 돈을 벌수있는 순회방법을 구해라
// 최대 하루에 한곳에서 강연을 할수있다.

#include<iostream>
#include <vector>
#include <queue>

using namespace std;


vector<priority_queue<int>> v;
int n, d, p;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int maxDate = 0;
    v.resize(10001);
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v[d].push(p);
        maxDate = max(maxDate, d);
    }
    int endidx=maxDate;

    for (int i = maxDate; i > 0; i--) {
        pair<int,int> maxprice={0,0};

        for(int j=endidx; j>=i; j--){
            if(!v[j].empty() && v[j].top()>maxprice.first){
                maxprice={v[j].top(),j};
            }
        }
        ans+=maxprice.first;
        v[maxprice.second].pop();
        while(v[endidx].empty()){
            endidx--;
        }
    }
    cout<<ans;

}