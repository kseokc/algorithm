//
// Created by 김석찬 on 2022/08/08.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int cnt, n, m, k, skill, Max;
vector<int> skillbook[100];
bool check[21];

void search(int t, int index) {
    if (t > 2 * n) {
        if (index != n)return;
    }
    if (index == n) {
        cnt = 0;
        for (int i = 0; i < m; i++) {
            bool ok = true;
            for (int j = 0; j < k; j++) {
                if (!check[skillbook[i][j]]) {
                    ok = false;
                    break;
                }
            }
            if (ok)cnt++;
        }
        Max = max(Max, cnt);
        return;
    } else {
        check[t] = true;
        search(t + 1, index + 1);
        check[t] = false;
        search(t + 1, index);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> skill;
            skillbook[i].push_back(skill);
        }
    }

    search(1, 0);

    cout << Max;
}