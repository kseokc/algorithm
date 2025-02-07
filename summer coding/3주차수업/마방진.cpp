//
// Created by 김석찬 on 2022/08/08.
//

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string word;
vector<string> S;
vector<string> arr;
bool check[20];
int N, L, cnt;

void search(int idx) {
    if (idx == L) {
        bool good = true;
        for (int i = 1; i < L; i++) {
            for (int j = 0; j != i; j++) {
                if (arr[j][i] != arr[i][j])good = false;
            }
        }
        if (good) {
            cnt++;
            if (cnt == 1) {
                for (int i = 0; i < L; i++) {
                    cout << arr[i] << "\n";
                }
            }
        }
    } else {
        for (int i = 0; i < N; i++) {
            if (check[i])continue;
            arr.push_back(S[i]);
            check[i] = true;
            search(idx+1);
            check[i] = false;
            arr.pop_back();
        }
    }
    return;
}

int main(){
    cin>>L>>N;
    for(int i=0; i<N; i++){
        cin>>word;
        S.push_back(word);
    }
    std::sort(S.begin(), S.end());
    search(0);
    if(cnt==0){
        cout<<"NONE\n";
    }
}

