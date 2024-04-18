#include "s_link_list.h"
#include "status.h"

void InitSpace(SLinkList space) {
  for (int i = 0; i < kMaxSize - 1; ++i) {
    space[i].cur = i + 1;
  }

  space[kMaxSize - 1].cur = 0;
}

int Malloc(SLinkList space) {
  int i = space[0].cur;

  if (i != 0) {
    space[0].cur = space[i].cur;
  }

  return i;
}

void Free(SLinkList space, int k) {
  space[k].cur = space[0].cur;
  space[0].cur = k;
}

Status InitList(SLinkList space, int* s) {
  int index;

  InitSpace(space);

  index = Malloc(space);

  if (index == 0) {
    return kError;
  }

  space[index].cur = 0;

  *s = index;

  return kOK;
}

Status DestroyList(SLinkList space, int* s) {
  int cur;

  if (s == nullptr || *s == 0) {
    return kError;
  }

  while (*s != 0) {
    cur = space[*s].cur;
    Free(space, *s);
    *s = cur;
  }

  return kOK;
}

Status ClearList(SLinkList space, int s) {
  int p;
  int cur;

  if (s == 0) {
    return kError;
  }

  p = space[s].cur;

  while (p != 0) {
    cur = space[p].cur;
    Free(space, p);
    p = cur;
  }

  space[s].cur = 0;

  return kOK;
}

Status ListEmpty(SLinkList space, int s) {
  if (s != 0 && space[s].cur == 0) {
    return kTrue;
  } else {
    return kFalse;
  }
}

int ListLength(SLinkList space, int s) {
  if (s == 0 || space[s].cur == 0) {
    return 0;
  }

  int count = 0;
  s = space[s].cur;

  while (s != 0) {
    count++;
    s = space[s].cur;
  }

  return count;
}

Status GetElem(SLinkList space, int s, int i, ElemType* e) {
  if (s == 0 || space[s].cur == 0) {
    return kError;
  }

  s = space[s].cur;
  int count = 0;

  while (s != 0 && count < i - 1) {
    count++;
    s = space[s].cur;
  }

  if (s == 0 || count > i - 1) {
    return kError;
  }

  *e = space[s].data;

  return kOK;
}

int LocateElem(SLinkList space, int s, ElemType e,
               std::function<Status(ElemType, ElemType)> compare) {
  if (s == 0 || space[s].cur == 0) {
    return 0;
  }

  int i = 1;
  int p = space[s].cur;

  while (p != 0 && !compare(space[p].data, e)) {
    ++i;
    p = space[p].cur;
  }

  if (p != 0) {
    return i;
  }
  return 0;
}

Status PriorElem(SLinkList space, int s, ElemType cur_e, ElemType* pre_e) {
  if (s == 0 || space[s].cur == 0) {
    return 0;
  }

  int pre = space[s].cur;
  int next;

  // Special case.
  if (space[pre].data == cur_e) {
    return kError;
  }

  next = space[pre].cur;

  while (next != 0 && space[next].data != cur_e) {
    pre = next;
    next = space[next].cur;
  }

  if (next == 0) {
    return kError;
  }

  *pre_e = space[pre].data;

  return kOK;
}

Status NextElem(SLinkList space, int s, ElemType cur_e, ElemType* next_e) {
  if (s == 0 || space[s].cur == 0) {
    return 0;
  }

  int pre = space[s].cur;

  while (space[pre].cur != 0 && space[pre].data != cur_e) {
    pre = space[pre].cur;
  }

  if (space[pre].cur == 0) {
    return kError;
  }

  *next_e = space[space[pre].cur].data;

  return kOK;
}

Status ListInsert(SLinkList space, int s, int i, ElemType e) {
  if (s == 0) {
    return kError;
  }

  int p = s;
  int new_s;
  int j = 0;

  while (p != 0 && j < i - 1) {
    p = space[p].cur;
    ++j;
  }

  if (p == 0 || j > i - 1) {
    return kError;
  }

  new_s = Malloc(space);
  space[new_s].data = e;
  space[new_s].cur = space[p].cur;
  space[p].cur = new_s;

  return kOK;
}

Status ListDelete(SLinkList space, int s, int i, ElemType* e) {
  if (s == 0) {
    return kError;
  }

  int p = s;
  int j = 0;
  int q;

  while (space[p].cur != 0 && j < i - 1) {
    p = space[p].cur;
    ++j;
  }

  if(space[p].cur == 0 || j > i - 1){
    return kError;
  }

  q = space[p].cur;
  space[p].cur = space[q].cur;
  *e = space[q].data;
  Free(space, q);

  return kOK;
}

void ListTraverse(SLinkList space, int s, std::function<void(ElemType)> visit){
    if(s == 0 || space[s].cur == 0){
        return;
    }

    int p = space[s].cur;

    while(p != 0){
        visit(space[p].data);
        p = space[p].cur;
    }
    std::cout << "\n";
}

void PrintList(SLinkList space, int s){
    int i=0;

    std::cout << "Backup space\n";

    while (i < 20){
      printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
      i = space[i].cur;
    }

    std::cout << "S link list\n";
    i = s;
    while(i > 0 && i < 20){
      printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
      i = space[i].cur;
    }
}