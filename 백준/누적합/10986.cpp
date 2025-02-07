//
// Created by 김석찬 on 2023/12/26.
//

#include <iostream>

using namespace std;

long long n, mod, ans, number;

long long arr[10000001];
long long modArr[1001];

void input() {
    cin >> n >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> number;
        arr[i] = arr[i - 1] + number;
    }
}

long long sol() {
    for (int i = 1; i <= n; i++) {
        arr[i] %= mod;
        if (arr[i] == 0)ans += 1;
        modArr[arr[i]] += 1;
    }
    for (int i = 0; i < mod; i++) {
        if (modArr[i] < 2)continue;
        ans += (modArr[i] * (modArr[i] - 1)) / 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    input();
    cout << sol();
}