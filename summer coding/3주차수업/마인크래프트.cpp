//
// Created by 김석찬 on 2022/08/10.
//

#include<iostream>
#include<vector>

using namespace std;
int inven, N, M, height, Time;
int H[257];
pair<int,int> Min = {100000000,0};
int Max_h;
int Min_h = 256;

int main() {
    cin >> N >> M >> inven;
    for (int i = 0; i < N * M; i++) {
        cin >> height;
        H[height]++;
        Min_h = min(Min_h, height);
        Max_h = max(Max_h, height);
    }
    for (int i = Min_h; i <= Max_h; i++) {
        int stand = i;
        bool good = true;
        int want =  0;
        Time = 0;
        for (int j = Max_h; j >= Min_h; j--) {
            if (j == stand)continue;
            if (j < stand) {
                want = want + H[j] * (stand - j);
                Time = Time + H[j] * (stand - j);
            } else if (j > stand) {
                want = want - H[j] * (j - stand);
                Time = Time + H[j] * 2 * (j - stand);
            }
        }
        if (want > inven)good = false;
        if (good){
            if(Min.first==Time){
                Min.second=max(Min.second,i);
            }else if(Min.first>Time){
                Min={Time,i};
            }
        }
    }

    cout << Min.first << " " << Min.second;
}

