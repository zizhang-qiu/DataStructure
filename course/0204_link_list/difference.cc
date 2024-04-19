#include "difference.h"
#include "s_link_list.h"

void Difference(SLinkList space, int* s, const std::vector<ElemType>& nums1,
                const std::vector<ElemType>& nums2) {
  InitSpace(space);
  *s = Malloc(space);

  int r = *s;
  int i;

  // Insert A data.
  for (int j = 1; j <= static_cast<int>(nums1.size()); ++j) {
    i = Malloc(space);
    space[i].data = nums1.at(j - 1);
    space[r].cur = i;
    r = i;
  }
  space[r].cur = 0;

  int p, k;
  for (int j = 1; j <= static_cast<int>(nums2.size()); ++j) {
    ElemType b = nums2.at(j - 1);
    p = *s;
    k = space[*s].cur;
    while (k != space[r].cur && space[k].data != b) {
      p = k;
      k = space[k].cur;
    }

    if (k == space[r].cur) {
        i = Malloc(space);
        space[i].data = b;
        space[i].cur = space[r].cur;
        space[r].cur = i;
    }else{
        space[p].cur = space[k].cur;
        Free(space, k);
        if (r == k) {
            r = p;
        }
    }
  }
}
