//
// Created by 김석찬 on 2022/08/06.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int number;
vector<int> A;

int main() {
    cin >> N;
    int size = N;
    while (size--) {
        cin >> number;
        A.push_back(number);
    }
    std::sort(A.begin(), A.end());
    int MAX = 0;
    do {
        int sum = 0;
        for (int i = 0; i < N - 1; i++) {
            if ((A[i] - A[i + 1]) < 0) {
                sum = sum - (A[i] - A[i + 1]);
            } else {
                sum = sum + (A[i] - A[i + 1]);
            }
        }
        MAX = max(sum, MAX);
    } while (next_permutation(A.begin(), A.end()));
    cout << MAX;
}