//
// Created by 김석찬 on 2022/07/25.
//

#include<iostream>
using namespace std;
#define phone 10
#define Max 10000
class Trie{
private:
    Trie* next[phone];
    bool nextchild;
    bool finsh;
public:
    Trie(){
        fill(next,next+phone,nullptr);
        nextchild=finsh=false;
    }
    ~Trie(){
        for(int i=0; i<phone; i++){
            if(!next[i]){
                delete next[i];
            }
        }
    }
    bool insert(const char *number){
        if(*number=='\0'){
            finsh=true;

            if(nextchild){
                return 0;
            }
            else{
                return 1;
            }
        }
        int nextnumber=*number-'0';
        if(!next[nextnumber]){
            next[nextnumber]=new Trie;
        }
        nextchild=true;
        bool get=next[nextnumber]->insert(number+1);
        return !finsh&&get;
    }
};

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        Trie* root=new Trie;
        int Case;
        char phonenumber[Max];
        bool result=true;
        cin>>Case;
        while(Case--){
            cin>>phonenumber;
            if(!root->insert(phonenumber)){
                result=false;
            }
        }
        if(result==true){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        delete root;
    }
}