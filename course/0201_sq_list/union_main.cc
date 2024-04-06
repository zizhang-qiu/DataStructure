#include <iostream>
#include "union.h"

int main() {
  ElemType a[5] = {5, 2, 1, 3, 9};
  ElemType b[7] = {7, 2, 6, 9, 11, 3, 10};
  SqList la, lb;

  // Initialize La.
  InitList(&la);
  for (int i = 1; i <= 5; ++i) {
    ListInsert(&la, i, a[i - 1]);
  }

  // Initialize Lb.
  InitList(&lb);
  for (int i = 1; i <= 7; ++i) {
    ListInsert(&lb, i, b[i - 1]);
  }

  auto print = [](const ElemType& e){std::cout << e << " ";};
  std::cout << "la = ";
  ListTraverse(la, print);

  std::cout << "lb = ";
  ListTraverse(lb, print);

  std::cout << "The union of la and lb = ";
  Union(&la, lb);
  ListTraverse(la, print);

  return 0;
}