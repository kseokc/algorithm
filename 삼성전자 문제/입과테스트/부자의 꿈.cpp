//
// Created by 김석찬 on 2023/07/10.
//

//모든 셀의 곰팡이의 수는 다르다.
//어떠한 셀이 안전하다는 것은, 해당 셀과 같은 행, 혹은 같은 열에 있는 다른 셀 중 외계 곰팡이 개체 수가 더 높은 것이 없다는 것을 뜻한다.


#include<iostream>
#include<vector>

using namespace std;

int tc, N, M, Q;
int dp_r[200000];
int dp_c[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int p = 1; p <= tc; p++) {

        cin >> N >> M >> Q;

        int map[N][M];
        fill(dp_c, dp_c + M, 0);
        fill(dp_r, dp_r + N, 0);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> map[i][j];
                if (map[i][j] > map[i][dp_r[i]])dp_r[i] = j;
                if (map[i][j] > map[dp_c[j]][j])dp_c[j] = i;
            }
        }

        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dp_r[i] == j && dp_c[j] == i)count++;
            }
        }

        int r, c, value;

        int ans = 0;
        for (int i = 0; i < Q; i++) {
            cin >> r >> c >> value;
            bool flag1 = false;
            bool flag2 = false;

            if (dp_r[r - 1] == c - 1 && dp_c[c - 1] == r - 1) {
                map[r - 1][c - 1] = value;
                ans += count;
                continue;
            }

            if (value > map[r - 1][dp_r[r - 1]]) {
                if (dp_c[dp_r[r - 1]] == r - 1) {
                    count--;
                }
                flag1 = true;
            }
            if (value > map[dp_c[c - 1]][c - 1]) {

                if (dp_r[dp_c[c - 1]] == c - 1) {
                    count--;
                }
                flag2 = true;
            }

            if (flag1) { dp_r[r - 1] = c - 1; }
            if (flag2)dp_c[c - 1] = r - 1;

            map[r - 1][c - 1] = value;

            if ((flag1 || flag2) && dp_r[r - 1] == c - 1 && dp_c[c - 1] == r - 1) {
                count++;
            }

            ans += count;
        }
        cout << "#" << p << " " << ans << '\n';


    }
}
