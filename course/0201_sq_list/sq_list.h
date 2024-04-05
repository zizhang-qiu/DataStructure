#ifndef COURSE_0201_SQ_LIST_SQ_LIST_H
#define COURSE_0201_SQ_LIST_SQ_LIST_H
#include <functional>
#include "status.h"

inline constexpr int kListInitSize = 100;
inline constexpr int kListIncrement = 10;

using ElemType = int;

struct SqList {
  ElemType* elem;
  int length;
  int list_size;
};

// Function to initialize a sq list.
Status InitList(SqList* L);

// Destroy a list.
Status DestroyList(SqList* L);

// Clear a list.
Status ClearList(SqList* L);

// Check that a list is empty.
Status ListEmpty(const SqList& L);

// Get the length of a list.
int ListLength(const SqList& L);

// Get element at position i.
Status GetElem(const SqList& L, int i, ElemType* e);

// Get prior element.
Status PriorElem(const SqList& L, ElemType cur_e, ElemType* pre_e);

// Get next element.
Status NextElem(const SqList& L, ElemType cur_e, ElemType* next_e);

// Insert an element at position i.
Status ListInsert(SqList* L, int i, ElemType e);

// Delete the element at position i.
Status ListDelete(SqList* L, int i, ElemType* e);

// Locate an element in list, return 0 if not exists.
int LocateElem(const SqList& L, ElemType e,
               std::function<Status(ElemType, ElemType)> compare);


// Traverse the list using visit function.
void ListTraverse(const SqList& L, std::function<void(ElemType)> visit);

#endif /* COURSE_0201_SQ_LIST_SQ_LIST_H */
