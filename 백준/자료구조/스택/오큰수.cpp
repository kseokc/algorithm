//
// Created by 김석찬 on 2023/07/06.
//

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    vector<int> S;
    stack<int> Stack;
    stack<int> result;
    int N, K;
    cin >> N;
    while (N--) {
        cin >> K;
        S.push_back(K);
    }
    for (int i = S.size() - 1; i >= 0; i--) {
        while (!Stack.empty() && Stack.top() <= S[i]) {
            Stack.pop();
        }
        if (Stack.size() == 0)result.push(-1);
        else result.push(Stack.top());
        Stack.push(S[i]);
    }

    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }

}

