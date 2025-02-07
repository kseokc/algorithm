//
// Created by 김석찬 on 2023/07/07.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define phone 10

bool flag = false;

struct Trienode {
    int next[phone];
    bool finsh;

    Trienode() {
        fill(next, next + phone, -1);
        finsh = false;
    }
};

class Trie {
private:
    vector<Trienode> node;

public:
    Trie() : node(1) {}

    void insert(const string &number) {
        int idx = 0;
        for (auto &s: number) {
            if (node[idx].next[s - '0'] == -1) {
                node[idx].next[s - '0'] = node.size();
                node.emplace_back();
            }
            if (node[idx].finsh) {
                flag = true;
                return;
            }
            idx = node[idx].next[s - '0'];
        }
        node[idx].finsh = true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    int Case;
    cin >> tc;

    while (tc--) {
        flag = false;
        Trie trie;
        string phonenumber[10001];
        cin >> Case;
        for (int i = 0; i < Case; i++) {
            cin >> phonenumber[i];
        }

        sort(phonenumber, phonenumber + Case);

        for (int i = 0; i < Case; i++) {
            trie.insert(phonenumber[i]);
            if (flag){
                break;
            }
        }
        if(!flag)cout << "YES\n";
        else cout<<"NO\n";
    }
}


