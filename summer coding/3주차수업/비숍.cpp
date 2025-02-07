//
// Created by 김석찬 on 2022/08/10.
//

#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> ck_l;
bool ck[10][10];
vector<pair<int, int>> can;
vector<pair<int, int>> can1;
int N, V, Max1,Max2;

bool available(int i, int j) {
    for (int k = 0; k < ck_l.size(); k++) {
        if (abs(ck_l[k].first - i) == abs(ck_l[k].second - j))return false;
    }
    return true;
}


void search1(int index, int count) {
    if (index == can.size()) {
        Max1 = max(Max1, count);
        return;
    } else {
        for (int i = index; i < can.size(); i++) {
            if (!available(can[i].first, can[i].second))continue;
            ck[can[i].first][can[i].second] = true;
            ck_l.emplace_back(can[i].first, can[i].second);
            search1(i + 1, count + 1);
            ck_l.pop_back();
            ck[can[i].first][can[i].second] = false;
        }
    }
    return;
}

void search2(int index, int count) {
    if (index == can1.size()) {
        Max2 = max(Max2, count);
        return;
    } else {
        for (int i = index; i < can.size(); i++) {
            if (!available(can1[i].first, can1[i].second))continue;
            ck[can1[i].first][can1[i].second] = true;
            ck_l.emplace_back(can1[i].first, can1[i].second);
            search2(i + 1, count + 1);
            ck_l.pop_back();
            ck[can1[i].first][can1[i].second] = false;
        }
    }
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> V;
            if (V == 1) {
                if(j%2==0 && i%2!=0)can.emplace_back(i, j);
                else if(j%2!=0&&i%2==0)can1.emplace_back(i,j);

            }
        }
    }
    search1(0, 0);
    search1(0,0);
    cout << max(Max1,Max2);
}
