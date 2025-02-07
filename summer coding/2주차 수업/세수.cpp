//
// Created by 김석찬 on 2022/08/03.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> number;

int main() {
    int tc, num;
    cin >> tc;
    while (tc--) {
        cin >> num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());

    pair<int, int> Max = {0, 0};
    pair<int, int> MMax = {0, 0};
    for (int i = 1; i < number.size() - 1; i++) {
        int mid;
        pair<int, int> avg;
        mid = number[i];

        if ((mid + number[0] + number[number.size() - 1]) % 3 == 0) {
            avg = {(mid + number[0] + number[number.size() - 1]) / 3, 0};
            if (avg.first == mid) {
                Max = {0, 0};
                MMax = max(Max, MMax);
            } else {
                if (avg.first > mid) {
                    Max = {avg.first - mid, avg.second};
                    MMax = max(Max, MMax);
                } else {
                    Max = {mid - avg.first, -avg.second};
                    MMax = max(Max, MMax);
                }
            }
        } else {
            avg = {(mid + number[0] + number[number.size() - 1]) / 3,
                   (mid + number[0] + number[number.size() - 1]) % 3};
            if (avg.first == mid) {
                Max = {0, avg.second};
                MMax = max(Max, MMax);
            } else {
                if (avg.first > mid) {
                    Max = {avg.first - mid, avg.second};
                    MMax = max(Max, MMax);
                } else {
                    Max = {mid - avg.first, -avg.second};
                    MMax = max(Max, MMax);
                }
            }
        }
    }

    cout << MMax.first * 3 + MMax.second;
}
