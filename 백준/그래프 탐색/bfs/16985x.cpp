//
// Created by 김석찬 on 2022/12/27.
//

// 판을 돌릴수 있음 , 판은 쌓는 순서도 마음대로 할수있음
// 1은 사람이 들어갈수있는 것 , 0은 사람이 들어갈수없는 것
//  5*5*5

#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>


using namespace std;

int box[5][5][5];
bool visit[5][5][5];
vector<int> rotation;
vector<int>V={0,1,2,3,4};
int minscore = 10000;


int xn[] = {-1, 1, 0, 0, 0, 0};
int yn[] = {0, 0, -1, 1, 0, 0};
int zn[] = {0, 0, 0, 0, -1, 1};


int bfs(int a, int b) {
    queue<pair<pair<int, int>, pair<int, int>>> Q;
    Q.push({{0, a},
            {b, 0}});
    visit[0][b][a] = true;
    while (!Q.empty()) {
        int cnt = Q.front().first.first;
        int x = Q.front().first.second;
        int y = Q.front().second.first;
        int z = Q.front().second.second;
        Q.pop();
        if (cnt >= minscore)return cnt;
        if (x == 4 - a && y == 4 - b && z == 4)return cnt;
        for (int i = 0; i < 6; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            int Z = z + zn[i];
            if (X < 0 || Y < 0 || Z < 0 || X > 4 || Y > 4 || Z > 4 || visit[V[Z]][Y][X])continue;
            if (rotation[V[Z]] == 0) {
                if (box[V[Z]][Y][X] == 1) {
                    visit[V[Z]][Y][X] = true;
                    Q.push({{cnt + 1, X},
                            {Y,       V[Z]}});
                }
            } else if (rotation[V[Z]] == 1) {
                if (box[V[Z]][X][4 - Y] == 1) {
                    visit[V[Z]][X][4 - Y] = true;
                    Q.push({{cnt + 1, 4 - Y},
                            {X,       V[Z]}});
                }
            } else if (rotation[V[Z]] == 2) {
                if (box[V[Z]][4 - Y][4 - X] == 1) {
                    visit[V[Z]][4 - Y][4 - X] = true;
                    Q.push({{cnt + 1, 4 - X},
                            {4 - Y,   V[Z]}});
                }
            } else if (rotation[V[Z]] == 3) {
                if (box[V[Z]][4 - X][Y] == 1) {
                    visit[V[Z]][4 - X][Y] = true;
                    Q.push({{cnt + 1, Y},
                            {4 - X,   V[Z]}});
                }
            }
        }
    }
    return 100000;
}

void clear() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                visit[i][j][k] = false;
            }
        }
    }
}

int bfs1() {
    clear();
    if (rotation[V[0]] == 0) {
        return bfs(0, 0);
    } else if (rotation[V[0]] == 1) {
        return bfs(4, 0);
    } else if (rotation[V[0]] == 2) {
        return bfs(4, 4);
    } else if (rotation[V[0]] == 3) {
        return bfs(0, 4);
    }
}


int brute2() {
    sort(V.begin(),V.end());
    do {
        minscore = min(bfs1(), minscore);
    } while (next_permutation(V.begin(), V.end()));
}

void brute1() { // 방향을 몇번 돌릴지 정하는 함수
    if (rotation.size() == 5) {
        brute2();
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotation.push_back(i);
        brute1();
        rotation.pop_back();
    }
}

void input() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> box[i][j][k];
            }
        }
    }
}

int main() {
    input();
    brute1();
    if (minscore == 100000) {
        cout << "-1";
    } else {
        cout << minscore;
    }

}
