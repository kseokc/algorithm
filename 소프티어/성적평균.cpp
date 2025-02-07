#include <iostream>

using namespace std;

int N, K;

float arr[1000001];
float sum[1000001];
int main() {
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }

    int a,b;
    float ans;
    for(int i=0; i<K; i++){
        cin>>a>>b;
        float total=b-a+1;
        if(a==1){
            ans=sum[b-1]/total;
        }else{
            ans=(sum[b-1]-sum[a-2])/total;
        }
        cout<<fixed;
        cout.precision(2);
        cout<<ans<<'\n';
    }
}
