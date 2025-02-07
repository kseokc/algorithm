#include<iostream>

using namespace std;

int n;
string s;
long long ans=-999999999999;


long long calculate(char a, long long second, long long first) {
    switch (a) {
        case '*':
            return first * second;
        case '-':
            return first - second;
        case '+':
            return first + second;
        case '/':
            return first / second;
    }
}

void sol(int num, long long value) {
    if (num >= s.length() - 1) {
        ans = max(ans, value);
        return;
    }
    //앞에 수와 하나를 택하거나 두개를 택하거나
    // 1. 앞의 수를 하나민 택 하는 경우
    long long cal = calculate(s[num], s[num + 1] - '0', value);
    sol(num + 2, cal);
    // 2. 두개를 택 하는 경우

    if (num + 3 > s.length() - 1)return;
    long long calTwo = calculate(s[num + 2], s[num + 3] - '0', s[num + 1] - '0');
    cal = calculate(s[num], calTwo, value);
    sol(num + 4, cal);
}

int main() {
    cin >> n >> s;
    sol(1, s[0] - '0');
    long long num = calculate(s[1], s[2] - '0', s[0] - '0');
    sol(3, num);
    cout << ans << '\n';
}

/*
 9
3+8*7-9*2

 5
8*3+5

 7
8*3+5+2

 19
1*2+3*4*5-6*7*8*9*0

 19
1*2+3*4*5-6*7*8*9*9

 19
1-9-1-9-1-9-1-9-1-9
 */