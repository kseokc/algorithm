//
// Created by 김석찬 on 2022/08/09.
//

#include<iostream>

using namespace std;
string word[50];
string S;
bool check[26];
int N, K;
int Max;

void search(int count, int t) {
    if (K - 5 == count) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            bool good = true;
            for (int j = 0; j < word[i].length(); j++) {
                if (!check[word[i][j] - 'a']) {
                    good = false;
                    break;
                }
            }
            if (good)cnt++;
        }
        Max = max(Max, cnt);
    } else {
        for (int i = t; i < 26; i++) {
            if (check[i])continue;
            check[i] = true;
            search(count + 1, i + 1);
            check[i] = false;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> S;
        word[i] = S;
    }

    check[0] = true;
    check[2] = true;
    check[8] = true;
    check[13] = true;
    check[19] = true;


    if (K == 26) {
        cout << N;
    } else if (K - 5 < 0) {
        cout << 0;
    } else {
        search(0, 0);
        cout << Max;
    }

}