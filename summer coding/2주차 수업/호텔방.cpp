//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>

using namespace std;


int main() {
    int T, H, W, N;
    cin >> T;
    int x;
    while (T--) {
        cin >> H >> W >> N;
        if (N % H == 0) {
            x = H * 100 + (N / H);
        } else
            x = ((N % H) * 100) + (N / H) + 1;
        cout << x << '\n';
    }
}