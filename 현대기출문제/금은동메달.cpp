#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int K,N;

int main() {
    cin>>N>>K;
    priority_queue<pair<tuple<int,int,int>,int>>q;
    int a,b,c,d;
    for(int i=0; i<N; i++){
        cin>>a>>b>>c>>d;
        q.push({{b,c,d},a});
    }

    int cnt=1;
    int plus=0;

    while(!q.empty()){
        int gold=get<0>(q.top().first);
        int silver=get<1>(q.top().first);
        int bronze=get<2>(q.top().first);
        int team=q.top().second;

        q.pop();

        if(K==team)break;
        if(gold==get<0>(q.top().first) && silver==get<1>(q.top().first) && bronze== get<2>(q.top().first)) {
            plus+=1;
            continue;
        }
        if(plus!=0){
            cnt=cnt+plus+1;
            plus=0;
        }
        else cnt++;


    }
    cout<<cnt<<'\n';
}

