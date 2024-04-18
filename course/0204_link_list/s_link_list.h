#ifndef COURSE_0204_LINK_LIST_S_LINK_LIST_H
#define COURSE_0204_LINK_LIST_S_LINK_LIST_H
#include <functional>
#include "status.h"

inline constexpr int kMaxSize = 1000;

using ElemType = int;

struct SLinkNode {
  ElemType data;
  int cur;
};

using SLinkList = SLinkNode[kMaxSize];

// In the following functions, s is the index of head node.

void InitSpace(SLinkList space);

int Malloc(SLinkList space);

void Free(SLinkList space, int k);

Status InitList(SLinkList space, int* s);

Status DestroyList(SLinkList space, int* s);

Status ClearList(SLinkList space, int s);

Status ListEmpty(SLinkList space, int s);

int ListLength(SLinkList space, int s);

Status GetElem(SLinkList space, int s, int i, ElemType* e);

int LocateElem(SLinkList space, int s, ElemType e, std::function<Status(ElemType, ElemType)> compare);

Status PriorElem(SLinkList space, int s, ElemType cur_e, ElemType* pre_e);

Status NextElem(SLinkList space, int s, ElemType cur_e, ElemType* next_e);

Status ListInsert(SLinkList space, int s, int i, ElemType e);

Status ListDelete(SLinkList space, int s, int i, ElemType* e);

void ListTraverse(SLinkList space, int s, std::function<void(ElemType)> visit);

void PrintList(SLinkList space, int s);

#endif /* COURSE_0204_LINK_LIST_S_LINK_LIST_H */
