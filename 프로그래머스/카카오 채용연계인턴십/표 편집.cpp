//
// Created by 김석찬 on 2022/12/29.
//

#include <string>
#include <vector>
#include <stack>
#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
    node *pre;

};

struct Iterator {
    node *Node;

    Iterator(node *n) {
        Node = n;
    }

    Iterator *operator++() {
        Node = Node->next;
        return this;
    }

    Iterator *operator--() {
        Node = Node->pre;
        return this;
    }
};

class List {
public:
    node *head;
    node *tail;

    List() {
        head = new node;
        tail = new node;
        head->data = tail->data = -1;
        head->next = tail;
        tail->pre = head;
    }

    node *begin() {
        return head->next;
    }

    node *end() {
        return tail->pre;
    }

    void pushback(int x) {
        node *newnode = new node;
        newnode->data = x;
        tail->pre->next = newnode;
        newnode->next = tail;

        newnode->pre = tail->pre;
        tail->pre=newnode;
    }

    node *del(Iterator &pos) {
        node *prenode = pos.Node->pre;
        node *nextnode = pos.Node->next;

        prenode->next = nextnode;
        nextnode->pre = prenode;
        if (nextnode == tail)return prenode;
        else return nextnode;

    }

    void insert(node *n) {
        n->pre->next = n;
        n->next->pre = n;
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    List list;
    stack<node *> Ztable;

    for (int i = 0; i < n; i++) {
        answer += 'O';
        list.pushback(i);
    }


    Iterator iter = Iterator(list.begin());

    for (int i = 0; i < k; i++) {
        ++iter;
    }


    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            string sx=cmd[i].substr(2,cmd[i].size()-2);
            int x=stoi(sx);
            while(x--){
                --iter;
                if(iter.Node==list.head)iter.Node=list.end();
            }
        } else if (cmd[i][0] == 'D') {
            string sx=cmd[i].substr(2,cmd[i].size()-2);
            int x=stoi(sx);
            while(x--){
                ++iter;
                if(iter.Node==list.tail)iter.Node=list.begin();
            }
        } else if (cmd[i] == "C") {

            answer[iter.Node->data]='X';
            Ztable.push(iter.Node);
            iter.Node=list.del(iter);

        } else if (cmd[i] == "Z") {
            answer[Ztable.top()->data]='O';
            list.insert(Ztable.top());
            Ztable.pop();
        }
    }
    return answer;

}