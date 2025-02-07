//
// Created by 김석찬 on 2023/11/25.
//

#include<iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int s;
int f[51][2];
int score[51][51];
int ans[51];
map<string, int> m;

int solution(vector<string> friends, vector<string> gifts) {
    s = friends.size();
    for (int i = 0; i < s; i++) {
        m.insert({friends[i], i});
    }
    for (auto i: gifts) {
        bool can = true;
        string Front = "";
        string Back = "";
        for (auto j: i) {
            if (j == ' ') {
                can = false;
            } else {
                if (can) {
                    Front += j;
                } else {
                    Back += j;
                }
            }
        }
        score[m[Front]][m[Back]] += 1; // 선물을준사람 누구에게 선물을 주었는지
        f[m[Front]][0] += 1; // 선물을 준사람의 선물지수 +1
        f[m[Back]][0] -= 1; //선물을 받은 사람의 선물지수 -1
    }
    int answer = 0;
    for (int i = 0; i < s; i++) { // 준사람
        for(int j=0; j<s; j++){ // 받은사람
            if(score[i][j]>score[j][i]){
                ans[i]+=1;
            }else if(score[i][j]==score[j][i]){
                if(f[i][0]+f[i][1]>f[j][0]+f[j][1]){
                    ans[i]+=1;
                }
            }
        }
        answer=max(answer,ans[i]);
    }


    return answer;
}


int main() {

}