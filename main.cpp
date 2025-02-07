#include<iostream>
#include <vector>
using namespace std;

int N,qNum;
vector<int> v;
vector<int>q;
int dp[31][40001];
int main(){
      cin>>N;
      int a;
      for(int i=0; i<N; i++){
            cin>>a;
            v.push_back(a);
      }

      for(int i=0; i<v.size(); i++){
          for(int j=v[i]; j<40001; j++){
              int curVal=v[i];
              if(curVal)
          }
      }
      // 1,4
      // 3 5

    // 1,2,4
    // 3,5 6,7, 1,2

    // 1 2 1 4
    // 2 4
    //

    // 확인할 구슬의 개수는 7이하이다.
      for(int i=0; i<qNum; i++){
          cin>>a;
          q.push_back(a);
      }
}