#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linklist.h"


LinkList* Init_LinkList() {
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->head.next = NULL;
    list->size = 0;
    return list;
}

void Insert_LinkList(LinkList* list, int pos, LinkNode* data) {
    assert(list != NULL && data != NULL && pos >= 0 && pos <= list->size);
    LinkNode* pCurrent = &(list->head);
    // find the position
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    // insert the element
    data->next = pCurrent->next;
    pCurrent->next = data;
    list->size++;
}

void Remove_LinkList(LinkList* list, int pos) {
    assert(list != NULL && pos >= 0 && pos < list->size);
    LinkNode* pCurrent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    pCurrent->next = pCurrent->next->next;
    list->size --;
}

int Find_LinkList(LinkList* list, LinkNode* data, COMPARE cmp) {
    assert(list != NULL && data != NULL);
    int index = 0;
    int flag = 0; // have found or not
    LinkNode* pCurrent = list->head.next;
    while (pCurrent != NULL) {
        if (cmp(data, pCurrent)) {
            flag = 1;
            break;
        }
        pCurrent = pCurrent->next;
        index++;
    }
    if (!flag) return -1;
    return index;
}

void Print_LinkList(LinkList* list, PRINTNODE print) {
    assert(list != NULL);
    LinkNode* pCurrent = list->head.next;
    while (pCurrent != NULL) {
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}

void Free_LinkList(LinkList* list) {
    if (list == NULL) return;
    free(list);
}




