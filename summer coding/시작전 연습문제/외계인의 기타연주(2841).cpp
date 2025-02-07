#include <iostream>
#include<stack>
using namespace std;
struct node{
    stack<int>arr;
    node(){

    }
    node(int x){
        arr.push(x);
    }
};

class result{
public:
    int count;
    node* pelt;
    result(){
        pelt=new node[7];
        count=0;
    }
    ~result(){
        delete[] pelt;
    }
    void insert(int m,int p){
        if(pelt[m].arr.empty()){
            pelt[m].arr.push(p);
            count++;
            return;
        }

        if(pelt[m].arr.top()==p){
            return;
        }
        else if(pelt[m].arr.top()<p){
            pelt[m].arr.push(p);
            count++;
            return;
        }
        else if(pelt[m].arr.top()>p){
            while(pelt[m].arr.top()>p){
                pelt[m].arr.pop();
                count++;
                if(pelt[m].arr.empty())break;
            }

            if(pelt[m].arr.empty()){
                pelt[m].arr.push(p);
                count++;
            }
            else if(pelt[m].arr.top()==p){
                return;
            }else{
                pelt[m].arr.push(p);
                count++;
            }



        }
    }
};

int main() {
    int tc,p,m,pc;
    cin>>tc>>pc;
    result r;
    while(tc--){
        cin>>m>>p;
        r.insert(m,p);

    }
    cout<<r.count;

}
