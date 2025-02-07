//
// Created by 김석찬 on 2022/07/29.
//

#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> result;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int tc, f_radius, radius;
    cin >> tc >> f_radius;
    while (--tc) {
        cin >> radius;
        int first = LCM(f_radius, radius) / radius;
        int second = LCM(f_radius, radius) / f_radius;
        result.push_back({first, second});
    }
    for (auto i: result) {
        cout << i.first << '/' << i.second << '\n';
    }
}