//
// Created by 김석찬 on 2024/04/02.
//

// M가지의 서로다른 색상의 보석을 선생님이 가지고있다
// 학생은 같은 색상의 보석만 가져갈수있다. 보석을 받지 못하는 학생이 있어도 된다.
// 질투심은 보석을 가장많이 가져간 학생의 보석의수
// 질투심이 최소가 되게 만들어라

#include <iostream>


using namespace std;

int N, M;   //학생의 수,보석의 색
long long Marr[300001];
long long ans = 0;

void input() {
    cin >> N >> M;
    long long end;
    for (int i = 0; i < M; i++) {
        cin >> Marr[i];
        end+=Marr[i];
    }
    long long start=1;
    while(start<=end){
        long long mid=(start+end)/2;
        long long people=0;
        for(int i=0; i<M; i++){
            if(Marr[i]%mid==0){
                people+=Marr[i]/mid;
            }
            else{
                people+=Marr[i]/mid+1;
            }
        }
        if(people>N){

            start=mid+1;
        }else{
            end=mid-1;
            ans=mid;
        }
    }
    cout<<ans;
}

int main() {
    input();

}