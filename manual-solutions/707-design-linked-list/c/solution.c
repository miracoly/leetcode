#include <stdlib.h>
#include "solution.h"

static Node* mkNode(int val, Node* restrict prev, Node* restrict next) {
    Node* node = calloc(1, sizeof *node);
    if (!node) return NULL;

    node->val = val;
    node->prev = prev;
    node->next = next;
    return node;
}

MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList* list = calloc(1, sizeof *list);
    if (!list) return NULL;

    Node* preHead = mkNode(0, NULL, NULL);
    if (!preHead) {
        free(list);
        return NULL;
    }

    Node* head = mkNode(0, NULL, NULL);
    if (!head) {
        free(list);
        free(preHead);
        return NULL;
    }

    preHead->next = head;
    head->prev = preHead;
    list->preHead = preHead;

    return list;
}

int myLinkedListGet(MyLinkedList* obj, size_t index) {
    if (!obj || index >= obj->size) return -1;

    Node* cur = obj->preHead->next;
    for (size_t i = 0; i < index; ++i) {
        cur = cur->next;
    }
    return cur->val;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, size_t index, int val) {
    if (!obj || index > obj->size) return;

    Node* prev = obj->preHead;
    for (size_t i = 0; i < index; ++i) {
        prev = prev->next;
    }
    Node* next = prev->next;
    Node* newNode = mkNode(val, prev, next);
    if (!newNode) return;

    prev->next = newNode;
    next->prev = newNode;

    obj->size++;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    myLinkedListAddAtIndex(obj, 0, val);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if (!obj) return;
    myLinkedListAddAtIndex(obj, obj->size, val);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, size_t index) {
    if (!obj || index >= obj->size) return;

    Node* prev = obj->preHead;
    for (size_t i = 0; i < index; ++i) {
        prev = prev->next;
    }
    Node* toDelete = prev->next;
    if (!toDelete) return;
    Node* next = toDelete->next;

    prev->next = next;
    next->prev = prev;

    free(toDelete);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (!obj) return;

    Node* cur = obj->preHead;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(obj);
}
