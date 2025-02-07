//
// Created by 김석찬 on 2023/07/20.
//

#include<iostream>
#include<list>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 10; i++) {
        list<int> a;
        int first, second, third, four;
        cin >> first;
        while (first--) {
            cin >> second;
            a.push_back(second);
        }
        cin >> third;
        int x, y;
        char k;
        while (third--) {
            cin >> k;

            if (k == 'I') {
                cin >> x >> y;
                auto iter = a.begin();

                for (int j = 0; j < x; j++) {
                    iter++;
                }

                for (int j = 0; j < y; j++) {
                    cin >> four;
                    a.insert(iter, four);
//                        iter++;
                }
            } else if (k == 'D') {
                cin >> x >> y;
                auto iter = a.begin();
                for (int j = 0; j < x; j++) {
                    iter++;
                }

                for (int j = 0; j < y; j++) {
                    iter = a.erase(iter);
                }
            } else if (k == 'A') {
                cin >> y;
                for (int j = 0; j < y; j++) {
                    cin >> four;
                    a.push_back(four);
                }
            }
        }

        auto iter = a.begin();

        cout << '#' << i << " ";
        for (int j = 0; j < 10; j++) {
            cout << *iter << " ";
            iter++;
        }
        cout << "\n";
    }
    return 0;
}