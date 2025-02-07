//
// Created by 김석찬 on 2022/08/01.
//

#include<iostream>
#include<cmath>

using namespace std;

long long findfive(long long x, int count) {
    long long result = 0;
    if (x == 0) {
        return result;
    }
    result = x / 5 * count - x / 5 * (count - 1) + findfive(x / 5, count + 1);
    return result;
}

long long findtwo(long long x, int count) {
    long long result = 0;
    if (x == 0) {
        return result;
    }
    result = x / 2 * count - x / 2 * (count - 1) + findtwo(x / 2, count + 1);
    return result;
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long five, two;
    five = findfive(n, 1) - findfive(n - m, 1) - findfive(m, 1);
    two = findtwo(n, 1) - findtwo(n - m, 1) - findtwo(m, 1);
    if (five <= two) {
        cout << five;
    } else {
        cout << two;
    }
}