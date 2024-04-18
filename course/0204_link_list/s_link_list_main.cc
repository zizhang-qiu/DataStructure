#include "s_link_list.h"
#include "status.h"

int main(){
    SLinkList space;
    int s;

    int i;
    ElemType e;

    std::cout << "InitList\n";
    InitList(space, &s);

    std::cout << "ListEmpty\n";
    if (ListEmpty(space, s)) {
        std::cout << "List is empty.\n";
    }else{
        std::cout << "List is not empty.\n";
    }

    std::cout << "ListInsert\n";
    {
        for(int i=0; i<=8; ++i){
          std::cout << "Insert " << 2 * i << " at position " << i << ".\n";
          ListInsert(space, s, i, 2*i);
        }
    }

    auto print = [](const ElemType& e){
        std::cout << e << " ";
    };
    std::cout << "ListTraverse\n";
    ListTraverse(space, s, print);

    std::cout << "ListLength\n";
    std::cout << "The length of the list is " << ListLength(space, s) << ".\n";

    std::cout << "ListDelete\n";
    std::cout << "Before delete, the list is ";
    ListTraverse(space, s, print);
    std::cout << "Trying to delete the 6th element in list...\n";
    if(ListDelete(space, s, 6, &e) == kOK){
        std::cout << "Delete success, the deleted element is " << e << ".\n";
    }else{
        std::cout << "Failed to delete the 6th element.\n";
    }

    std::cout << "After delete, the list is ";
    ListTraverse(space, s, print);

    std::cout << "GetElem\n";
    GetElem(space, s, 4, &e);
    std::cout << "The 4th element in list is " << e << ".\n";

    std::cout << "LocateElem\n";
    auto cmp = [](const ElemType data, const ElemType e)->Status{
        return data > e? kTrue : kFalse;
    };
    i = LocateElem(space, s, 7, cmp);
    GetElem(space, s, i, &e);
    std::cout << "The first element in list that is greater than 7 is " << e << ".\n";

    std::cout << "PriorElem\n";
    {
      ElemType cur_e = 6;
      if (PriorElem(space, s, cur_e, &e) == kOK) {
        std::cout << "The prior element of element " << cur_e << " is " << e
                  << ".\n";
      } else {
        std::cout << "The prior element of element " << cur_e
                  << " doesn't exist.\n";
      }
    }
    

    std::cout << "NextElem\n";
    {
      ElemType cur_e = 6;
      if (NextElem(space, s, cur_e, &e) == kOK) {
        std::cout << "The next element of element " << cur_e << " is " << e
                  << ".\n";
      } else {
        std::cout << "The next element of element " << cur_e
                  << " doesn't exist.\n";
      }
    }

    std::cout << "ClearList\n";
    std::cout << "Before clear: ";
    if (ListEmpty(space, s)) {
      std::cout << "List is empty.\n";
    } else {
      std::cout << "List is not empty.\n";
    }

    ClearList(space, s);
    std::cout << "After clear: ";
    if (ListEmpty(space, s)) {
      std::cout << "List is empty.\n";
    } else {
      std::cout << "List is not empty.\n";
    }

    std::cout << "DestroyList\n";
    std::cout << "Before destroy: ";
    if(s!=0){
        std::cout << "The list exists.\n";
    }else{
        std::cout << "The list doesn't exist.\n";
    }

    DestroyList(space, &s);
    if (s != 0) {
      std::cout << "The list exists.\n";
    } else {
      std::cout << "The list doesn't exist.\n";
    }

    return 0;
}