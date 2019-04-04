#ifndef LINKLIST_H
#define LINKLIST_H

typedef struct LINKNODE{
    struct LINKNODE* next;  
}LinkNode;

typedef struct LINKLIST{
    LinkNode head;
    int size;
}LinkList;

typedef void(*PRINTNODE)(LinkNode*);
typedef int(*COMPARE)(LinkNode*, LinkNode*);

// interface
LinkList* Init_LinkList();
void Insert_LinkList(LinkList *list, int pos, LinkNode* data);
void Remove_LinkList(LinkList *list, int pos);
int Find_LinkList(LinkList *list, LinkNode* data, COMPARE cmp);
void Print_LinkList(LinkList *list, PRINTNODE print);
void Free_LinkList(LinkList *list);


#endif

