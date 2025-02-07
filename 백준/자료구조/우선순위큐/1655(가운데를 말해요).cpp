//
// Created by 김석찬 on 2023/07/04.
//

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int> Q_left;
priority_queue<int, vector<int>, greater<>> Q_right;
int middle, total;

int n;

int mid_pq(int a) {
    if (total == 0) {
        middle = a;
        total++;
        return middle;
    }
    int left = Q_left.size();
    int right = Q_right.size();
    if (middle == a) {
        if (right > left)Q_left.push(a);
        else Q_right.push(a);
    } else if (middle < a) {
        if (left >= right) {
            Q_right.push(a);
        } else {
            Q_left.push(middle);
            Q_right.push(a);
            middle = Q_right.top();
            Q_right.pop();
        }
    } else {//middle > a
        if (left >= right) {
            Q_right.push(middle);
            Q_left.push(a);
            middle = Q_left.top();
            Q_left.pop();
        } else {
            Q_left.push(a);
        }

    }
    return middle;
}

void input() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int number;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> number;
        cout << mid_pq(number) << '\n';
    }
}

int main() {
    input();
}