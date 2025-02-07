//
// Created by 김석찬 on 2023/03/08.
//

//홀수줄에서 N개의 타일이 짝수 줄에는 N-1개의 타일이 있다.
// 한타일에서 다른 타일로 넘어가려면 인접해야한다.
// 같은 변을 공유하는 타일의 숫자가 같아야한다.\

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

int N, Max;
int map[1002][1002];
bool visit[1002][1002];
vector<int> MaxV;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i % 2 == 1) {
            for (int j = 1; j <= 2 * N; j++) {
                cin >> map[i][j];
            }
        } else {
            for (int j = 2; j <= 2 * N - 1; j++) {
                cin >> map[i][j];
            }
        }
    }

}

void sol() { //N이 짝수일때는 1로 나온다
    priority_queue<pair<int,pair<pair<int, int>, pair<vector<int>, int>>>,vector<pair<int,pair<pair<int, int>, pair<vector<int>, int>>>>,greater<>> Q;
    vector<int> V;
    V.push_back(1);
    Q.push({1,{{1, 1},
               {V, 1}}});
    Q.push({1,{{2, 1},
               {V, 1}}});
    visit[1][2]=true;
    visit[1][1]=true;
    while (!Q.empty()) {
        int idx_x = Q.top().second.first.first;
        int idx_y = Q.top().second.first.second;
        int ln = Q.top().second.second.second;
        int tile_num=Q.top().first;
        vector<int> v1 = Q.top().second.second.first;
        if(ln>Max){
            Max=ln;
            MaxV=v1;
        }
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int idx_xx = idx_x + xn[i];
            int idx_yy = idx_y + yn[i];
            int cnt = ln;
            bool left=false;
            vector<int> v2 = v1;
            if (idx_xx <= 0 || idx_yy <= 0 || idx_xx > 2 * N || idx_yy > N)continue;
            if (visit[idx_yy][idx_xx])continue;
            if (idx_yy % 2 == 0) { // 같은 타일의 순서는 짝,홀 개수는 2N-2이개임
                if (idx_xx >= 2 && idx_xx <= ((2 * N) - 1)) {
                    if (map[idx_y][idx_x] == map[idx_yy][idx_xx]) { // 다른 타일의 이동
                        if (idx_yy != idx_y) {  //  위 아래로 움직일때
                            if (idx_yy > idx_y) {
                                if (idx_x % 2 != 0)cnt = cnt + N - 1;
                                else cnt = cnt + N;
                            } else {
                                if (idx_x % 2 != 0)cnt = cnt - N;
                                else cnt = cnt - N + 1;
                            }
                        } else { // 옆으로 아동할때
                            if (idx_xx > idx_x) {
                                cnt = cnt + 1;
                            } else {
                                cnt = cnt - 1;
                            }
                        }
                        v2.push_back(cnt);
                        Q.push({tile_num+1,{{idx_xx, idx_yy},
                                            {v2,     cnt}}});
                        visit[idx_yy][idx_xx] = true;
                    }
                }
            } else {  // 같은 타일의 순서는 홀.짝
                if (map[idx_yy][idx_xx] == map[idx_y][idx_x]) {
                    if (idx_yy != idx_y) {  //  위 아래로 움직일때
                        if (idx_yy > idx_y) {
                            if (idx_x % 2 == 0)cnt = cnt + N - 1;
                            else cnt = cnt + N;
                        } else {
                            if (idx_x % 2 == 0)cnt = cnt - N;
                            else cnt = cnt - N + 1;
                        }
                    } else { // 옆으로 이동할때
                        if (idx_xx > idx_x) {
                            cnt = cnt + 1;
                        } else {
                            cnt = cnt - 1;
                        }
                    }
                    v2.push_back(cnt);
                    Q.push({tile_num+1,{{idx_xx, idx_yy},
                                        {v2,     cnt}}});
                    visit[idx_yy][idx_xx] = true;
                }
            }
        }
    }
}


int main() {
    input();
    sol();
    cout << MaxV.size() << '\n';
    for (int i = 0; i < MaxV.size(); i++) {
        cout << MaxV[i] << " ";
    }

}