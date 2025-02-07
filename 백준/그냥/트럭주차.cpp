//
// Created by 김석찬 on 2024/02/27.
//

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
vector<int> e;
int arr[4];
int ans;

int main() {
    for (int i = 1; i < 4; i++) {
        cin >> arr[i];
    }
    int a, b;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    std::sort(v.begin(), v.end(), greater<pair<int, int>>());


    int cnt = 1;

    while ((!v.empty() || !e.empty()) && cnt <= 100) {
        while (!v.empty() && v[v.size() - 1].first == cnt) {
            e.push_back(v[v.size() - 1].second);
            v.pop_back();
        }
        std::sort(e.begin(), e.end(), greater<int>());
        while (!e.empty() && e[e.size() - 1] == cnt) {
            e.pop_back();
        }
        ans += e.size()*arr[e.size()];
        cnt += 1;
    }
    cout << ans;
}