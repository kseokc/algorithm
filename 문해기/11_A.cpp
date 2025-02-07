#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int T;
	queue<int> q;
	queue<int> answer;
	int N, K;
	cin >> T;
	while (T--) {

		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			q.push(i);
		}
		while (!q.empty()) {
			for (int p = 0; p < K; p++) {
				q.push(q.front());
				q.pop();
			}
			answer.push(q.front());
			q.pop();
		}

		for (int i = 0; i < N; i++) {
			cout << answer.front() << ' ';
			answer.pop();
		}
		cout << '\n';
	}
}