//
// Created by 김석찬 on 2023/02/10.
//

#include<iostream>

using namespace std;

long long sol[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
long long N;

void Div(long long x, long long cnt) {
    while (x > 0) {
        sol[x % 10] += cnt;
        x /= 10;
    }
}

void ans(long long x, long long y, long long cnt) {
    while ((x % 10) != 0 && x <= y) {
        Div(x, cnt);
        x++;
    }
    if (x > y)return;
    while ((y % 10) != 9 && y >= x) {
        Div(y, cnt);
        y--;
    }

    for (int i = 0; i < 10; i++) {
        sol[i] = sol[i] + ((y / 10) - (x / 10) + 1) * cnt;
    }

    ans(x / 10, y / 10, cnt * 10);
}


int main() {
    long long n;
    cin >> n;
    ans(1, n, 1);
    for (int i = 0; i < 10; i++) {
        cout << sol[i] << " ";
    }
}