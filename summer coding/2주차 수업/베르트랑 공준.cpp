#include <iostream>
#include <cmath>

using namespace std;

int number = 123456 * 2; // 구하고자 하는 소수의 범위
int primeNum[246913];

void pN(int n) {
    int count = 0;
    for (int i = 2; i <= number; i++) {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (primeNum[i] == 0)
            continue;

        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    for (int i = n + 1; i <= 2 * n; i++) {
        if (primeNum[i] != 0)
            count++;
    }

    cout << count << '\n';
}

int main() {

    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        pN(n);
    }

}