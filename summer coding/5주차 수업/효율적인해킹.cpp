//
// Created by 김석찬 on 2022/08/21.
//

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N, M, com_1, com_2, Max;
vector<int> trust[10001];
bool vertex[10001];
vector<int> sol;

int bfs(int strat) {
    int cnt=1;
    queue<int> Q;
    Q.push(strat);
    vertex[strat] = true;
    while (!Q.empty()) {
        int number = Q.front();
        Q.pop();
        for (int i = 0; i < trust[number].size(); i++) {
            if (vertex[trust[number][i]])continue;
            cnt++;
            Q.push(trust[number][i]);
            vertex[trust[number][i]] = true;
        }
    }
    return cnt;
}

void reset() {
    for (int i = 1; i <= N; i++) {
        vertex[i] = false;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> com_1 >> com_2;
        trust[com_2].push_back(com_1);
    }
    for (int i = 1; i <= N; i++) {
        int bfs_num = bfs(i);
        if (bfs_num > Max) {
            Max = bfs_num;
            sol.clear();
            sol.push_back(i);
        } else if (bfs_num == Max) {
            sol.push_back(i);
        }
        reset();
    }
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }

}