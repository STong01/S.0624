#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

void SListInit(SList* plist){
	assert(plist);

	plist->_head = NULL;
}

void SListDestory(SList* plist){
	SListNode * tmp;
	while (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}

void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode * cur = (SListNode * )malloc(sizeof(SListNode));
	cur->_data = x;
	cur->_next = plist->_head;
	plist->_head = cur;
}

void SListPopFront(SList* plist){
	assert(plist);
	SListNode * tmp;
	if (plist->_head){
		tmp = plist->_head;
		plist->_head = plist->_head->_next;
		free(tmp);
	}
}
void SListPrint(SList* plist){
	assert(plist);
	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		printf("%d->", cur->_data);
	}
	printf("NULL\n");
}

SListNode* SListFind(SList* plist, SLTDataType x) {
	assert(plist);

	SListNode * cur;
	for (cur = plist->_head; cur; cur = cur->_next){
		if (cur->_data == x){
			return cur;
		}
	}
	return NULL;
}
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos);

	SListNode * cur = (SListNode *)malloc(sizeof(SListNode *));
	cur->_data = x;
	cur->_next = cur->_next;
	pos->_next = cur;

}
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode * tmp = pos->_next;

	pos->_next = tmp->_next;
	free(tmp);

}
