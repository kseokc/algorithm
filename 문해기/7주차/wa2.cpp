#include<iostream>
using namespace std;

int dp[501][501];
int map[501][501];
int T;
int N,M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;

    for(int t=0; t<T; t++){
        int total=0;
        cin>>N>>M;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin>>map[i][j];
                if(map[i][j])total++;
            }
        }
        int cnt=0;
        for(int i=0; i<M; i++){
            if(map[0][i]==1)cnt++;
            dp[0][i]=cnt;
        }
        cnt=0;
        for(int i=0; i<N; i++){
            if(map[i][0]==1)cnt++;
            dp[i][0]=cnt;
        }
        for(int i=1; i<N; i++){
            for(int j=1; j<M; j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+map[i][j];

            }
        }
        cout<<total-dp[N-1][M-1]<<'\n';
    }
}