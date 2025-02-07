//
// Created by 김석찬 on 2022/07/25.
//

#include<iostream>
#include<stack>
#include<vector>

using namespace std;
int num[1000001];
int Com[1000001];
int result[1000001];
stack<pair<int, int>> A;
int N, value;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> value;
        num[value]++;
        result[i] = value;
    }
    for (int i = 0; i < N; i++) {
        Com[i] = num[result[i]];
    }

    for (int i = N - 1; i >= 0; i--) {
        int compare = Com[i];

        if (A.empty()) {
            A.push({compare, i});
            Com[i] = -1;
        } else {
            if (A.top().first > compare) {
                Com[i] = result[A.top().second];
                A.push({compare, i});
            } else {
                while (A.top().first <= compare) {
                    A.pop();
                    if (A.empty())break;
                }
                if (A.empty()) {
                    A.push({compare, i});
                    Com[i] = -1;
                    continue;
                }
                Com[i] = result[A.top().second];
                A.push({compare, i});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << Com[i] << " ";
    }

}