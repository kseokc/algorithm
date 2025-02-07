//
// Created by 김석찬 on 2023/11/22.
//

#include<iostream>
#include<vector>
//두엄지 손가락 위치가 같을때는 오른손잡이는 오른쪽손 왼속 잡이는 왼손으
// 1 2 3
// 4 5 6
// 7 8 9
// * 0 #

#include <string>
#include <vector>

int i;
int j;
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left={0,3};
    pair<int,int> right={2,3};
    for(auto num: numbers){
        if(num!=0){
            i=(num-1)/3; // y축의 위치
            j=(num-1)%3; // x축의 위치
        }else{
            j=1;
            i=3;
        }

        switch (num) {
            case 1:
            case 4:
            case 7:
                left={j,i};
                answer+='L';
                break;
            case 3:
            case 6:
            case 9:
                answer+='R';
                right={j,i};
                break;
            default:
                if(abs(left.first-j)+abs(left.second-i)>abs(right.first-j)+abs(right.second-i)){
                    right={j,i};
                    answer+='R';
                }else if(abs(left.first-j)+abs(left.second-i)==abs(right.first-j)+abs(right.second-i)){
                    if(hand=="right"){
                        right={j,i};
                        answer+='R';
                    }
                    else{
                        left={j,i};
                        answer+='L';
                    }
                }else{
                    left={j,i};
                    answer+='L';
                }
                break;
        }
    }

    return answer;
}