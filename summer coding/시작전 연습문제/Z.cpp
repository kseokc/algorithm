//
// Created by 김석찬 on 2022/07/18.
//

#include<iostream>

using namespace std;


int func1(int a,int b,int N){
    int count=0;
    if(N==0){
        return 0;
    }
    if(a/N==1 && b/N==1){
        count=N*N*3;
        count=count+func1(a%N,b%N,N/2);
    }
    else if(a/N==0 && b/N==1){
        count=N*N*2;
        count=count+func1(a%N,b%N,N/2);
    }
    else if(a/N==1 && b/N==0){
        count=N*N*1;
        count=count+func1(a%N,b%N,N/2);
    }
    else if(a/N==0 && b/N==0){
        count=count+func1(a%N,b%N,N/2);
    }
    return count;
}

int main(){
    int tc,r,c;
    cin>>tc>>r>>c;
    int N=(1<<tc);
    cout<<func1(c,r,N/2);
}

