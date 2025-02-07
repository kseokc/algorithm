//
// Created by 김석찬 on 2022/07/26.
//

#include<iostream>
using namespace std;

struct node{
    node* next;
    bool have;
    int R;
    int C;
    node(){
        next= nullptr;
        have= false;
    }
};

bool apple[100][100];
node* snake[100][100];
char direc[10001];
int row,col;
char change;
int tc;
int value;
int N;

int main(){
    cin>>N;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            snake[i][j] = new node();
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            snake[i][j]->R=i;
            snake[i][j]->C=j;
        }
    }
    cin>>tc;

    while(tc--){
        cin>>row>>col;
        apple[row-1][col-1]=true;
    }

    cin>>tc;

    while(tc--){
        cin>>value>>change;
        direc[value]=change;
    }

    int time=1;
    int D=1; // 1: right, 2: left 3: up, 4:down;
    row=0;
    col=0;
    snake[row][col]->have=true;
    pair<int,int> roc;// 꼬리의 위치
    roc.first=row;
    roc.second=col;

    while(1){
        int last_r=roc.first;
        int last_c=roc.second;
        if(D==1){
            col+=1;
            if(col>=N || snake[row][col]->have==true){
                cout<<time;
                break;
            }

            snake[row][col]->have=true;
            snake[row][col-1]->next=snake[row][col];

            if(apple[row][col]!=true){
                snake[last_r][last_c]->have=false;
                roc.first=snake[last_r][last_c]->next->R;
                roc.second=snake[last_r][last_c]->next->C;
                snake[last_r][last_c]->next= nullptr;
            }else{
                apple[row][col]=false;
            }
        }
        else if(D==2){
            col-=1;
            if(col<0 || snake[row][col]->have==true){
                cout<<time;
                break;
            }
            snake[row][col]->have=true;
            snake[row][col+1]->next=snake[row][col];

            if(apple[row][col]!=true){
                snake[last_r][last_c]->have=false;
                roc.first=snake[last_r][last_c]->next->R;
                roc.second=snake[last_r][last_c]->next->C;
                snake[last_r][last_c]->next= nullptr;
            }
            else{
                apple[row][col]=false;
            }
        }
        else if(D==3){
            row-=1;
            if(row<0 || snake[row][col]->have==true){
                cout<<time;
                break;
            }

            snake[row][col]->have=true;
            snake[row+1][col]->next=snake[row][col];

            if(apple[row][col]!=true){
                snake[last_r][last_c]->have=false;
                roc.first=snake[last_r][last_c]->next->R;
                roc.second=snake[last_r][last_c]->next->C;
                snake[last_r][last_c]->next= nullptr;
            }
            else{
                apple[row][col]=false;

            }
        }
        else if(D==4){
            row+=1;
            if(row>=N || snake[row][col]->have==true){
                cout<<time;
                break;
            }

            snake[row][col]->have=true;
            snake[row-1][col]->next=snake[row][col];

            if(apple[row][col]!=true){
                snake[last_r][last_c]->have=false;
                roc.first=snake[last_r][last_c]->next->R;
                roc.second=snake[last_r][last_c]->next->C;
                snake[last_r][last_c]->next= nullptr;
            }
            else{
                apple[row][col]=false;
            }
        }

        if(direc[time]!=' '){
            if(D==1){
                if(direc[time]=='L')D=3;
                else if(direc[time]=='D')D=4;
            }
            else if(D==2){
                if(direc[time]=='L')D=4;
                else if(direc[time]=='D')D=3;
            }
            else if(D==3){
                if(direc[time]=='L')D=2;
                else if(direc[time]=='D')D=1;
            }
            else if(D==4){
                if(direc[time]=='L')D=1;
                else if(direc[time]=='D')D=2;
            }
        }
        time++;
    }

}
