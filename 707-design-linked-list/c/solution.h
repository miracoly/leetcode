#ifndef LEETCODE_H
#define LEETCODE_H

typedef struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* preHead;
    size_t size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate(void);

int myLinkedListGet(MyLinkedList *obj, size_t index);

void myLinkedListAddAtHead(MyLinkedList* obj, int val);

void myLinkedListAddAtTail(MyLinkedList* obj, int val);

void myLinkedListAddAtIndex(MyLinkedList *obj, size_t index, int val);

void myLinkedListDeleteAtIndex(MyLinkedList *obj, size_t index);

void myLinkedListFree(MyLinkedList* obj);

#endif
