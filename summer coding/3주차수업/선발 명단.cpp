//
// Created by 김석찬 on 2022/08/10.
//

#include<iostream>

using namespace std;
int player[11][11];
bool posi[11];
int tc, score;
int Max;

void search(int count, int sum) {
    if (count == 11) {
        Max = max(Max, sum);
    } else {
        for (int i = 0; i < 11; i++) {
            if (player[i][count] == 0)continue;
            if (posi[i])continue;
            posi[i] = true;
            sum = sum + player[i][count];
            search(count + 1, sum);
            sum = sum - player[i][count];
            posi[i] = false;
        }
    }
    return;
}

int main() {
    cin >> tc;
    while (tc--) {
        Max=0;
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> score;
                player[i][j] = score;
            }
        }
        search(0, 0);
        cout << Max << '\n';
    }
}