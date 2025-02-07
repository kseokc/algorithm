#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int V, E, vertex_1, vertex_2, strat;
vector<int> gragh[1001];
bool ver[1001];

void dfs(int v) {
    ver[v] = true;
    cout << v << " ";
    for (int i = 0; i < gragh[v].size(); i++) {
        if (ver[gragh[v][i]])continue;
        dfs(gragh[v][i]);
    }
}

void bfs(int v) {
    queue<int> Q;
    Q.push(v);
    cout << v << " ";
    ver[v] = true;
    while (!Q.empty()) {
        int num = Q.front();
        Q.pop();
        for (int i = 0; i < gragh[num].size(); i++) {
            if (ver[gragh[num][i]])continue;
            ver[gragh[num][i]] = true;
            cout << gragh[num][i] << " ";
            Q.push(gragh[num][i]);
        }
    }
    return;
}

void reset() {
    for (int i = 0; i <= V; i++) {
        ver[i] = false;
    }
}

int main() {

    cin >> V >> E >> strat;

    for (int i = 0; i < E; i++) {
        cin >> vertex_1 >> vertex_2;
        gragh[vertex_1].push_back(vertex_2);
        gragh[vertex_2].push_back(vertex_1);
    }

    for (int i = 0; i <= V; i++) {
        std::sort(gragh[i].begin(), gragh[i].end());
    }

    dfs(strat);
    cout << "\n";
    reset();
    bfs(strat);
}