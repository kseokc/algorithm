//
// Created by 김석찬 on 2023/02/09.
//

#include<iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int Arr[MAX];
int N, M;
int number[MAX];


bool find(int a, int first, int last) {

    if (first > last)return false;

    int mid = (first + last) / 2;

    if (Arr[mid] == a)return true;
    else if (Arr[mid] < a) return find(a, mid + 1, last);
    else return find(a, first, mid - 1);


}


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> number[i];
    }

    sort(Arr, Arr + N);

    for (int i = 0; i < M; i++) {
        if (find(number[i], 0, N - 1))cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}