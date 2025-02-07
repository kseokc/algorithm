//
// Created by 김석찬 on 2022/08/08.
//

#include<iostream>
#include<vector>

using namespace std;
int N, M;
int number;  // 0: 빈집 1 : 집 2 : 치킨 집
vector<pair<int, int>> chik;
vector<pair<int, int>> house;
vector<pair<int, int>> dis;
vector<int> arr(13);
bool check[13];
int sumdis = 10000000;
int sumMin;

void search(int k, int index) {
    if (k > chik.size())return;
    if (index == M) {
        sumMin = 0;
        for (int i = 0; i < house.size(); i++) {
            int Min = 250;
            for (int j = 0; j < index; j++) {
                Min = min(Min, abs(chik[arr[j]].first - house[i].first) + abs(chik[arr[j]].second - house[i].second));
            }
            sumMin += Min;
        }
        sumdis = min(sumMin, sumdis);
    } else {
        arr[index] = k;
        search(k + 1, index + 1);
        search(k + 1, index);
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> number;
            if (number == 2) {
                chik.emplace_back(i, j);
            } else if (number == 1) {
                house.emplace_back(i, j);
            }
        }
    }
    search(0, 0);
    cout << sumdis;

}