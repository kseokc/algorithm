//
// Created by 김석찬 on 2023/11/22.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ans = "";
    for (int i = 0; i < s.length(); i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            ans += s[i];
        } else {
            for (int j = 3; j < 6; j++) {
                if(i+j>s.length()){
                    break;
                }
                string num = s.substr(i, j);
                if(num=="zero"){
                    ans+='0';
                }else if(num=="one"){
                    ans+='1';
                }
                else if(num=="two"){
                    ans+='2';
                }
                else if(num=="three"){
                    ans+='3';
                }
                else if(num=="four"){
                    ans+='4';
                }
                else if(num=="five"){
                    ans+='5';
                }
                else if(num=="six"){
                    ans+='6';
                }
                else if(num=="seven"){
                    ans+='7';
                }
                else if(num=="eight"){
                    ans+='8';
                }
                else if(num=="nine"){
                    ans+='9';
                }
            }
        }
    }
    answer=stoi(ans);
    return answer;
}