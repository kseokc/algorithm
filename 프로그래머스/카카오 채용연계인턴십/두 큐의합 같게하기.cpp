//
// Created by 김석찬 on 2023/11/15.
//

#include <string>
#include <vector>
#include<iostream>

using namespace std;

long long q1 = 0;
long long q2 = 0;
int cnt = 0;
int first = 0;
int second = 0;
int size1, size2, Max;

int solution(vector<int> queue1, vector<int> queue2) {
    size1 = queue1.size();
    size2 = queue2.size();
    int maxsize=size1*2;
    bool can = true;
    for (int i = 0; i < size1; i++) {
        q1 += queue1[i];
        q2 += queue2[i];
        Max=max(Max,queue1[i]);
        Max=max(Max,queue2[i]);
    }
    q2 += q1;
    q2 /= 2;
    if(Max>q2)can=false;

    while (q2 != q1 && can) {
        if (q2 < q1) {
            //반보다  q2의 값이 작을때 q1에서 꺼내야함
            while (q1 > q2) {
                if (size1 == 1) {
                    can = false;
                    break;
                }
                int q1front = queue1[first];
                first += 1;
                size1 -= 1;
                size2 += 1;
                queue2.push_back(q1front);
                q1 -= q1front;
                cnt++;
            }
        } else {
            //반보다  q1의 값이 작을때  q2에서 꺼내야함
            while (q1 < q2) {
                if (size2 == 1) {
                    can = false;
                    break;
                }
                int q2front = queue2[second];
                second += 1;
                size1 += 1;
                size2 -= 1;
                queue1.push_back(q2front);
                q1 += q2front;
                cnt++;
            }
        }
        if((first+second)==maxsize-1){
            can=false;
            break;
        }
    }
    int answer=-1;
    if (can)answer = cnt;
    return answer;
}

int main() {
    //(321 453)
    vector<int> queue1 = {14, 4, 2};
    vector<int> queue2 = {4, 4, 2};
    cout << solution(queue1, queue2);

}