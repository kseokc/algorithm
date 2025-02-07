//
// Created by 김석찬 on 2022/08/01.
//

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define number 10000000
vector<int> primeNum(10000001);


void pN() {
    for (int i = 2; i <= number; i++) {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (primeNum[i] == 0)
            continue;

        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }
}

int main(){
    int num;
    cin>>num;
    int index=2;
    pN();
    while(num!=1){
        if(primeNum[index]!=0){
            if(num%primeNum[index]==0){
                num/=primeNum[index];
                cout<<primeNum[index]<<'\n';
            }
            else{
                index+=1;
            }
        }
        else{
            index+=1;
        }
    }
}