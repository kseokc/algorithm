//
// Created by 김석찬 on 2022/11/16.
//

// 초록색 배양액과 빨간색 배양액을 적절하게 뿌림
// 배양액을 뿌릴 수있는 땅은 미리 정해져있다.
// 배양액은 매 초마다 이전에 배양액이 도달한 적이 없는 인접한 땅으로 퍼져간다.
// 하얀색 칸은 배영액을 뿌릴수없는 땅, 황토색 칸은 배양액을 뿌릴수 있는 땅, 하늘색 칸은 호수를 으미ㅣ
// 빨 , 초 배양액이 동시에 도달하면 꽃이 핌
// 정원가 두 배양액의 수가 주어졌을때 피울수있는 꽃의 최대 개수

#include<iostream>
#include<queue>
#include<vector>

using namespace std;


int xn[] = {-1, 1, 0, 0};
int yn[] = {0, 0, -1, 1};
int gareden[51][51];
pair<int, int> map[51][51];
vector<pair<int, int>> V;
vector<pair<int, int>> V1;
vector<pair<int, pair<int, int>>> choice; // 1은 초록색
int G, R, N, M;
int result;

void input() {
    cin >> N >> M >> G >> R;
    choice.resize(R + G);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> gareden[i][j];
            if (gareden[i][j] == 2)V.emplace_back(i, j);
        }
    }
}

void setting() {
    for (int i = 0; i < R + G; i++) {
        choice[i].first = 1;
    }
}


void sol() {
    int flower = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[0][i][j] == map[1][i][j]) flower += 1;
        }
    }
    result = max(result, flower);
}

void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    for (int i = 0; i < choice.size(); i++) {
        map[choice[i].second.first][choice[i].second.second] = {choice[i].first, 1};
        Q.push({{choice[i].first,        1},
                {choice[i].second.first, choice[i].second.second}});
    }
    while (!Q.empty()) {
        int x = Q.front().second.second;
        int y = Q.front().second.first;
        int color = Q.front().first.first;
        int cnt = Q.front().first.second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (gareden[Y][X] == 0)continue;
            if (map[Y][X].second!=0){
                if(map[Y][X].)
            }
        }
    }
    sol();
}

void brute2(int x, int a) {
    if (a > R)return;
    if (a == R && x == R) {
        bfs();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[0][i][j] = 0;
                map[1][i][j] = 1;
            }
        }
        return;
    } else {
        choice[a].first = 0;
        brute2(x + 1, a + 1);
        choice[a].first = 1;
        brute2(x + 1, a);
    }
}

void brute1(int x, int a) {
    if (x > G + R)return;
    else if (a == G + R && x == G + R) {
        for (int i = 0; i < R + G; i++) {
            choice[i].second.first = V1[i].first;
            choice[i].second.second = V1[i].second;
            cout << choice[i].second.first << " " << choice[i].second.second << '\n';
        }
        cout << '\n';
        brute2(0, 0);
        setting();
        return;
    }
    V1.emplace_back(V[x].first, V[x].second);
    brute1(x + 1, a + 1);
    V1.pop_back();
    brute1(x + 1, a);

}

int main() {
    input();
    brute1(0, 0);
    cout << result;
}


