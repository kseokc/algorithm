#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

#define  ll long long

int T,N,M;
vector<pair<int,int>>v;
int main(){
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>N>>M;
        int K;
        cin>>K;
        int a,b;
        for(int i=0; i<K; i++){
            cin>>a>>b;
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        int ans=0;
        while(!v.empty()){
            vector<pair<int,int>>tmp;
            int x=v[0].first;
            int y=v[0].second;
            ans++;
            for(int i=1; i<v.size(); i++){
                if(x<=v[i].first && y<=v[i].second){
                    x=v[i].first;
                    y=v[i].second;
                }else{
                    tmp.push_back({v[i].first,v[i].second});
                }
            }
            v=tmp;
        }
        cout<<ans<<'\n';
    }
}
