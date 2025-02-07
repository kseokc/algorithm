//
// Created by 김석찬 on 2022/08/09.
//

#include<iostream>
#include<vector>

using namespace std;

int direc; //0->왼 1->오 2->위 3->아
vector<int> dirc;
int N, number;
int Max;
int arr[20][20];

void search() {
    if (dirc.size() == 5) {
        int arr_1[20][20];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr_1[i][j] = arr[i][j];
            }
        }

        for (int i = 0; i < 5; i++) {
            if (dirc[i] == 0) {
                for (int j = 0; j < N; j++) {
                    for (int k = 1; k < N; k++) {
                        int count = 1;
                        while (k - count != 0 && arr[i][k - count] == 0) {
                            arr_1[i][k - count] = arr_1[i][k - count + 1];
                            arr_1[i][k - count + 1] = 0;
                            count++;
                        }
                        if (arr_1[i][k - count] == arr_1[i][k - count + 1]) {
                            arr_1[i][k - count] = arr_1[i][k - count + 1] * 2;
                            arr_1[i][k - count + 1] = 0;
                        }
                        else if(arr_1[i][k-count]==0){
                            arr_1[i][k - count] = arr_1[i][k - count + 1];
                            arr_1[i][k - count + 1] = 0;
                        }
                    }
                }
            } else if (dirc[i] == 1) {
                for (int j = 0; j < N; j++) {
                    for (int k = N - 2; k >= 0; k--) {
                        int count = 1;
                        while (k + count != N - 1 && arr[i][k + count] == N - 1) {
                            arr_1[i][k + count] = arr_1[i][k + count + 1];
                            arr_1[i][k + count - 1] = 0;
                            count++;
                        }
                        if (arr_1[i][k + count] == arr_1[i][k + count - 1]) {
                            arr_1[i][k + count] = arr_1[i][k + count - 1] * 2;
                            arr_1[i][k + count - 1] = 0;
                        }
                        else if(arr_1[i][k+count]==0){
                            arr_1[i][k + count] = arr_1[i][k + count - 1];
                            arr_1[i][k + count - 1] = 0;
                        }
                    }
                }
            } else if (dirc[i] == 2) {
                for (int j = 0; j < N; j++) {
                    for (int k = 1; k < N; k++) {
                        int count = 1;
                        while (k - count != 0 && arr[k - count][i] == 0) {
                            arr_1[k - count][i] = arr_1[k - count + 1][i];
                            arr_1[k - count + 1][i] = 0;
                            count++;
                        }
                        if (arr_1[k - count][i] == arr_1[k - count + 1][i]) {
                            arr_1[k - count][i] = arr_1[k - count + 1][i] * 2;
                            arr_1[k - count + 1][i] = 0;
                        }
                        else if(arr_1[k-count][i]==0){
                            arr_1[k - count][i] = arr_1[k - count + 1][i];
                            arr_1[k - count + 1][i] = 0;
                        }
                    }
                }
            } else if (dirc[i] == 3) {
                for (int j = 0; j < N; j++) {
                    for (int k = N - 2; k >= 0; k--) {
                        int count = 1;
                        while (k + count != N - 1 && arr[k + count][i] == 0) {
                            arr_1[k + count][i] = arr_1[k + count - 1][i];
                            arr_1[k + count - 1][i] = 0;
                            count++;
                        }
                        if (arr_1[k + count][i] == arr_1[k + count - 1][i]) {
                            arr_1[k + count][i] = arr_1[k + count - 1][i] * 2;
                            arr_1[k + count - 1][i] = 0;
                        }
                        else if(arr_1[k+count][i]==0){
                            arr_1[k + count][i] = arr_1[k + count - 1][i];
                            arr_1[k + count - 1][i] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                Max = max(Max, arr_1[i][j]);
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            dirc.push_back(i);
            search();
            dirc.pop_back();
        }
    }
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> number;
            arr[i][j] = number;
        }
    }
    search();
    cout << Max;
}