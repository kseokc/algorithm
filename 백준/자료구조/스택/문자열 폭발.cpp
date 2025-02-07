//
// Created by 김석찬 on 2023/07/08.
//

#include<iostream>
#include<stack>
#include<vector>
#include<cstring>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    string boom;

    cin >> S >> boom;

    string ans;
    for (int i = 0; i < S.length(); i++) {
        ans.push_back(S[i]);
        if (boom.back() == ans.back()) {
            if (boom.length() > ans.length())continue;
            int del_idx = ans.length() - 2;
            bool flag = true;
            for (int j = boom.length() - 2; j >= 0; j--) {
                if (boom[j] != ans[del_idx]) {
                    flag = false;
                    break;
                }
                del_idx--;
            }
            if(flag)for(int j=0; j<boom.length(); j++)ans.pop_back();
        }
    }
    if(ans=="")cout<<"FRULA";
    else cout<<ans;

}

