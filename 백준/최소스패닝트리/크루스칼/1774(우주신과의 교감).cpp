//
// Created by 김석찬 on 2023/02/02.
//

//
// Created by 김석찬 on 2022/08/27.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


#define Max 10001
using namespace std;

int V, E;
double A, B;
double ans;
int parent[Max];
vector<pair<double, double>> SpaceGod;
vector<pair<double, pair<int, int>>> all_V;


int find(int x) {
    if (parent[x] == x)return x;
    else {
        return parent[x] = find(parent[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}


double calculate_dis(int a, int b) {
    double x = pow((double) SpaceGod[a].first - (double) SpaceGod[b].first, 2);
    double y = pow((double) SpaceGod[a].second - (double) SpaceGod[b].second, 2);
    return sqrt(x + y);
}


void find_edge() {
    for (int i = 1; i <= V; i++) {
        for (int j = i + 1; j <= V; j++) {
            double value = calculate_dis(i, j);
            all_V.push_back({value, {i, j}});
        }
    }
    sort(all_V.begin(), all_V.end());

    for (int i = 0; i < all_V.size(); i++) {
        int first = all_V[i].second.first;
        int second = all_V[i].second.second;
        double val = all_V[i].first;
        if (find(first) == find(second))continue;
        Union(first, second);
        ans += val;
    }
}

int main() {
    cin >> V >> E;
    SpaceGod.resize(V + 1);

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= V; i++) {
        cin >> A >> B;
        SpaceGod[i] = {A, B};
    }

    int a, b;
    for (int i = 0; i < E; i++) {
        cin >> a >> b;
        if (find(a) == find(b))continue;
        Union(a, b);
    }

    find_edge();

    cout << fixed;
    cout.precision(2);
    cout << ans;
}