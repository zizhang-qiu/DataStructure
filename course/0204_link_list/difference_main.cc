#include <vector>
#include "difference.h"
#include "s_link_list.h"

int main(){
    SLinkList space;
    int s;

    const std::vector<ElemType> nums1 = {2, 3, 4};
    const std::vector<ElemType> nums2 = {1,3,4,6,7};

    Difference(space, &s,  nums1, nums2);

    auto print = [](const ElemType e){
        std::cout << e << " ";
    };
    ListTraverse(space, s, print);

    return 0;
}