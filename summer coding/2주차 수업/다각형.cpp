//
// Created by 김석찬 on 2022/08/01.
//

#include<iostream>

using namespace std;

int findcount(int x) {
    return (x * (x - 1) * (x - 2) * (x - 3)) / 24;
}

int main() {
    int num;
    cin >> num;
    cout << findcount(num);
}
