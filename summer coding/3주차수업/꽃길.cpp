//
// Created by 김석찬 on 2022/08/09.
//

#include<iostream>
#include<vector>

using namespace std;
int N, gold;
int arr[10][10];
bool ok[10][10];
int dx[4]{0, 0, -1, 1};
int dy[4]{-1, 1, 0, 0};
int Min = 10000;

bool search(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int x = j + dx[k];
        int y = i + dy[k];
        if (ok[y][x])return false;
    }
    return true;
}

int sumgold(int i, int j) {
    int sum = 0;
    for (int k = 0; k < 4; k++) {
        int x = j + dx[k];
        int y = i + dy[k];
        sum += arr[y][x];
    }
    sum += arr[i][j];
    return sum;
}

void buy(int i, int j, int un) {
    if (un == 1) {
        for (int k = 0; k < 4; k++) {
            int x = j + dx[k];
            int y = i + dy[k];
            ok[y][x] = true;
        }
        ok[i][j] = true;
    } else {
        for (int k = 0; k < 4; k++) {
            int x = j + dx[k];
            int y = i + dy[k];
            ok[y][x] = false;
        }
        ok[i][j] = false;
    }

}

void flower(int count, int sum) {
    if (count == 3) {
        Min = min(Min, sum);
        return;
    } else {
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < N - 1; j++) {
                if (search(i, j)) {
                    buy(i, j, 1);
                    sum = sum + sumgold(i, j);
                    flower(count + 1, sum);
                    sum = sum - sumgold(i, j);
                    buy(i, j, -1);
                }
            }
        }
        return;
    }

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gold;
            arr[i][j] = gold;
        }
    }
    flower(0, 0);
    cout << Min;
}