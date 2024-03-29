#ifndef _SLIST_H_
#define _SLIST_H_
/*
	链表如何遍历；
	for(cur = head; cur; cur = cur->next){
		cur;
	}
	双向链表；
	for(cur = head->next; cur != head; cur = cur->next){
		cur;
	}

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType; 
typedef struct SListNode {
	SLTDataType _data;   
	struct SListNode* _next; 
}SListNode;

typedef struct SList {
	SListNode* _head;
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x); 
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist); 
SListNode* SListFind(SList* plist, SLTDataType x); 
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos); 
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList();

#endif//_SLIST_H_