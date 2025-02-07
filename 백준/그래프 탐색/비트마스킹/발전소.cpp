//
// Created by 김석찬 on 2023/02/09.
//

//고장나지 않은 발전소를 이용해서  고장난 발전소를 고칠수있다. 이떄 비용이 발생한다.
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

#define INF 900000000

using namespace std;

int N, fac, min_factory, condition;
int ans = 900000000;
int map[17][17];
int cur_cost[17][1 << 17];
char factory[17];
vector<int> V;
int C = 1;


int dfs(int cur_fac, int cur_bit, int fix) {


    if (min_factory == fix) {
        for (int i : V) {
            if (!((1 << i) & cur_bit))return INF;
        }
        return 0;
    }

    if (cur_cost[cur_fac][cur_bit] != -1) {
        return cur_cost[cur_fac][cur_bit];
    }
    cur_cost[cur_fac][cur_bit] = INF;

    for (int i = 0; i < N; i++) {
        if (i == cur_fac)continue;
        if ((1 << i) & cur_bit)continue;
        if ((1 << i) & fac) {
            cur_cost[cur_fac][cur_bit] = min({cur_cost[cur_fac][cur_bit], dfs(i, cur_bit | (1 << i), fix + 1),
                                              dfs(cur_fac, cur_bit | (1 << i), fix + 1)});
        } else {
            cur_cost[cur_fac][cur_bit] = min({cur_cost[cur_fac][cur_bit],
                                              map[cur_fac][i] + dfs(i, cur_bit | (1 << i), fix + 1),
                                              map[cur_fac][i] + dfs(cur_fac, cur_bit | (1 << i), fix + 1)});
        }
    }

    return cur_cost[cur_fac][cur_bit];
}


void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }


    for (int i = 0; i < N; i++) {
        cin >> factory[i];
        if (factory[i] == 'Y') {
            condition += 1;
            fac = fac | (1 << i);
            V.push_back(i);
        }
    }

    cin >> min_factory;
}

void sol() {
    input();
    memset(cur_cost, -1, sizeof(cur_cost));

    if (min_factory > N || condition == 0) {
        if (min_factory == condition)cout << 0;
        else {
            cout << -1;
        }
        return;
    }

    if (condition >= min_factory) {
        cout << 0;
    } else {
        for (auto i: V) {
            ans = min(ans, dfs(i, 1 << i, 1));
        }
        cout << ans;
    }
}

int main() {
    sol();

}
