#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<sstream>
using namespace std;
map<string,int>A;
string word;
string first;

queue<string>arr[10000];
int tc;

int main(){
    cin>>tc;
    cin.ignore();
    int count=0;
    for(int i=0; i<tc; i++){
        getline(cin,word);
        stringstream stream;
        stream.str(word);
        while(stream>>first){
            arr[i].push(first);
            A.insert({first,i});
            count++;
        }
        stream.str("");
    }
    int result=count;
    int result1=0;
    getline(cin,word);
    stringstream stream;
    stream.str(word);
    while(stream>>first){
        result1++;
        auto i=A.find(first);
        if(i == A.end()){
            break;
        }
        else{
            if( arr[i->second].front() == first){
                arr[i->second].pop();
                result--;
            }
            else{
                break;
            }
        }
    }
    if(result==0){
        if(result1==count)cout<<"Possible";
        else cout<<"Impossible";
    }
    else{
        cout<<"Impossible";
    }
}