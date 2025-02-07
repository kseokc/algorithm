//
// Created by 김석찬 on 2022/07/26.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string fuc,num,c;
int tc,num_tc;
vector<string> arr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>tc;
    while(tc--){
        cin>>fuc>>num_tc>>num;
        for(int i=1; i<num.length(); i++){
            if(0<=num[i]-'0'&& 10>num[i]-'0'){
                c+=num[i];
            }else{
                arr.push_back(c);
                c="";
            }
        }

        for(int i=0; i<fuc.length(); i++){
            if(fuc[i]=='R'){
                reverse(arr.begin(), arr.end());
            }
            else{
                if(arr.empty() || num_tc==0){
                    cout<<"error";
                    break;
                }
                else{
                    arr.erase(arr.begin());
                }
            }
        }
        if(num_tc==0){cout<<"\n";arr.clear();continue;}

        for(int i=0; i<arr.size(); i++){
            if(i==0)cout<<'[';
            if(i==arr.size()-1){cout<<arr[i];cout<<']';break;}
            cout<<arr[i]<<",";
        }

        cout<<"\n";
        arr.clear();
    }

}

