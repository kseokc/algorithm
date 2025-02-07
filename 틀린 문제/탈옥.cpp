//
// Created by 김석찬 on 2023/01/26.
//

#include<iostream>
#include<queue>
#include<vector>

#define Max 103
using namespace std;

int xn[] = {-1, 1, 0, 0};
int yn[] = {0, 0, -1, 1};

int h, w, tc;
char prison[Max][Max];  // 감옥의 평면도를 저장
bool open_door[Max][Max]; // 문을 열었는지 아닌지 확인;
bool visit[Max][Max];
vector<pair<int, int>> exit_prison; // 탈출구의 위치를 저장
vector<pair<int, int>> person; // 범죄자들의 위치를 저장

int dfs(int a) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> Q;
    for (int i = 0; i < exit_prison.size(); i++) {
        if (prison[exit_prison[i].second][exit_prison[i].first] == '#' &&
            !open_door[exit_prison[i].second][exit_prison[i].first]) {
            Q.push({1, {exit_prison[i].first, exit_prison[i].second}});
            open_door[exit_prison[i].second][exit_prison[i].first] = true;
        } else {
            Q.push({0, {exit_prison[i].first, exit_prison[i].second}});
        }
        visit[exit_prison[i].second][exit_prison[i].first] = true;
    }
    while (!Q.empty()) {
        int x = Q.top().second.first;
        int y = Q.top().second.second;
        int cnt = Q.top().first;
        if (person[a].first == x && person[a].second == y)return cnt;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int X = xn[i] + x;
            int Y = yn[i] + y;
            if (X < 0 || Y < 0 || X >= w || Y >= h)continue;
            if (prison[Y][X] == '*' || visit[Y][X])continue;
            if (prison[Y][X] == '#' && !open_door[Y][X]) {
                open_door[Y][X] = true;
                visit[Y][X] = true;
                Q.push({cnt + 1, {X, Y}});
            } else {
                visit[Y][X] = true;
                Q.push({cnt, {X, Y}});
            }
        }
    }
}


void find_exit() {  //탈출구의 위치를 찾을 수있는 함수
    for (int i = 0; i < w; i++) {
        if (prison[0][i] != '*') {
            exit_prison.emplace_back(i, 0); // 출구가 되는 x와 y좌표를 저장한다.
        } else if (prison[h - 1][i] != '*') {
            exit_prison.emplace_back(i, h - 1);
        }
    }
    for (int i = 0; i < h; i++) {
        if (prison[i][0] != '*') {
            exit_prison.emplace_back(0, i);
        } else if (prison[i][w - 1] != '*') {
            exit_prison.emplace_back(w - 1, i);
        }
    }
}

void input() {
    cin >> h >> w;
    string s;
    for (int i = h - 1; i >= 0; i--) {
        cin >> s;
        for (int j = 0; j < w; j++) {
            if (s[j] == '$') person.emplace_back(j, i);
            prison[i][j] = s[j];
        }
    }
}

void reset_visit() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            visit[i][j] = false;
        }
    }
}

void all_reset() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            open_door[i][j] = false;
        }
    }
    exit_prison.clear();
    person.clear();
}

void sol() {
    cin >> tc;
    while (tc--) {
        int solution = 0;
        input();
        find_exit();
        for (int i = 0; i < 2; i++) {
            solution += dfs(i);
            cout<<solution<<"\n";
            reset_visit();
        }
        cout << solution << '\n';
        all_reset();
    }
}


int main() {
    sol();
}