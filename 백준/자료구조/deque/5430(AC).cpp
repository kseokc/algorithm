//
// Created by 김석찬 on 2023/07/04.
//

#include<iostream>
#include<deque>

using namespace std;
int tc, n;
string cmd, arr;

deque<int> make_dequeue(string S) {
    string num = "";
    deque<int> result;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '[' || S[i] == ']' || S[i] == ',') {
            if (num == "")continue;
            int number = stoi(num);
            result.push_back(number);
            num = "";
        } else {
            num += S[i];
        }

    }
    return result;
}

int main() {
    cin >> tc;
    while (tc--) {

        cin >> cmd >> n >> arr;

        deque<int> result = make_dequeue(arr);
        bool reverse = false;
        bool empty = true;

        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') {
                reverse = !reverse;
            } else {
                if (result.empty()) {
                    cout << "error\n";
                    empty = false;
                    break;
                }
                if (reverse)result.pop_back();
                else result.pop_front();
            }
        }
        string ans = "[";
        if (empty) {
            while (!result.empty()) {
                if (reverse) {
                    ans += to_string(result.back());
                    result.pop_back();
                } else {
                    ans += to_string(result.front());
                    result.pop_front();
                }
                ans += ',';
            }
            if( ans[ans.length() - 1] == ',') ans[ans.length() - 1] = ']';
            else ans+=']';
            cout << ans << '\n';
        }
    }
}
