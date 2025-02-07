#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000000];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while(T--) {
		int N, M, size_;
		cin >> N >> M;

		size_ = N * M;

		for (int i = 0; i < size_; i++) {
			cin >> arr[i];
		}

		int Q, q;
		cin >> Q;

		for (int i = 0; i < Q; i++) {
			cin >> q;
			cout << binary_search(arr, arr + size_, q) << ' ';
		}
		cout << '\n';
	}
}