#include <vector>
#include "merge.h"

int main() {
  LinkList La, Lb, Lc;

  const int n = 5;

  std::cout << "Creating La and Lb...\n";
  const std::vector<int> nums1 = {9, 7, 5, 3, 1};
  const std::vector<int> nums2 = {2, 4, 6, 8, 10};

  CreateListHead(&La, n, nums1);
  CreateListTail(&Lb, n, nums2);
  auto visit = [](const ElemType e) {
    std::cout << e << " ";
  };

  std::cout << "La = ";
  ListTraverse(La, visit);

  std::cout << "Lb = ";
  ListTraverse(Lb, visit);

  std::cout << "After merge, Lc = ";
  MergeList(&La, &Lb, &Lc);
  ListTraverse(Lc, visit);

  return 0;
}