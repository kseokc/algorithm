#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>arr[10001];
bool visited[10001];
int n,k,a,b;


int bfs(int start,int end){
    queue<pair<int,int>> q;
    q.push({start,0});
    while(!q.empty()){
        int front=q.front().first;
        int count=q.front().second;
        q.pop();
        if(front==end)return count;
        if(visited[front])continue;
        visited[front]=true;
        for(auto i:arr[front]){
            if(!visited[i]) q.push({i,count+1});
        }
    }
    return -1;
}

int main(){
    cin>>k;
    int idx=1;
    int t=k;
    while(t--){
        cin>>n;
        int c=1;
        int p=1;
        while((idx+(c*n))<=k){
            arr[idx].push_back((c*n)+idx);
            c++;
        }
        while((idx-(p*n))>0){
            arr[idx].push_back(idx-(p*n));
            p++;
        }
        idx++;
    }
    cin>>a>>b;
    cout<<bfs(a,b);
}