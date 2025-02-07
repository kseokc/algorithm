//
// Created by 김석찬 on 2024/07/11.
//

// 1. 일렬로 있는 어항에 물고기의 개수가 적혀져있다.
// 2. 가장 적은 물고기가 들어있는 어항에 +1을 해준다.
// 3. 가장 왼쪽에 있는 어항을 두번째 어항 위로 올린다.
// 4. 두개이상 어항이 쌓여있으면 전체를 시계방향으로 90도 회전시켜서 올린다. <반복> -> 여기서 차이를 줄인다.
// 5. 외쪽 부터 아래서 위로 다시 일자로 만든다.
// 6. n/2를 나눠서 180도 돌린다음 위로 올리고 한번더 반복 -> 여기서 차이를 줄인다.
// 7. 왼쪽 부터 아래서 위로 다시 일자로 만든다.


#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> v;
vector<int> minV;
int Min = 10000000;
int Max;
int xn[4] = {0, 0, -1, 1};
int yn[4] = {-1, 1, 0, 0};
int dis[101][101];

void findMin() { // 가장 작은 값을 찾는 함수
    minV.clear();
    Min = 100000000;
    Max=0;
    for (int i = 0; i < N; i++) {

        if (Min > v[i][0]) {
            minV.clear();
            minV.push_back(i);
            Min = v[i][0];
        } else if (Min == v[i][0]) {
            minV.push_back(i);
        }
        Max = max(Max, v[i][0]);
    }

    for (int i = 0; i < minV.size(); i++) {
        v[minV[i]][0]++;
    }

}

int sol(int cnt) {

    int first; // 쌓여있는 어항의 맨 처음 인덱스
    int last; // 가장 쌓여있는 어항의 맨 끝 인덱스
    int height; // 현재 쌓여있는 어항의 갸장 높은 높이

    while (Max - Min > K) {

        v[1].push_back(v[0][0]);
        first = 1;
        last = 1;
        height = 2;
        //((N-1)-last) 받을수 있는 크기
        while (height <= ((N - 1) - last)) {
            int f = first;
            int l = last;
            int h = height;
            for (int i = last; i >= first; i--) {
                for (int j = 0; j < height; j++) {
                    v[last + j + 1].push_back(v[i][j]);
                }
            }
            last += h;
            first = l + 1;
            height = l - f + 2;
        }


        for (int i = first; i < N; i++) {
            for (int j = 0; j < height; j++) {
                if (i > last && j > 0)continue;
                for (int p = 0; p < 4; p++) {
                    int xx = i + xn[p];
                    int yy = j + yn[p];
                    if (xx < first || xx > N - 1 || yy < 0 || yy >= height || (xx > last && yy > 0))continue;
                    int d = (abs(v[i][j] - v[xx][yy])) / 5;
                    if (d > 0) {
                        if (v[i][j] > v[xx][yy]) {
                            dis[i][j] -= d;
                        } else {
                            dis[i][j] += d;
                        }
                    }
                }
            }
        }
        vector<int> copy_v;
        for (int i = first; i < N; i++) {
            for (int j = 0; j < height; j++) {
                if (i > last && j > 0)continue;
                v[i][j] += dis[i][j];
                dis[i][j] = 0;
                copy_v.push_back(v[i][j]);
            }
        }

        for (int i = 0; i < copy_v.size(); i++) {
            v[i].clear();
            v[i].push_back(copy_v[i]);
        }


        last = N / 2 - 1;
        height = 1;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N / ((i + 1) * 2); j++) {
                for (int k = height - 1; k >= 0; k--) {
                    v[last + 1 + j].push_back(v[last - j][k]);
                }
            }
            first = last + 1;
            last += N / 4;
            height += height;
        }

        for (int i = first; i < N; i++) {
            for (int j = 0; j < height; j++) {
                for (int p = 0; p < 4; p++) {
                    int xx = i + xn[p];
                    int yy = j + yn[p];
                    if (xx < first || xx > N - 1 || yy < 0 || yy >= height)continue;
                    int d = (abs(v[i][j] - v[xx][yy])) / 5;
                    if (d > 0) {
                        if (v[i][j] > v[xx][yy]) {
                            dis[i][j] -= d;
                        } else {
                            dis[i][j] += d;
                        }
                    }
                }
            }
        }
        copy_v.clear();
        for (int i = first; i < N; i++) {
            for (int j = 0; j < height; j++) {
                v[i][j] += dis[i][j];
                dis[i][j] = 0;
                copy_v.push_back(v[i][j]);
            }
        }

        for (int i = 0; i < copy_v.size(); i++) {
            v[i].clear();
            v[i].push_back(copy_v[i]);
        }
        copy_v.clear();
        cnt++;
        findMin();

    }
    return cnt;
}


int main() {
    cin >> N >> K;
    v.resize(N + 1);
    int value;
    for (int i = 0; i < N; i++) {
        cin >> value;
        v[i].push_back(value);
    }
    findMin();
    cout << sol(0);

}