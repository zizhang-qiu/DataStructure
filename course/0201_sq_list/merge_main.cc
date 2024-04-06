#include <iostream>
#include "merge.h"

int main() {
  ElemType a[4] = {3, 5, 8, 11};
  ElemType b[7] = {2, 6, 8, 9, 11, 15, 20};

  SqList la, lb, lc1, lc2;

  // Initialize la.
  InitList(&la);
  for (int i = 1; i <= 4; ++i) {
    ListInsert(&la, i, a[i - 1]);
  }

  // Initialize lb.
  InitList(&lb);
  for (int i = 1; i <= 7; ++i) {
    ListInsert(&lb, i, b[i - 1]);
  }

  auto print = [](const ElemType& e) {
    std::cout << e << " ";
  };
  std::cout << "la = ";
  ListTraverse(la, print);

  std::cout << "lb = ";
  ListTraverse(lb, print);

  MergeList(la, lb, &lc1);
  std::cout << "After merge, lc1 = ";
  ListTraverse(lc1, print);

  MergeList(la, lb, &lc2);
  std::cout << "After merge, lc2 = ";
  ListTraverse(lc2, print);

  return 0;
}