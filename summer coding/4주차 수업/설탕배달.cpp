//
// Created by 김석찬 on 2022/08/14.
//

#include<iostream>

using namespace std;

int main() {
    int T;
    int count = 0;
    cin >> T;
    while (1) {
        if (T % 5 == 0) {
            if (count == 0) {
                cout << T / 5;
                break;
            } else {
                cout << T / 5 + count;
                break;
            }
        } else if (T == 0) {
            cout << count;
            break;
        } else if (T < 0) {
            cout << "-1";
            break;
        }
        T -= 3;
        count++;
    }

}