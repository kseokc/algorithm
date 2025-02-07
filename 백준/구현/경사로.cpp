//
// Created by 김석찬 on 2024/07/10.
//

#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<vector<int>> vRow;
vector<vector<int>> vCol;

int ans;

void sol(vector<int> street, int Q, string role) {
    bool ok = true;
    int connect = 1;
    bool down = false;
    for (int i = 0; i < street.size() - 1; i++) {
        int cnt = street[i];
        int nxt = street[i + 1];
        if (abs(cnt - nxt) == 1) {
            if (nxt - cnt < 0) {
                if (down) {
                    if (connect < L) {
                        ok = false;
                        break;
                    }
                }
                down = true;
            } else {
                if (connect < L || down) {
                    ok = false;
                    break;
                }
            }
            connect = 1;
        } else if (cnt - nxt == 0) {
            connect += 1;
            if (down && connect >= L) {
                connect -= L;
                down = false;
            }
        } else {
            ok = false;
            break;
        }

    }

    if(down && L<=connect)down=false;
    if (ok && !down) {
        ans += 1;
    }
}

// 각 행열을 첫번째 부분만 확인을 하면 된다.
int main() {
    cin >> N >> L;
    int value;
    vRow.resize(101);
    vCol.resize(101);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> value;
            vRow[i].push_back(value);
            vCol[j].push_back(value);
        }
    }
    for (int i = 0; i < N; i++) {
        sol(vRow[i], i, "row");
        sol(vCol[i], i, "col");
    }
    cout << ans;


}