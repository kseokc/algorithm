//
// Created by 김석찬 on 2024/02/27.
//

#include<iostream>
#include<vector>
using namespace std;

bool Can;
int arr[9];
vector<int>v;

void sol(int i,int sum){

    if(7-v.size()>8-i || i>=9){// 7-i는 남은 난쟁이
        return;
    }
    if(v.size()==7) {
        if(sum==100){
            std::sort(v.begin(), v.end(),greater<int>());
            for(auto ans:v){
                cout<<ans<<'\n';
                Can=true;
            }
            return;
        }
    }
    for(int k=i; k<9; k++){
        if (Can)break;
        v.push_back(arr[k]);
        sum+=arr[k];
        sol(i+1,sum);
        sum-=arr[k];
        v.pop_back();
    }

}

int main(){
    for(int i=0; i<9; i++){
        cin>>arr[i];
    }
    for(int i=0; i<3; i++){
        if(Can)return 0;
        sol(i,0);
    }
}
/*
 * #include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int arr[9];
	int sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);
	for (int i = 0; i < 8; i++) {
		for (int j = 1; j < 9; j++) {

			if (sum - arr[i] - arr[j] == 100) {

				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << arr[k] << '\n';
				}
				return 0;
			}
		}
	}
	return 0;
}
 *
 * */