#include<iostream>

using namespace std;


int N, M;
int arr[501][501];
int dp[501][501];

int xn[4] = {0, 0, -1, 1};
int yn[4] = {1, -1, 0, 0};

int sol(int x, int y) {
    if(y==M-1 && x==N-1){
        return 1;
    }
    int &ret = dp[y][x];
    if (ret!=0) return ret;

    for (int i = 0; i < 4; i++) {
        int _x = x + xn[i];
        int _y = y + yn[i];
        if (_x < 0 || _y < 0 || _x >= N || _y >= M) continue;
        if (arr[_y][_x] < arr[y][x]) {
            int temp=sol(_x,_y);
            if(temp!=-1)ret+=temp;
        }
    }

    if(ret==0)ret=-1;
    return ret;
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    sol(0,0);
    if(dp[0][0]==-1)cout<<0;
    else cout<<dp[0][0]<<'\n';
}