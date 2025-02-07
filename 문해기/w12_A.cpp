#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N, K, M, Q;
        cin >> N >> K >> M;

        vector<vector<int>> graph(K + 1);
        vector<int> in_degree(K + 1, 0);
        vector<int> min_semesters(K + 1, 0);
        
        // Read prerequisites
        for (int i = 0; i < M; ++i) {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            in_degree[b]++;
        }

        // Topological sort to calculate minimum semesters
        queue<int> q;
        for (int i = 1; i <= K; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
                min_semesters[i] = 1;
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int next : graph[current]) {
                in_degree[next]--;
                min_semesters[next] = max(min_semesters[next], min_semesters[current] + 1);
                if (in_degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Process queries
        cin >> Q;
        while (Q--) {
            int course;
            cin >> course;
            cout << (min_semesters[course] <= N ? "True" : "False") << '\n';
        }
    }
}
