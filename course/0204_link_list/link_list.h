#ifndef COURSE_0204_LINK_LIST_LINK_LIST_H
#define COURSE_0204_LINK_LIST_LINK_LIST_H
#include <functional>
#include "status.h"

using ElemType = int;

struct LNode {
  ElemType data;
  LNode* next;
};

using LinkList = LNode*;

// Initialize a link list.
Status InitList(LinkList* L);

// Destroy a link list.
Status DestroyList(LinkList* L);

// Clear a link list.
Status ClearList(LinkList L);

// Check that a link list is empty.
Status ListEmpty(const LinkList& L);

//  Get the length of a link list.
int ListLength(const LinkList& L);

// Get the element at position i.
Status GetElem(const LinkList& L, int i, ElemType* e);

// Get the position of a element satisfying conditions.
int LocateElem(const LinkList& L, ElemType e,
               std::function<Status(ElemType, ElemType)> compare);

// Get prior element of an element.
Status PriorElem(const LinkList& L, ElemType cur_e, ElemType* pre_e);

// Get next element of an element;
Status NextElem(const LinkList& L, ElemType cur_e, ElemType* next_e);

// Insert an element at position i.
Status ListInsert(const LinkList& L, int i, ElemType e);

// Delete an element at position i.
Status ListDelete(const LinkList& L, int i, ElemType* e);

// Traverse a link list using visit function.
void ListTraverse(const LinkList& L, std::function<void(ElemType)> visit);

// Create link list from head.
Status CreateListHead(LinkList* L, int n, const std::vector<int>& nums);

// Create link list from tail.
Status CreateListTail(LinkList* L, int n, const std::vector<int>& nums);

#endif /* COURSE_0204_LINK_LIST_LINK_LIST_H */
