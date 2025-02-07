//
// Created by 김석찬 on 2022/09/05.
//

#include<iostream>
#include<vector>

#define Max 501
#define INF 100000000

using namespace std;
vector<pair<int, pair<int, int>>> v;
int N, M, A, B, C;
long long dist[Max];

void set_dist() {
    for (int i = 2; i <= N; i++) {
        dist[i] = INF;
    }
}

bool bellmam_ford() {
    dist[1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int strat = v[j].first;
            int last = v[j].second.first;
            int t = v[j].second.second;
            if (dist[strat] != INF && dist[last] > dist[strat] + t) {
                dist[last] = dist[strat] + t;
                if (i == N - 1) {
                    return false;
                }

            }
        }
    }
    return true;
}

int main() {
    cin >> N >> M;

    set_dist();

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        v.push_back({A, {B, C}});
    }

    if (bellmam_ford()) {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)cout << "-1" << '\n';
            else cout << dist[i] << '\n';
        }
    } else {
        cout << "-1";
    }


}