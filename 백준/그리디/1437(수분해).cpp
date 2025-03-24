//
// Created by 김석찬 on 2025/03/20.
//

#include<iostream>

#define MOD 10007

using namespace std;

int n;
long long sol = 1;
int arr[99];

int main() {
    cin >> n;
    if (n == 0 || n == 1) {
        sol = n == 0 ? 0 : 1;
        cout << sol;
        return 0;
    }
    // 무조건 2,3으로 나누고 곱하는게 가장 크다
    while (n > 0) {
        if (n == 4 || n == 2) {
            sol = n == 4 ? (sol * 4) % MOD : (sol * 2) % MOD;
            break;
        }
        sol = (sol * 3) % MOD;
        n = n - 3;
    }
    cout << sol;

}