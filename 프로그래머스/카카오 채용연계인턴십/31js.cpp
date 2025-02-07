
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


double p[12][101];
double ans[11];
vector<int> a;
vector<vector<int>> result;
void calculateWin(vector<int> d, int idx) {
    // 가장 높은 값의 면을 선택
    sort(d.begin(), d.end());
    int min = d[0];
    int cnt = 0;
    result[idx].push_back(min);
    for(int i=0; i<6; i++){
       if(min==d[i]){
           cnt++;
       }else{
           p[idx][min]=cnt/6.0;
           min=d[i];
           cnt=1;
           result[idx].push_back(min);
       }
   }
    p[idx][min]=cnt/6.0;
} //확률을 계산


void sol(int s, int idx) {
    if (a.size() == s / 2) {
        for (int i = 0; i < a.size(); i++) {

        }
        return;
    }
    // 모든 주사위에 대해 선택 여부 시도
    for (int i = idx; i < s; i++) {
        a.push_back(0);
        sol(s, i + 1);
        a.pop_back();
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int s = dice.size();
    result.resize(s+1);
    for (int i = 0; i < dice.size(); i++) {
        calculateWin(dice[i], i);
    }
    sol(s, 0);
    vector<int> answer;
    return answer;
}


//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//unordered_map<int, vector<int>> combinationMap;
//int sumArr[501][501];
//vector<int> answer;
//
//void calculateSum(int start, const vector<vector<int>> dice, int sum, int combination) {
//    if (start == dice.size() / 2) {
//        combinationMap[combination].push_back(sum);
//        sumArr[combinationMap[combination].back()][0]++;
//        for (int i = 1; i <= 500; i++) {
//            sumArr[combinationMap[combination].back()][i] = sumArr[combinationMap[combination].back()][i - 1] + (sum == i);
//        }
//        return;
//    }
//
//    for (int i = 0; i < 6; i++) {
//        sum += dice[start][i];
//        calculateSum(start + 1, dice, sum, combination);
//        sum -= dice[start][i];
//    }
//}
//
//void chooseCombination(int start, const vector<vector<int>> dice, int combination) {
//    if (combinationMap[combination].size() == dice.size() / 2) {
//        calculateSum(0, dice, 0, combination);
//        return;
//    }
//    for (int i = start; i < dice.size(); i++) {
//        combination ^= (1 << i);
//        chooseCombination(i + 1, dice, combination);
//        combination ^= (1 << i);
//    }
//}
//
//void compare(int size) {
//    for (auto entry : combinationMap) {
//        int win = 0;
//        int opponent = entry.first ^ ((1 << size) - 1);
//        for (int j = 1; j <= 500; j++) {
//            win += sumArr[entry.first][j] * sumArr[opponent][j - 1];
//        }
//
//        if (win > sumArr[answer[0]][answer[0]]) {
//            answer = entry.second;
//        }
//    }
//}
//
//vector<int> solution(vector<vector<int>> dice) {
//    vector<int> result;
//    chooseCombination(0, dice, 0);
//    compare(dice.size());
//    for (int i : answer) {
//        for (int j = 1; j <= 500; j++) {
//            result.push_back(i + 1);
//        }
//    }
//    return result;
//}