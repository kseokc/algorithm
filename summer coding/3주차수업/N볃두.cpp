//
// Created by 김석찬 on 2022/08/10.
//

#include <iostream>
#include<vector>

using namespace std;

int n, ans;
bool ck[18][18];
vector<pair<int,int>> ck_d;
int eorkr[15];

bool availQueen(int i, int j) {
    for(int k=0; k<ck_d.size(); k++){
        if(ck_d[k].first-i==0 || ck_d[k].second-j==0 || abs(ck_d[k].first-i)==abs(ck_d[k].second-j))return false;
    }
    return true;
}

void sol(int i) {
    if (i == n) {
        ans++;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!availQueen(i, j)) continue;
        ck[i][j] = true;
        ck_d.emplace_back(i,j);
        sol(i + 1);
        ck_d.pop_back();
        ck[i][j] = false;
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    sol(0);
    cout << ans;
}