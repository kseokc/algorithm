//
// Created by 김석찬 on 2023/07/04.
//

#include<iostream>
#include<queue>

using namespace std;

queue<int> truck;
queue<int> bridge;
int n, W, L, ans;

void input() {
    cin >> n >> W >> L;
    int weight;
    for (int i = 0; i < n; i++) {
        cin >> weight;
        truck.push(weight);
    }
    for (int i = 0; i < W; i++) {
        bridge.push(0);
    }
}

void solve() {
    int MAX = 0;
    while (!truck.empty()) {
        bridge.pop();
        int value = truck.front();
        if (value + MAX <= L) {
            bridge.push(value);
            MAX += value;
            truck.pop();
        } else {
            bridge.push(0);
        }
        MAX -= bridge.front();
        ans++;
    }

}

int main() {
    input();
    solve();
    cout << ans + W;
}