//
// Created by 김석찬 on 2022/08/03.
//

#include<iostream>

using namespace std;


int main() {
    int A, B, V;
    int result;
    int count;
    cin >> A >> B >> V;

    result = (V - A) % (A - B);
    count = (V - A) / (A - B);
    if (result == 0) {
        cout << count + 1;
    } else {
        cout << count + 2;
    }

}
