//
// Created by 김석찬 on 2023/02/10.
//

// 앱이 활성화가 되어있다
// 메모리에 있는 앱을 삭제하는것을 비활성화라고 한다.
// FD x : 거북이를 x만큼 앞으로 전진
// lT x : 거북이를 반시계 방향으로 a도 만큼 회전
// RT a : 시계방향으로 a도 만큼 회전
// PU : 연필을 올린다.
// PD : 연필을 내린다.

// 직사각형을 그리는 필요한 pU의 최솟값
//


#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int map[1001][1001];
bool visit[1001][1001];
bool check[1001];

int x1, x2, y1, y2, N;
int ans;
int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};


void find_line(int a1, int b1, int a2, int b2,int number) {

    int num=number;

    a1 += 500;
    a2 += 500;
    b1 += 500;
    b2 += 500;

    for (int i = a1; i <= a2; i++) {
        if(map[i][b1]!=0){
            num=min(map[i][b1],num);
        }
        if(map[i][b2]!=0){
            num=min(map[i][b2],num);
        }
    }

    for (int i = b1; i <= b2; i++) {
        if(map[a1][i]!=0){
            num=min(map[a1][i],num);
        }
        if(map[a2][i]!=0){
            num=min(map[a2][i],num);
        }
    }

    for(int i=b1; i<=b2; i++){
        map[a1][i]=num;
        map[a2][i]=num;
    }
    for(int i=a1; i<=a2; i++){
        map[i][b1]=num;
        map[i][b2]=num;
    }
}

//void bfs(int x, int y) {
//    queue<pair<int, int>> Q;
//    Q.push({x, y});
//    visit[x][y] = true;
//    while (!Q.empty()) {
//        int X = Q.front().first;
//        int Y = Q.front().second;
//        Q.pop();
//        for (int i = 0; i < 4; i++) {
//            int xx = X + xn[i];
//            int yy = Y + yn[i];
//            if (!map[xx][yy])continue;
//            if (visit[xx][yy] || xx > 1000 || yy > 1000 || xx < 0 || yy < 0)continue;
//            Q.push({xx, yy});
//            visit[xx][yy] = true;
//
//        }
//    }
//}


void sol() {
    cin >> N;
    map[500][500]=1;
    for (int i = 2; i <= N+1; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        find_line(x1, y1, x2, y2,i);
    }


    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            check[map[j][i]]=true;
//            if (map[j][i] && !visit[j][i]) {
//                bfs(j, i);
//            }
        }
    }

    for(int i=2; i<1001; i++) {
        if (check[i])ans += 1;
    }

    cout<<ans;


}

int main() {
    sol();
}

