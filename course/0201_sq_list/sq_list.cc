#include "sq_list.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include "status.h"

Status InitList(SqList* L) {
  // Use new instead of malloc.
  L->elem = new ElemType[kListInitSize];

  // Use nullptr instead of NULL.
  if (L->elem == nullptr) {
    std::exit(kOverflow);
  }

  L->length = 0;
  L->list_size = kListInitSize;

  return kOK;
}

Status ListEmpty(const SqList& L) {
  return L.length == 0 ? kTrue : kFalse;
}

int ListLength(const SqList& L) {
  return L.length;
}

Status GetElem(const SqList& L, int i, ElemType* e) {
  if (i < 1 || i > L.length) {
    return kError;
  }

  *e = L.elem[i - 1];

  return kOK;
}

Status DestroyList(SqList* L) {
  if (L == nullptr || L->elem == nullptr) {
    return kError;
  }

  // Use delete instead of free.
  delete[] L->elem;
  L->elem = nullptr;

  L->length = 0;
  L->list_size = 0;

  return kOK;
}

Status ClearList(SqList* L) {
  if (L == nullptr || L->elem == nullptr) {
    return kError;
  }

  L->length = 0;
  return kOK;
}

Status PriorElem(const SqList& L, ElemType cur_e, ElemType* pre_e) {
  // Check that there are at least 2 elements.
  if (L.elem == nullptr || L.length < 2) {
    return kError;
  }

  int i = 0;

  // Look for the element.
  while (i < L.length && L.elem[i] != cur_e) {
    ++i;
  }

  if (i == 0 || i >= L.length) {
    return kError;
  }

  *pre_e = L.elem[i - 1];

  return kOK;
}

Status NextElem(const SqList& L, ElemType cur_e, ElemType* next_e) {
  // Check that there are at least 2 elements.
  if (L.elem == nullptr || L.length < 2) {
    return kError;
  }

  int i = 0;
  // Look for the element.
  while (i < L.length - 1 && L.elem[i] != cur_e) {
    ++i;
  }

  if (i >= L.length - 1) {
    return kError;
  }

  *next_e = L.elem[i + 1];

  return kOK;
}

Status ListInsert(SqList* L, int i, ElemType e) {
  // Check that L is legal.
  if (L == nullptr || L->elem == nullptr) {
    return kError;
  }

  // Check that index is legal.
  if (i < 1 || i > L->length + 1) {
    return kError;
  }

  ElemType* new_base;
  ElemType* p;
  ElemType* q;
  //  If storage is full, add new storage.
  if (L->length >= L->list_size) {
    new_base = new ElemType[L->list_size + kListIncrement];
    if (new_base == nullptr) {
      std::exit(kOverflow);
    }
    // copy
    std::copy(L->elem, L->elem+L->length, new_base);
    delete[] L->elem;

    L->elem = new_base;
    L->list_size += kListIncrement;
  }

  // q is the position to insert.
  q = &(L->elem[i - 1]);

  // Move the element to right.
  for (p = &(L->elem[L->length - 1]); p >= q; --p) {
    *(p + 1) = *p;
  }

  // Insert element.
  *q = e;

  // Modify length.
  ++L->length;

  return kOK;
}

void ListTraverse(const SqList& L, std::function<void(ElemType)> visit) {
  for (int i = 0; i < L.length; ++i) {
    visit(L.elem[i]);
  }
  std::cout << "\n";
}

Status ListDelete(SqList* L, int i, ElemType* e) {

  if (L == nullptr || L->elem == nullptr) {
    return kError;
  }

  if (i < 1 || i > L->length) {
    return kError;
  }

  ElemType* p;
  ElemType* q;

  // p is the position to delete.
  p = &(L->elem[i - 1]);

  //  Get the deleted elem.
  *e = *p;

  // q is the tail of list.
  q = L->elem + L->length - 1;

  // move elements to left.
  for (++p; p <= q; ++p) {
    *(p - 1) = *p;
  }

  // Modify the length.
  --L->length;

  return kOK;
}

int LocateElem(const SqList& L, ElemType e,
               std::function<Status(ElemType, ElemType)> compare) {
  int i;
  ElemType* p;
  if (L.elem == nullptr) {
    return kError;
  }

  i = 1;
  p = L.elem;

  while (i <= L.length && !compare(*p++, e)) {
    ++i;
  }

  if (i <= L.length) {
    return i;
  }
  return 0;
}
