//
// Created by 김석찬 on 2022/08/06.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int N;
int number;
int arr[20][20];
vector<int> C;
vector<int> team1;
vector<int> team2;


int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> number;
            arr[i][j] = number;
        }
        C.push_back(1);
    }
    for (int i = 0; i < N / 2; i++) {
        C[i] = 0;
    }
    std::sort(C.begin(), C.end());
    int Min = 1000000;
    do {
        for (int i = 0; i < N; i++) {
            if (C[i] != 0) {
                team1.push_back(i);
            } else {
                team2.push_back(i);
            }
        }
        int score1 = 0;
        int score2 = 0;
        for (int i = 0; i < team1.size(); i++) {
            for (int j = 0; j < team1.size(); j++) {
                if (team1[i] == team1[j])continue;
                score1 = score1 + arr[team1[i]][team1[j]];
            }
        }
        for (int i = 0; i < team2.size(); i++) {
            for (int j = 0; j < team2.size(); j++) {
                if (team2[i] == team2[j])continue;
                score2 = score2 + arr[team2[i]][team2[j]];
            }
        }

        Min = min(abs(score1 - score2), Min);
        team1.clear();
        team2.clear();
    } while (next_permutation(C.begin(), C.end()));
    cout<<Min;
}