#include "merge.h"

void MergeList(LinkList* La, LinkList* Lb, LinkList* Lc){
    LinkList pa = (*La)->next;
    LinkList pb = (*Lb)->next;
    LinkList pc = *Lc = *La;

    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    pc->next = pa? pa: pb;

    delete *Lb;

    *La = nullptr;
    *Lb = nullptr;
}