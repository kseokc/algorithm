//
// Created by 김석찬 on 2022/08/01.
//

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define number 40000
vector<int> primeNum(40001);
vector<int> primesum;
int Find[40001];

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

    for(int i=2; i<=number; i++){
        if(primeNum[i]!=0){
            primesum.push_back(i);
        }
    }

}

int main(){
    int num;
    cin>>num;
    pN();

    Find[0]=1;
    for(int i=0; i<primesum.size(); i++){
        for(int j=primesum[i]; j<=num; j++){
            Find[j]=Find[j]+Find[j-primesum[i]];
            Find[j]%=123456789;
        }
    }
    cout<<Find[num];
}