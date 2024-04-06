#include <iostream>

#include "sq_list.h"
#include "status.h"

void Print(ElemType e) {
  std::cout << e << " ";
}

Status Compare(const ElemType& lhs, const ElemType& rhs) {
  return lhs > rhs ? kTrue : kFalse;
}

int main() {
  SqList L;  // 待操作的顺序表

  int i;
  ElemType e;

  std::cout << "InitList \n";
  {
    std::cout << "Initialize sq list L ...\n";
    InitList(&L);
  }

  std::cout << "ListEmpty: " << ListEmpty(L) << std::endl;

  std::cout << "ListInsert \n";
  for (int i = 1; i <= 120; ++i) {
    std::cout << "Insert " << 2 * i << " at position " << i << ".\n";
    ListInsert(&L, i, 2 * i);
  }
  ListTraverse(L, Print);

  std::cout << "ListLength: " << ListLength(L) << std::endl;

  std::cout << "ListDelete\n";

  std::cout << "Before delete: \n";
  ListTraverse(L, Print);

  std::cout << "Delete the 6th element in L.\n";
  if (ListDelete(&L, 6, &e) == kOK) {
    std::cout << "Delete successfully, the 6th element is " << e << std::endl;
  } else {
    std::cout << "Delete failed, the 6th element doesn't exist.";
  }

  std::cout << "After delete: \n";
  ListTraverse(L, Print);

  std::cout << "GetElem\n";
  GetElem(L, 4, &e);
  std::cout << "The 4th element in L is " << e << std::endl;

  std::cout << "LocateElem\n";
  i = LocateElem(L, 7, Compare);
  std::cout << "The first element that is greater than 7 is " << L.elem[i - 1]
            << ".\n";

  std::cout << "PriorElem\n";
  ElemType cur_e = 6;
  if (PriorElem(L, cur_e, &e) == kOK) {
    std::cout << "The prior element of element " << cur_e << " is " << e
              << ".\n";
  } else {
    std::cout << "The prior element of element " << cur_e << " doesn't exist\n";
  }

  std::cout << "NextElem\n";
  if (NextElem(L, cur_e, &e) == kOK) {
    std::cout << "The next element of element " << cur_e << " is " << e
              << ".\n";
  } else {
    std::cout << "The next element of element " << cur_e << " doesn't exist\n";
  }

  std::cout << "ClearList\n";
  std::cout << "Before clear: ";
  //   ListTraverse(L, Print);
  if (ListEmpty(L) == kTrue) {
    std::cout << "L is empty.\n";
  } else {
    std::cout << "L is not empty.\n";
  }

  ClearList(&L);

  std::cout << "After clear: ";
  if (ListEmpty(L) == kTrue) {
    std::cout << "L is empty.\n";
  } else {
    std::cout << "L is not empty.\n";
  }

  std::cout << "DestroyList\n";
  std::cout << "Before destroy: ";
  if (L.elem != nullptr) {
    std::cout << "L exists.\n";
  } else {
    std::cout << "L doesn't exist.\n";
  }

  DestroyList(&L);
  if (L.elem != nullptr) {
    std::cout << "L exists.\n";
  } else {
    std::cout << "L doesn't exist.\n";
  }

  return 0;
}