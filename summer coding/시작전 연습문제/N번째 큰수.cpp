//
// Created by 김석찬 on 2022/07/17.
//

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x,v;
    int* arr;
    cin>>x;
    int t= x * x;
    arr= new int[t];
    for(int i = 0; i < t; i++){
        cin >> v;
        arr[i] = v;
    }

    sort(arr,arr+t);
    cout << arr[t-x];

}