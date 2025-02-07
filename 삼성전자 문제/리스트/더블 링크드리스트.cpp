#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>

#define MAX_NODE 10000

using namespace std;

enum {
    ADD_HEAD = 1, ADD_TAIL, ADD_NUM, FIND, REMOVE, PRINT, PRINT_REVERSE, END = 99
};

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class link {
public:
    Node node[MAX_NODE];
    int nodeCnt;
    Node *head;

    Node *getNode(int data) {
        node[nodeCnt].data = data;
        node[nodeCnt].prev = nullptr;
        node[nodeCnt].next = nullptr;
        return &node[nodeCnt++];
    }


    void init() {
        head = nullptr;
        for (int i = 0; i < nodeCnt; i++) {
            node[i].data = 0;
            node[i].next = nullptr;
            node[i].prev = nullptr;
        }
        nodeCnt = 0;
    }

    void addNode2Head(int data) {
        Node *newnode = getNode(data);
        if (nodeCnt == 1)head = newnode;
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void addNode2Tail(int data) {
        Node *newnode = getNode(data);
        if (nodeCnt == 1)head = newnode;
        else {
            Node *curnode = head;
            while (curnode->next != nullptr) {
                curnode = curnode->next;
            }

            curnode->next = newnode;
            newnode->prev = curnode;
        }
    }

    void addNode2Num(int data, int num) {
        Node *newnode = getNode(data);
        Node *curnode = head;
        if (num == 1) {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
            return;
        }
        for (int i = 1; i < num - 1; i++) {
            curnode = curnode->next;
        }

        if (curnode->next == nullptr) {
            newnode->prev = curnode;
            curnode->next = newnode;
            return;
        }

        newnode->next = curnode->next;
        newnode->prev = curnode;

        curnode->next->prev = newnode;
        curnode->next = newnode;
    }

    void removeNode(int data) {
        Node *prevnode = head;
        Node *delnode = head;
        while (delnode->data != data) {
            if (delnode->next == nullptr)return;
            prevnode = delnode;
            delnode = delnode->next;

        }
        if (delnode->next == nullptr) {
            prevnode->next= nullptr;
            return;
        }
        prevnode->next = delnode->next;
        delnode->next->prev = prevnode;

        if (delnode == head)head = delnode->next;
    }

    int findNode(int data) {

        Node *findnode = head;
        int count = 1;
        while (findnode->data != data) {
            count++;
            if (findnode->next == nullptr)return -1;
            findnode = findnode->next;

        }
        return count;
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

    int getReversedList(int output[MAX_NODE]) {
        Node *curnode = head;
        int cnt = 0;
        while (curnode->next != nullptr) {
            curnode = curnode->next;

        }
        while (curnode != nullptr) {
            output[cnt] = curnode->data;
            curnode = curnode->prev;
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
        if (t == 2) {}

        while (1) {
            int cmd, data, num, cnt, i = 0;
            int output[MAX_NODE] = {0};

            scanf("%d", &cmd);
            if (cmd == 99)break;
            switch (cmd) {
                case ADD_HEAD: // 1
                    scanf("%d", &data);
                    s.addNode2Head(data);
                    break;
                case ADD_TAIL: // 2
                    scanf("%d", &data);
                    s.addNode2Tail(data);
                    break;
                case ADD_NUM: // 3
                    scanf("%d %d", &data, &num);
                    s.addNode2Num(data, num);
                    break;
                case FIND: // 4
                    scanf("%d", &data);
                    num = s.findNode(data);
                    printf("%d\n", num);
                    break;
                case REMOVE: // 5
                    scanf("%d", &data);
                    s.removeNode(data);
                    break;
                case PRINT: // 6
                    cnt = s.getList(output);
                    while (cnt--)
                        printf("%d ", output[i++]);
                    printf("\n");
                    break;
                case PRINT_REVERSE: // 7
                    cnt = s.getReversedList(output);
                    while (cnt--)
                        printf("%d ", output[i++]);
                    printf("\n");
                    break;
                case END:
                    return 0;
            }
        }
        printf("\n");
    }

    return 0;
}