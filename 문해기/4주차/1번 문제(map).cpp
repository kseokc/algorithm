//
// Created by 김석찬 on 2024/09/29.
//

#include<iostream>-
#include<map>

using namespace std;

int T,n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>T;
    for(int testcase=0; testcase<T; testcase++){
        map<pair<char,string>,int>ScoreBoard;
        int Ascore=0; // 입력 받을 A팀의 점수
        int Bscore=0; // 입력 받을 B팀의 점수
        pair<string,int>preA={"",0}; // {A팀의 최고 득점자,A팀의 이전 점수}
        pair<string,int>preB={"",0}; // {B팀의 최고 득점자,B팀의 이전 점수}
        string player="";  // 득점 선수 이름

        cin>>n;
        for(int i=0; i<n; i++){
            cin>>Ascore>>Bscore>>player;
            if(preA.second!=Ascore){ //A팀이 득점을 했을때
                ScoreBoard[{'A',player}]+=(Ascore-preA.second); // 새로 득점을 올린 선수의 점수를 올린다.
                if(ScoreBoard[{'A',player}]>ScoreBoard[{'A',preA.first}]){ // 새로운 선수가 저 많이 득점을 했을경우
                    preA.first=player;
                }
                preA.second=Ascore;
            }else{
                ScoreBoard[{'B',player}]+=(Bscore-preB.second); // 새로 득점을 올린 선수의 점수를 올린다.
                if(ScoreBoard[{'B',player}]>ScoreBoard[{'B',preB.first}]){ // 새로운 선수가 저 많이 득점을 했을경우
                    preB.first=player;
                }
                preB.second=Bscore;
            }
        }
        if(Ascore>Bscore){
            cout<<preA.first<<" "<<ScoreBoard[{'A',preA.first}]<<'\n';
        }else{
            cout<<preB.first<<" "<<ScoreBoard[{'B',preB.first}]<<'\n';
        }

    }
}

