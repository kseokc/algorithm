//
// Created by 김석찬 on 2023/07/01.
//


#include<iostream>
#include<algorithm>

using namespace std;

bool broken[10];

int N, M;
int gap;

int big;
int b_cnt;
int sml;
int s_cnt;
int ans = 500000;

bool check(int input)
{
    if(input == 0) return !broken[0];
    int cur;
    while(input > 0)
    {
        cur = input % 10;
        input /= 10;
        if (broken[cur]) return 0;
    }
    return 1;
}

int count(int input)
{
    if (input == 0) return 1;
    int cnt = 0;
    while (input > 0)
    {
        cnt++;
        input /= 10;
    }
    return cnt;
}

void find_near()
{
    big = N;
    sml = N;
    while(1)
    {
        if (b_cnt + count(big) >= gap || s_cnt + count(sml) >= gap) break;


        if(check(sml))
        {
            ans = s_cnt + count(sml);
            break;
        }
        if (check(big))
        {
            ans = b_cnt + count(big);
            break;
        }


        big++;
        if (sml > 0) sml--;
        ++b_cnt;
        ++s_cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; ++i)
    {
        int x;
        cin >> x;
        broken[x] = 1;
    }
    gap = abs(N - 100);
    find_near();

    cout << min(ans, gap);

    // 100에서 +, - 로 이동하는 것도 생각하기.
}