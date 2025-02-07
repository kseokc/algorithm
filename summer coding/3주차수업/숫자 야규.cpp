//
// Created by 김석찬 on 2022/08/07.
//

#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> score;
vector<string> base;
vector<int> result;
bool number[9];
int N, st, ball, cnt;
string s;

void serach() {
    if (result.size() == 3) {
        bool good = true;
        for (int i = 0; i < N; i++) {
            int b_cnt = 0, s_cnt = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (result[j] == (base[i][k] - '0')) {
                        if (j != k)b_cnt++;
                        else s_cnt++;
                    }
                }
            }
            if (score[i].first != s_cnt || score[i].second != b_cnt)good = false;
        }
        if (good)cnt++;
        return;
    } else {
        for (int i = 1; i < 10; i++) {
            if (number[i])continue;
            number[i] = true;
            result.push_back(i);
            serach();
            result.pop_back();
            number[i] = false;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s >> st >> ball;
        score.emplace_back(st, ball);
        base.push_back(s);
    }
    serach();
    cout<<cnt;
}