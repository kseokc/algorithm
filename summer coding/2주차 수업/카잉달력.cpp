//
// Created by 김석찬 on 2022/07/30.
//

//
// Created by 김석찬 on 2022/07/30.
//

#include<iostream>
#include<map>

using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, a, b;
        cin >> m >> n >> a >> b;
        int LC;
        LC = LCM(n, m);
        bool yes=0;
        int x;
        for (int i = 0; i < LC; i+=m) {
            for(int j=0; j<LC; j+=n){
                if(i+a==j+b){
                    x=i+a;
                    yes=true;
                    break;
                }
            }
        }
        if (!yes) {
            cout << "-1"<<'\n';
        } else cout << x<<'\n';
    }
}
