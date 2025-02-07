#include <iostream>
using namespace std;

int N,M;

int arr[1025][1025];
int score[1025][2025];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==0 && j==0)score[i][j]=arr[i][j];
            else if(i==0)score[i][j]=arr[i][j]+score[i][j-1];
            else if(j==0)score[i][j]=arr[i][j]+score[i-1][j];
            else score[i][j]=arr[i][j]+score[i][j-1]+score[i-1][j]-score[i-1][j-1];
        }
    }

    int x1,x2,y1,y2;
    for(int i=0; i<M; i++){
        cin>>x1>>y1>>x2>>y2;
        int ans;
        if(x1==1 && y1==1)ans=score[x2-1][y2-1];
        else if(y1==1)ans=score[x2-1][y2-1]-score[x1-2][y2-1];
        else if(x1==1)ans=score[x2-1][y2-1]-score[x2-1][y1-2];
        else ans=score[x2-1][y2-1]-score[x2-1][y1-2]-score[x1-2][y2-1]+score[x1-2][y1-2];

        cout<<ans<<'\n';

    }

}



//
// Created by 김석찬 on 2024/11/19.
//

