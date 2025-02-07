//
// Created by 김석찬 on 2023/02/01.
//

#include<iostream>
#include<queue>

#define Max 1001
using namespace std;

int N, M;
char map[Max][Max];
char sol[Max][Max];

int xn[] = {0, 0, -1, 1};
int yn[] = {-1, 1, 0, 0};

bool visit1[Max][Max];
bool visit2[Max][Max];
int visit3[Max][Max];


void reset() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sol[i][j] = '0';
        }
    }
}

int bfs1(int a, int b) {
    int cnt = 1;
    queue<pair<int, int>> Q;
    Q.push({a, b});
    visit1[b][a] = true;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (visit1[Y][X] || map[Y][X] == '1')continue;
            cnt+=1;
            cnt%=10;
            Q.push({X, Y});
            visit1[Y][X] = true;
        }
    }
    return cnt%10;
}

void bfs2(int a, int b, char cnt, int number) {
    queue<pair<int, int>> Q;
    Q.push({a, b});
    visit2[b][a] = true;
    sol[b][a] = '0';
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = x + xn[i];
            int Y = y + yn[i];
            if (X < 0 || Y < 0 || X >= M || Y >= N)continue;
            if (visit2[Y][X])continue;
            if (map[Y][X] == '1' && visit3[Y][X]!=number) {
                int count = sol[Y][X] - '0';
                count = count + (cnt - '0');
                count%=10;
                sol[Y][X] = '0' + count;
                visit3[Y][X] = number;
            } else if (map[Y][X] == '0') {
                Q.push({X, Y});
                visit2[Y][X] = true;
                sol[Y][X] = '0';
            }

        }
    }
}

void input() {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin>>map[i][j];
        }
    }
}


void solve() {
    input();
    reset();
    int number=1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '0' && !visit1[i][j]) {
                int count = bfs1(j, i);
                char c = '0' + count;
                bfs2(j, i, c,number);
                number+=1;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == '0') {
                cout << 0;
            } else {
                int z = sol[i][j] - '0';
                z += 1;
                z %= 10;
                cout << z;
            }
        }
        cout << '\n';
    }
}

int main() {
    solve();
}