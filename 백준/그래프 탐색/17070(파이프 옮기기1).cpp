//
// Created by 김석찬 on 2025/01/17.
//

#include<iostream>

using namespace std;

int n;
int arr[17][17];
bool visit[17][17];

int dir_x[] = {1, 0, 1};
int dir_y[] = {0, 1, 1};


int cnt;

void chk(int d, int x, int y) {
    switch (d) {
        case 0:
            visit[y][x + 1] = true;
            return;
        case 1:
            visit[y + 1][x] = true;
            return;
        case 2:
            visit[y + 1][x] = true;
            visit[y][x + 1] = true;
            visit[y + 1][x + 1] = true;
            return;
    }
    return;
}

void reChk(int d, int x, int y) {
    switch (d) {
        case 0:
            visit[y][x + 1] = false;
            return;
        case 1:
            visit[y + 1][x] = false;
            return;
        case 2:
            visit[y + 1][x] = false;
            visit[y][x + 1] = false;
            visit[y + 1][x + 1] = false;
            return;
    }
}


void sol(int x, int y,int d) {
    if (x == n - 1 && y == n - 1) {
        cnt++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        int xx = x + dir_x[i];
        int yy = y + dir_y[i];
        if (xx < 0 || yy < 0 || xx >= n || yy >= n)continue;
        if (visit[yy][xx] || arr[yy][xx]==1)continue;
        if(d==0 && i==1)continue;
        if((d==1 && i==0) || (4==d && i==1))continue;
        if(i==2 && (arr[y+1][x]==1||arr[y][x+1]==1))continue;
        chk(i, x, y);

        sol(xx, yy,i);

        reChk(i, x, y);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    visit[0][0] = true;
    visit[1][0] = true;
    sol(1, 0,4);

    cout<<cnt<<'\n';


}