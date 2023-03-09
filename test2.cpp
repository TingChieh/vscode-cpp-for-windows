#include <iostream>
using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void CreateList(LinkList &L) {
    L = new LNode;
    L->next = NULL;
    int x;
    cin >> x;
    while (x != -1) {
        LNode *p = new LNode;
        p->data = x;
        p->next = L->next;
        L->next = p;
        cin >> x;
    }
}

void TraverseList(LinkList L) {
    LNode *p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DestroyList(LinkList &L) {
    LNode *p = L, *q = L->next;
    while (q) {
        delete p;
        p = q;
        q = p->next;
    }
    delete p;
    L = NULL;
}

int main() {
    LinkList L;
    CreateList(L);
    TraverseList(L);
    DestroyList(L);
    return 0;
}
