//
// Created by 김석찬 on 2023/07/20.
//

#include <iostream>

using namespace std;

int T, ans, num;

int find(int n) {

    int result = 0;
    int n_=n;
    while (1) {
        int tmp=n_;
        while (tmp > 0) {
            result |= 1 << (tmp % 10);
            tmp /= 10;
        }

        if (result == (1 << 10) - 1){
            return n_;
        }
        n_+=n;
    }


}


int main() {
    cin >> T;
    for(int i=1; i<=T; i++) {
        cin >> num;
        ans = find(num);
        cout<<"#"<<i<<" "<< ans<<'\n';
    }
}