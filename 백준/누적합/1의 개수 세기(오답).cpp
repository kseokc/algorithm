//
// Created by 김석찬 on 2024/07/13.
//

//두 자연수 A, B가 주어졌을 때, A ≤ x ≤ B를 만족하는 모든 x에 대해 x를 이진수로 표현했을 때 1의 개수의 합을 구하는 프로그램을 작성하시오.
//
//즉, f(x) = x를 이진수로 표현 했을 때 1의 개수라고 정의하고, 아래 식의 결과를 구하자.



// 10 = 1010
// 1 = 1
//
// 100 = 1100100

#include <iostream>
#include <vector>
#include <math.h>


/*
 *    0
 *    1
 *   10
 *   11
 *  100
 *  101
 *  110
 *  111
 * 1000
 * 1001
 * 1010
 * 1011
 * 1100
 * 1101
 * 1110
 * 1111
 * 10000
 * 10001
 * 10010
 * 10011
 * 10100
 * 10101
 * 10110
 * 10111
 * 11000
 * 11001
 * 11010
 * 11011
 * 11100
 * 11101
 * 11110
 * 11111
 *
 *
 */

using namespace std;
long long A,B;
long long oneNum[51];

string calculate(long long x){
    vector<int>v;
    string result="";
    while(x!=1){
        int d;
        int m;
        m=x%2;
        x=x/2;
        v.push_back(m);
    }
    v.push_back(1);
    for(int i=v.size()-1; i>=0; i--){
        char c=v[i]+'0';
        result.push_back(c);
    }
    return result;
}

long sol(string x){
    cout<<x<<'\n';
    long long ans=0;
    int size=x.size();
    for(int i=1; i<size; i++){

        ans+=oneNum[size-i];

    }
    cout<<ans<<'\n';
    return ans;
}

int main(){
    cin>>A>>B;

    oneNum[1]=1;
    for(int i=2; i<51; i++){
        oneNum[i]=pow(2,i-1)+oneNum[i-1]*2;
    }
    cout<<oneNum[2]<<'\n';

    cout<<sol(calculate(B))-sol(calculate(A-1));

}