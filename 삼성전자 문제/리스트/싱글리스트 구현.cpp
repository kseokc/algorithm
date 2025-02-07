#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

#define MAX_NODE 10000

using namespace std;

enum {
    ADD_HEAD = 1, ADD_TAIL, ADD_NUM, REMOVE, PRINT, END = 99
};

struct Node {
    int data;
    Node *next;
};

class link {
public:
    Node node[MAX_NODE];
    int nodeCnt;
    Node *head;

    Node *getNode(int data) {
        node[nodeCnt].data = data;
        node[nodeCnt].next = nullptr;
        return &node[nodeCnt++];
    }

    void init() {
        head= nullptr;
        for(int i=0; i<nodeCnt; i++){
            node[i].data=0;
            node[i].next= nullptr;
        }
        nodeCnt = 0;
    }

    void addNode2Head(int data) {
        Node* newnode = getNode(data);
        if (nodeCnt == 1)head = newnode;
        else {
            newnode->next = head;
            head = newnode;
        }
    }

    void addNode2Tail(int data) {
        Node *newnode = getNode(data);
        if(nodeCnt==1)head=newnode;
        else{
            Node *curnode = head;
            while (curnode->next != nullptr) {
                curnode = curnode->next;
            }

            curnode->next = newnode;
        }
    }

    void addNode2Num(int data, int num) {
        Node *newnode = getNode(data);
        Node *curnode = head;
        if (num == 1) {
            newnode->next=head;
            head=newnode;
            return;
        }
        for (int i = 1; i < num-1; i++) {
            curnode = curnode->next;
        }

        newnode->next = curnode->next;
        curnode->next = newnode;

    }

    void removeNode(int data) {
        Node *prevnode = head;
        Node *delnode = head;
        while (delnode->data != data) {
            if(delnode->next== nullptr)return;
            prevnode = delnode;
            delnode = delnode->next;

        }
        prevnode->next = delnode->next;

        if (delnode == head)head = delnode->next;
    }

    int getList(int output[MAX_NODE]) {

        Node *curnode = head;
        int cnt = 0;
        while (curnode != nullptr) {

            output[cnt] = curnode->data;
            curnode = curnode->next;
            cnt++;
        }
        return cnt;
    }
};


int main() {
    //setbuf(stdout, NULL);
    //freopen("sll_input.txt", "r", stdin);

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("#%d\n", t);
        link s;
        s.init();
        if(t==3){}

        while (1) {
            int cmd, data, num, cnt, i;
            int output[MAX_NODE] = {0};

            scanf("%d", &cmd);
            if(cmd==99)break;
            switch (cmd) {
                case 1:
                    scanf("%d", &data);
                    s.addNode2Head(data);
                    break;
                case 2:
                    scanf("%d", &data);
                    s.addNode2Tail(data);
                    break;
                case 3:
                    scanf("%d %d", &data, &num);
                    s.addNode2Num(data, num);
                    break;
                case 4:
                    scanf("%d", &data);
                    s.removeNode(data);
                    break;
                case 5:
                    cnt = s.getList(output);
                    i = 0;
                    while (cnt--)
                        printf("%d ", output[i++]);
                    printf("\n");
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}