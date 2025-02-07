#include<iostream>
#include<vector>
using namespace std;

int T;
int n,k;
int arr[100001];
pair<int,int> ans[100001];
int solve[100001];
bool visit[100001];

vector<vector<int>>v;


void init(){
    for(int i=0; i<100001; i++){
        visit[i]=false;
        ans[i]={0,0};
        solve[i]=0;
    }
}


void sol(int s,int cnt){

    visit[s]=true;
    if(ans[s].first==1){
        solve[ans[s].second]=cnt;
    }

    for(auto i:v[s]){
        if(visit[i])continue;
        sol(i,cnt+1);
    }
}

int  main(){
    cin>>T;
    for(int t=0; t<T; t++){
        init();
        cin>>n>>k;
        v.resize(n+2);
        int w;
        for(int i=1; i<n+1; i++){
            cin>>w;
            arr[w]=i;
        }

        for(int i=0; i<k; i++){
            cin>>w;
            ans[arr[w]]={1,i+1};
        }
        int a,b;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            v[a].push_back(b);
        }
        sol(0,0);
        for(int i=1; i<k+1; i++){
            cout<<solve[i]<<' ';
        }
        cout<<'\n';
        v.clear();
    }
}