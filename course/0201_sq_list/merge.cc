#include "merge.h"
#include <cstdlib>
#include "status.h"

void MergeList(const SqList& la, const SqList& lb, SqList* lc) {
  InitList(lc);
  int i = 1, j = 1, k = 0;
  const int len_la = ListLength(la);
  const int len_lb = ListLength(lb);
  ElemType ai;
  ElemType bj;
  while ((i <= len_la) && (j <= len_lb)) {
    GetElem(la, i, &ai);
    GetElem(lb, j, &bj);

    if (ai <= bj) {
      ListInsert(lc, ++k, ai);
      ++i;
    } else {
      ListInsert(lc, ++k, bj);
      ++j;
    }
  }

  // Deal with remained elements.
  while (i <= len_la) {
    GetElem(la, i, &ai);
    ListInsert(lc, ++k, ai);
    ++i;
  }

  while (j <= len_lb) {
    GetElem(lb, j, &bj);
    ListInsert(lc, ++k, bj);
    ++j;
  }
}

void MergeList2(const SqList& la, const SqList& lb, SqList* lc) {
  ElemType* pa;
  ElemType* pb;
  ElemType* pc;
  ElemType *pa_last, *pb_last;
  pa = la.elem;
  pb = lb.elem;

  lc->list_size = lc->length = la.length + lb.length;
  pc = lc->elem = new ElemType[lc->list_size];

  if (pc == nullptr) {
    std::exit(kOverflow);
  }

  pa_last = la.elem + la.length - 1;
  pb_last = lb.elem + lb.length - 1;
  while (pa <= pa_last && pb < pb_last) {
    if (*pa <= *pb) {
      *pc = *pa;
      ++pc;
      ++pa;
    } else {
      *pc = *pb;
      ++pc;
      ++pb;
    }
  }

  // Deal with remained elements.
  while (pa <= pa_last) {
    *pc++ = *pa++;
  }
  while (pb <= pb_last) {
    *pc++ = *pb++;
  }
}
