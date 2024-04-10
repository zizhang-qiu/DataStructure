#include "link_list.h"
#include <cstdlib>
#include <iostream>
#include "status.h"

Status InitList(LinkList* L) {
  *L = new LNode;
  if (*L == nullptr) {
    std::exit(kOverflow);
  }

  (*L)->next = nullptr;

  return kOK;
}

Status DestroyList(LinkList* L) {
  if (L == nullptr || *L == nullptr) {
    return kError;
  }

  LinkList p = *L;
  while (p != nullptr) {
    p = (*L)->next;
    delete *L;
    (*L) = p;
  }

  *L = nullptr;

  return kOK;
}

Status ClearList(LinkList L) {
  if (L == nullptr) {
    return kError;
  }

  LinkList pre, p;
  p = L->next;

  while (p != nullptr) {
    pre = p;
    p = p->next;
    delete pre;
  }

  L->next = nullptr;

  return kOK;
}

Status ListEmpty(const LinkList& L) {
  if (L != nullptr && L->next == nullptr) {
    return kTrue;
  }
  return kFalse;
}

int ListLength(const LinkList& L) {
  LinkList p;
  int i;

  if (L == nullptr || L->next == nullptr) {
    return 0;
  }

  i = 0;
  p = L->next;

  // Traverse all nodes.
  while (p != nullptr) {
    ++i;
    p = p->next;
  }

  return i;
}

Status GetElem(const LinkList& L, int i, ElemType* e) {
  if (L == nullptr || L->next == nullptr) {
    return kError;
  }

  LinkList p = L;
  int j = 0;

  while (p->next != nullptr && j < i - 1) {
    p = p->next;
    ++j;
  }

  if (p->next == nullptr || j > i - 1) {
    return kError;
  }

  *e = p->next->data;

  return kOK;
}

int LocateElem(const LinkList& L, ElemType e,
               std::function<Status(ElemType, ElemType)> compare) {
  if (L == nullptr || L->next == nullptr) {
    return 0;
  }

  int i = 1;
  LinkList p = L->next;

  while (p != nullptr && !compare(p->data, e)) {
    ++i;
    p = p->next;
  }

  if (p != nullptr) {
    return i;
  }
  return 0;
}

Status PriorElem(const LinkList& L, ElemType cur_e, ElemType* pre_e) {
  if (L == nullptr || L->next == nullptr) {
    return kError;
  }

  LinkList pre, next;
  pre = L->next;

  if (pre->data == cur_e) {
    return kError;
  }

  next = pre->next;

  while (next != nullptr && next->data != cur_e) {
    pre = next;
    next = next->next;
  }

  if (next == nullptr) {
    return kError;
  }

  *pre_e = pre->data;
  return kOK;
}

Status NextElem(const LinkList& L, ElemType cur_e, ElemType* next_e) {
  if (L == nullptr || L->next == nullptr) {
    return kError;
  }

  LinkList pre = L->next;

  while (pre->next != nullptr && pre->data != cur_e) {
    pre = pre->next;
  }

  if (pre->next == nullptr) {
    return kError;
  }

  *next_e = pre->next->data;

  return kOK;
}

Status ListInsert(const LinkList& L, int i, ElemType e) {
  if (L == nullptr) {
    return kError;
  }

  LinkList p = L;
  LinkList s;
  int j = 0;

  while (p != nullptr && j < i - 1) {
    p = p->next;
    ++j;
  }

  if (p == nullptr || j > i - 1) {
    return kError;
  }

  s = new LNode;
  if (s == nullptr) {
    return kError;
  }

  s->data = e;
  s->next = p->next;
  p->next = s;

  return kOK;
}

Status ListDelete(const LinkList& L, int i, ElemType* e) {
  if (L == nullptr || L->next == nullptr) {
    return kError;
  }

  LinkList p = L;
  LinkList q;
  int j = 0;

  while (p->next != nullptr && j < i - 1) {
    p = p->next;
    ++j;
  }

  if (p == nullptr || j > i - 1) {
    return kError;
  }

  q = p->next;
  p->next = q->next;
  *e = q->data;
  delete q;

  return kOK;
}

void ListTraverse(const LinkList& L, std::function<void(ElemType)> visit) {
  if (L == nullptr || L->next == nullptr) {
    return;
  }

  LinkList p = L->next;

  while (p != nullptr) {
    visit(p->data);
    p = p->next;
  }

  std::cout << "\n";
}

// Create link list from head.
Status CreateListHead(LinkList* L, int n, const std::vector<int>& nums) {

  if (nums.size() < n) {
    return kError;
  }
  LinkList p;
  *L = new LNode();
  (*L)->next = nullptr;

  for (int i = 1; i <= n; ++i) {
    p = new LNode();
    p->data = nums[i - 1];
    p->next = (*L)->next;
    (*L)->next = p;
  }
  return kOK;
}

Status CreateListTail(LinkList* L, int n, const std::vector<int>& nums){
  if (nums.size() < n) {
    return kError;
  }
  LinkList p, q;
  *L = new LNode();
  (*L)->next = nullptr;
  int i;
  for(i=1, q=*L; i<=n; ++i){
    p = new LNode();
    p->data = nums[i-1];

    q->next = p;
    q = q->next;
  }

  return kOK;
}