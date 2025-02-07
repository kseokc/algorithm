
#include<iostream>

#define mod 1000000007
using namespace std;

long long numi(long long x) {
    long long n = 1;
    for (long long i = x; i >= 1; i--) {
        n = n * i % mod;
    }
    return n;
}

long long Pow(long long x, long long y) {
    long long ret = 1;
    while (y) {
        if (y % 2 == 1)
            ret = ret * x % mod;
        y = y / 2;
        x = x * x % mod;
    }
    return ret;
}

int main() {
    long long n, m;
    long long num = 1;
    long long num_1 = 1;
    long long num_2 = 1;
    cin >> n >> m;
    num = numi(n);
    num_1 = Pow(numi(m), mod - 2) % mod;
    num_2 = Pow(numi(n - m), mod - 2) % mod;
    cout << (num * num_1 % mod) * num_2 % mod;
}
