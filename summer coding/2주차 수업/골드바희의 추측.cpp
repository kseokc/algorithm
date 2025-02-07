//
// Created by 김석찬 on 2022/07/29.
//

#include<iostream>
#include<cmath>

using namespace std;
int number = 10000;
int primenumber[10001];

void pN() {
    for (int i = 2; i < number; i++) {
        primenumber[i] = i;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (primenumber[i] == 0)continue;
        for (int j = i * i; j <= number; j += i) {
            primenumber[j] = 0;
        }
    }
}

void findgold(int n) {
    int num;
    for (int i = n / 2; i < n - 1; i++) {
        if (primenumber[i] != 0 && (primenumber[n - i]) != 0) {
            num = i;
            break;
        }
    }
    cout << (n - num) << " " << num << "\n";
}

int main() {
    int tc, n;
    cin >> tc;
    pN();
    while (tc--) {
        cin >> n;
        findgold(n);
    }
}