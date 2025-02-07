//
// Created by 김석찬 on 2023/06/28.
//

#include<iostream>
#include<vector>

using namespace std;

int puzzle[9][9];
vector<pair<int, int>> zero;
int flag;

void input() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> puzzle[i][j];
            if (puzzle[i][j] == 0)zero.push_back({j, i});
        }
    }
}

bool check(int x, int y, int number) {
    //가로확인
    for (int i = 0; i < 9; i++) {
        if (puzzle[y][i] == number && i != x)return false;
    }
    for (int i = 0; i < 9; i++) {
        if (puzzle[i][x] == number && i != y)return false;
    }
    for (int i = (y / 3) * 3; i < (y / 3) * 3 + 3; i++) {
        for (int j = (x / 3) * 3; j < (x / 3) * 3 + 3; j++) {
            if (puzzle[i][j] == number && i != y && j != x)return false;
        }
    }
    return true;
}

void solve(int number) {
    if (zero.size() == number) {
        flag = true;
        return;
    }
    for (int i = 1; i < 10; i++) {
        puzzle[zero[number].second][zero[number].first] = i;
        if (check(zero[number].first, zero[number].second, i))solve(number + 1);
        if (flag)return;
    }

    puzzle[zero[number].second][zero[number].first] = 0;
    return;
}

void print() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << puzzle[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    input();
    solve(0);
    print();
}