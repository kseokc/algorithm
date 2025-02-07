//
// Created by 김석찬 on 2023/07/21.
//

#include<iostream>
#include<list>

using namespace std;

int T, N, M, L;

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {

        list<int> a;
        cin >> N >> M >> L;
        int size = N;
        while (N--) {
            int number;
            cin >> number;
            a.push_back(number);
        }
        char s;
        while (M--) {
            cin >> s;
            if (s == 'I') {
                int number, index;
                cin >> index >> number;
                auto iter = a.begin();
                for (int i = 1; i < index; i++)iter++;
                a.insert(iter, number);
                size++;
            } else if (s == 'D') {
                if (a.empty())continue;
                int index;
                cin >> index;
                auto iter = a.begin();
                for (int i = 0; i < index; i++)iter++;
                a.erase(iter);
                size--;
            } else if (s == 'C') {
                int index, number;
                cin >> index >> number;
                auto iter = a.begin();
                for (int i = 0; i < index; i++) {
                    iter++;
                }
                *iter = number;
            }
        }
        if (size < L)cout << '#' << tc << " -1\n";
        else {
            auto iter = a.begin();
            for (int i = 0; i < L; i++) {
                iter++;
            }
            cout<<'#'<<tc<<" " << *iter << '\n';
        }
    }
}