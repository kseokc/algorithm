//
// Created by 김석찬 on 2025/03/07.
//

#include<iostream>
#include<vector>


using namespace std;

vector<string> v1;
vector<string> v2;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v1.push_back(s);
    }
    for (int i = 0; i < n; i++) {
        cin >> s;
        v2.push_back(s);
    }
    int cnt = 0;
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (v1[i][j] != v2[i][j]) {
                for (int k = i; k < i + 3; k++) {
                    for (int p = j; p < j + 3; p++) {
                        if (v1[k][p] == '0')v1[k][p] = '1';
                        else v1[k][p] = '0';
                    }
                }
                cnt++;
            }
        }
    }


    //1.다른부분 처음에 정리 -> 하나씩 바꾸기 -> 끊임없이 바꾸기? -> 안되면 무한루프..
    //계속 바뀌는 문제
    //같은지 검사

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;

    return 0;
}