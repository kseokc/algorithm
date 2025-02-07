//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> arr;
vector<int> loto;
int n;

void search(vector<int> p, int k) {
    if (k == n) {
        if (arr.size() == 0)return;
        if (arr.size() == 6) {
            for (int i = 0; i < 6; i++)cout << arr[i] << " ";
            cout << endl;
            return;
        } else {
            return;
        }
    } else {
        arr.push_back(p[k]);
        search(p, k + 1);
        arr.pop_back();
        search(p, k + 1);
    }
    return;
}

int main() {
    int m;
    while (1) {
        loto.clear();
        cin >> n;
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            cin >> m;
            loto.push_back(m);
        }

        search(loto, 0);
        cout << '\n';
    }


}