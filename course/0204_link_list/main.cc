#include <iostream>
#include "link_list.h"
#include "status.h"

Status CmpGreater(const ElemType data, const ElemType e) {
  return data > e ? kTrue : kFalse;
}

int main() {
  LinkList L;
  ElemType e;
  auto visit = [](const ElemType e) {
    std::cout << e << " ";
  };

  std::cout << "Initialize Link list\n";
  InitList(&L);

  std::cout << "ListEmpty\n";
  if (ListEmpty(L)) {
    std::cout << "The list is empty.";
  } else {
    std::cout << "The list is not empty.";
  }

  std::cout << "ListInsert\n";
  for (int i = 1; i <= 8; ++i) {
    std::cout << "Insert " << 2 * i << " at position " << i << ".\n";
    ListInsert(L, i, 2 * i);
  }
  ListTraverse(L, visit);

  std::cout << "ListLength\n";
  std::cout << "The length of L is " << ListLength(L) << ".\n";

  std::cout << "ListDelete\n";
  std::cout << "Elements before delete, L = ";
  ListTraverse(L, visit);

  std::cout << "Delete the 6th element in link list.\n";
  if (ListDelete(L, 6, &e) == kOK) {
    std::cout << "Delete successfully, the deleted element is " << e << ".\n";
  } else {
    std::cout << "Delete failed, the 6th element doesn't exist.\n";
  }

  std::cout << "Elements after delete, L = ";
  ListTraverse(L, visit);

  std::cout << "GetElem\n";
  GetElem(L, 4, &e);
  std::cout << "The 4th element in L is " << e << ".\n";

  std::cout << "LocateElem\n";
  int index = LocateElem(L, 7, CmpGreater);
  std::cout << "The first element that is greater than 7 in the list is " << e
            << "at position" << index << ".\n";

  std::cout << "PriorElem\n";
  ElemType cur_e = 6;
  if (PriorElem(L, cur_e, &e) == kOK) {
    std::cout << "The prior of element 6 is " << e << ".\n";
  } else {
    std::cout << "The prior of element 6 doesn't exist.\n";
  }

  std::cout << "NextElem\n";
  if (NextElem(L, cur_e, &e) == kOK) {
    std::cout << "The next of element 6 is " << e << ".\n";
  } else {
    std::cout << "The next of element 6 doesn;t exist.\n";
  }

  std::cout << "ClearList\n";
  std::cout << "Before clear: ";
  if (ListEmpty(L)) {
    std::cout << "The list is empty.\n";
  } else {
    std::cout << "The list is not empty.\n";
  }

  ClearList(L);
  std::cout << "After clear: ";
  if (ListEmpty(L)) {
    std::cout << "The list is empty.\n";
  } else {
    std::cout << "The list is not empty.\n";
  }

  std::cout << "DestroyList\n";
  std::cout << "Before destroy: ";
  if (L!=nullptr) {
    std::cout << "L exists.\n";
  }else{
    std::cout <<"L doesn't exist.\n";
  }
  DestroyList(&L);
  std::cout << "After destroy: ";
  if (L != nullptr) {
    std::cout << "L exists.\n";
  } else {
    std::cout << "L doesn't exist.\n";
  }

  std::cout << "Create link list from head.\n";
  const std::vector<int> nums1 = {9, 7, 5, 3, 1};
  {
    LinkList L;
    CreateListHead(&L, 5, nums1);
    ListTraverse(L, visit);
  }

  std::cout << "Create link list from tail.\n";
  const std::vector<int> nums2 = {1,3,5,7,9};
  {
    LinkList L;
    CreateListTail(&L, 5, nums2);
    ListTraverse(L, visit);
  }

  return 0;
}