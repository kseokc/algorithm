//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> arr;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int max = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] * (arr.size() - (i)) > max) {
            max = arr[i] * (arr.size() - (i));
        }
    }
    cout << max;
}