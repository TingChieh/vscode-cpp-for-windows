#include <iostream>
#include <stdlib.h>
using namespace std;

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct LNode {
    ElemType data;
    struct LNode* next;
} LNode, *LinkList;

Status InitList(LinkList& L) {
    L = new LNode;
    L->next = NULL;
    return OK;
}

Status GetElem(LinkList L, int i, ElemType& e) {
    LNode* p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return ERROR;
    e = p->data;
    return OK;
}

Status ListInsert(LinkList& L, int i, ElemType e) {
    LNode* p = L;
    int j = 0;
    while (p && (j < i - 1)) {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return ERROR;
    LNode* s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

int main() {
    LinkList L;
    InitList(L);
    int i = 1, x;
    while (1) {
        cin >> x;
        if (x == -1) break;
        ListInsert(L, i, x);
        ++i;
    }
    for (int j = i - 1; j > 0; --j) {
        ElemType e;
        GetElem(L, j, e);
        cout << e << ' ';
    }
    return 0;
}
