//
// Created by 김석찬 on 2022/08/23.
//

#include<iostream>
#include<vector>

using namespace std;
int N, weight, vertex_p, vertex_c, Max, Sol;
vector<pair<int, int>> Tree[10001];
bool vertex[10001];


int dfs(int strat, int sum_weight) {
    vertex[strat] = true;
    for (int i = 0; i < Tree[strat].size(); i++) {
        if (vertex[Tree[strat][i].first])continue;
        sum_weight += Tree[strat][i].second;
        dfs(Tree[strat][i].first, sum_weight);
        sum_weight -= Tree[strat][i].second;
    }
    Max = max(sum_weight, Max);
    return Max;
}

void reset() {
    for (int i = 1; i <= N; i++) {
        vertex[i] = false;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> vertex_p >> vertex_c >> weight;
        Tree[vertex_p].emplace_back(vertex_c, weight);
        Tree[vertex_c].emplace_back(vertex_p, weight);
    }

    for (int i = 1; i <= N; i++) {
        Sol = max(dfs(i, 0), Sol);
        Max = 0;
        reset();
    }
    cout << Sol;
}