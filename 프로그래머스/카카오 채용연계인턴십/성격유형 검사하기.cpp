//
// Created by 김석찬 on 2023/11/14.
//

//매우동의 매우비동의 -3,3점씩 받는다.
// 동의 비동의 2,-2점씩 받는다.
// 두성격유형중에 높은 점수를 받은 쪽이 성격유형이되고 같을때는 사전 순으로 정의가된다.
// survey 문자열 배열이 들어오고 첫번쨰는 비동의 두번쨰는 동의로 생각한다.
//choice는 1~7까지있고  1이 매우 비동의 7이 매우 동의

//R,T   C,F   J,M   A,N

#include<iostream>
#include <map>

using namespace std;

// 1,7->3   2,6->2   3,5->1   4->0

int main(){
    map<char,int> m;
    string mbti[1000];
    int score[1000];
    for(int i=0; i<5; i++){
        cin>>mbti[i];
    }
    for(int i=0; i<5; i++){
        cin>>score[i];
    }
    for(int i=0; i<5; i++){
        switch (score[i]) {
            case 1:
                m[mbti[i][0]]+=3;
                break;
            case 2:
                m[mbti[i][0]]+=2;
                break;
            case 3:
                m[mbti[i][0]]+=1;
                break;
            case 5:
                m[mbti[i][1]]+=1;
                break;
            case 6:
                m[mbti[i][1]]+=2;
                break;
            case 7:
                m[mbti[i][1]]+=3;
                break;
        }
    }
    string result="RCJA";
    result[0]=m[result[0]]>=m['T']?result[0]:'T';
    result[1]=m[result[1]]>=m['F']?result[1]:'F';
    result[2]=m[result[2]]>=m['M']?result[2]:'M';
    result[3]=m[result[3]]>=m['N']?result[3]:'N';
    cout<<result;
}