//
// Created by 김석찬 on 2022/07/27.
//
#include<iostream>
#include<map>

using namespace std;
multimap<int, int> m;

int main() {
    int tc;
    int strat, last;
    cin >> tc;
    while (tc--) {
        cin >> strat >> last;
        m.insert({strat, last});
    }
    int count = 1;
    auto iter = m.begin();
    while (1) {
        if (iter == m.end()) {
            count++;
            iter = m.begin();
        }
        multimap<int, int>::iterator del = iter;
        iter = m.lower_bound(iter->second);
        m.erase(del);
        if (m.empty()) {
            break;
        }
    }
    cout << count;
}
