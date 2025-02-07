//
// Created by 김석찬 on 2022/09/01.
//

// 0번에서 출발해서 i번째 정점까지의 최단거리
//
#include<iostream>
#include<queue>
#include<vector>

#define Max 20000
#define INF 200001
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
vector<vector<pair<int, int>>> v;
int N, M, v1, v2, value, strat;
int dist[Max];


void reset_INF() {
    for (int i = 1; i <= Max; i++) {
        dist[i] = INF;
    }
}

void sol() {
    Q.push({0, 0});
    while (!Q.empty()) {
        int now = Q.top().first;
        int d = Q.top().second;
        if (dist[now] < d)continue;
    }
}

int main() {
    cin >> N >> M;
    v.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        v[v1].emplace_back(v2, value);
    }

}

// 벨만 포드 ssp
// 음의 가중치가 있어도 사용가능, 음의 사이클 유무 판별 가능
// O(V*E)의 시간복잡도를 가짐 다익스트라보다는 사실 효율이 잘 나오지 않음
// 동작 원리
// 간선 리스트로만 저장하면 된다. ->(  출발 도착 가중치  )
// dist 배열을 초기화, 출발 노드의 dist값 0
// 모든 간선을 확인해보며 해당 간선을 사용해서 dist 배열을 갱신시킬수있는지 확인한다.
// n-1번 반복한다.
//

/* include<iostream>
 * #include<vector>
 *
 * using namespace std;
 *
 */