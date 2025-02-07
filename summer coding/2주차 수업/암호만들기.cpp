//
// Created by 김석찬 on 2022/08/01.
//

//L개의 문자
// c개의 문자 중에 있음 모음은 최소한개 자음도 최소 한개가 있어야함
// a e i o u
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<char> aeiou;
vector<char> non_aeiou;

int solve, alpha;

vector<char> a;
vector<string>t;

void search(vector<char> b,int index ,int n, int size){
    if(index==size){
        if(a.size()==n){
            string s="";
            for(int i=0; i<a.size(); i++){
                s+=a[i];
            }
            t.push_back(s);
            return;
        }
        else{
            return;
        }

    }
    else{
        a.push_back(b[index]);
        search(b,index+1,n,size);
        a.pop_back();
        search(b,index+1,n,size);
    }

    return;
}


int main() {

    char alp;
    cin >> solve >> alpha;
    while (alpha--) {
        cin >> alp;
        if (alp == 'a' || alp == 'e' || alp == 'i' || alp == 'o' || alp == 'u') {
            aeiou.push_back(alp);
        } else {
            non_aeiou.push_back(alp);
        }
    }
    sort(aeiou.begin(),aeiou.end());
    sort(non_aeiou.begin(),non_aeiou.end());
    int n=1;
    while(solve-n>=2){
        search(aeiou,0,n,aeiou.size());
        a.clear();
        search(non_aeiou,0,solve-n,non_aeiou.size());
        cout<<'\n';
        n++;
    }


}