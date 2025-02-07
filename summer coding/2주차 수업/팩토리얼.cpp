//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int arr[2];

int main() {
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++) {
        int x = 0;
        int y = 0;
        if (i % 2 == 0) {
            for (int j = 1; j < 9; j++) {
                int F = pow(2, j);
                if (i % F != 0)break;
                x = j;
            }
        }
        if (i % 5 == 0) {
            for (int j = 1; j < 4; j++) {
                int F = pow(5, j);
                if (i % F != 0)break;
                y = j;
            }
        }
        arr[0] += x;
        arr[1] += y;
    }
    if (arr[0] >= arr[1]) {
        cout << arr[1];
    } else {
        cout << arr[0];
    }
}