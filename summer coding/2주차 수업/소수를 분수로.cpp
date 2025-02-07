//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long GCD(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() {
    int tc;
    string s;
    cin >> tc;
    vector<long long> demomi;
    vector<long long> numi;
    vector<long long> rem;

    while (tc--) {
        demomi.clear();
        numi.clear();
        rem.clear();
        bool cycle = false;
        long long x = 0, y = 0, r = 0;

        cin >> s;

        for (int i = 2; i < s.length(); i++) {
            if (s[i] == '(') {
                cycle = true;
                continue;
            }
            if (s[i] == ')')continue;

            numi.push_back(s[i] - '0');
            if (cycle) {
                demomi.push_back(9);
            } else {
                rem.push_back(s[i] - '0');
                demomi.push_back(0);
            }
        }
        if (demomi[demomi.size() - 1] == 0)demomi[demomi.size() - 1] = 10;

        for (int i = 0; i < demomi.size(); i++) {
            y = y + demomi[i] * pow(10, i);
        }
        for (int i = 0; i < numi.size(); i++) {
            x = x + numi[numi.size() - i - 1] * pow(10, i);
        }
        for (int i = 0; i < rem.size(); i++) {
            r = r + rem[rem.size() - i - 1] * pow(10, i);
        }
        long long p;
        long long x_1;
        if ((x - r) == 0) {
            x_1 = x;
        } else {
            x_1 = (x - r);
        }
        p = GCD(y, x_1);
        cout << x_1 / p << '/' << y / p << '\n';
    }
}