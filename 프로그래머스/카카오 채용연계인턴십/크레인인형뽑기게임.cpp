//
// Created by 김석찬 on 2023/11/21.
//

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {

    //board[0,0]은 맨 위 맨 왼
    int cnt=0;
    stack<int> s;
    for(auto i:moves){ // i가 움직이는 위치

        for(int j=0; j<board.size(); j++){
            if(board[j][i-1]!=0){
                int top=board[j][i-1];
                if(!s.empty() && s.top()==top){
                    cnt+=2;
                    s.pop();
                }
                else{
                    s.push(top);
                }
                board[j][i-1]=0;
                break;
            }
        }
    }
    int answer = cnt;
    return answer;
}

int main(){

}