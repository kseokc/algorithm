//
// Created by 김석찬 on 2023/07/07.
//

#include<iostream>
#include<stack>

#define MAX 500001
using namespace std;

stack<pair<int, int>> build;
int result[MAX];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int height;
    for (int i = 1; i <= N; i++) {
        cin >> height;
        while (!build.empty() && build.top().second < height)build.pop();
        if (build.empty()) result[i] = 0;
        else result[i] = build.top().first;
        build.push({i, height});
    }
    for (int i = 1; i <= N; i++)cout << result[i] << " ";
}
