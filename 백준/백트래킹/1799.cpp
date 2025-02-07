//
// Created by 김석찬 on 2022/11/17.
//

#include<iostream>

#include<vector>

using namespace std;
vector<pair<int, int>> ck_l;
bool ck[10][10];
vector<pair<int, int>> can1;
vector<pair<int, int>> can2;
int N, V, Max1, Max2;


bool available(int i, int j) {
    for (int k = 0; k < ck_l.size(); k++) {
        if (abs(ck_l[k].first - i) == abs(ck_l[k].second - j))return false;
    }
    return true;
}

void search1(int index, int count) {
    if (index == can1.size()) {
        Max1 = max(Max1, count);
        return;
    } else {
        for (int i = index; i < can1.size(); i++) {
            if ((!available(can1[i].first, can1[i].second)) || ck[can1[i].first][can1[i].second])continue;
            ck[can1[i].first][can1[i].second] = true;
            ck_l.emplace_back(can1[i].first, can1[i].second);
            search1(i + 1, count + 1);
            ck_l.pop_back();
            ck[can1[i].first][can1[i].second] = false;
        }
    }
}

void search2(int index, int count) {
    if (index == can2.size()) {
        Max2 = max(Max2, count);
        return;
    } else {
        for (int i = index; i < can2.size(); i++) {
            if ((!available(can2[i].first, can2[i].second)) || ck[can2[i].first][can2[i].second])continue;
            ck[can2[i].first][can2[i].second] = true;
            ck_l.emplace_back(can2[i].first, can2[i].second);
            search2(i + 1, count + 1);
            ck_l.pop_back();
            ck[can2[i].first][can2[i].second] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> V;
            if (V == 1) {
                if (i % 2 == 0) {
                    if (j % 2 == 0) {
                        can1.emplace_back(i, j);
                    } else {
                        can2.emplace_back(i, j);
                    }
                } else {
                    if (j % 2 == 0) {
                        can2.emplace_back(i, j);
                    } else {
                        can1.emplace_back(i, j);
                    }
                }

            }
        }
    }
    search1(0, 0);
    ck_l.clear();
    search2(0, 0);
    cout << Max1 + Max2;
}
