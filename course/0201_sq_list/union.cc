#include "union.h"
#include "status.h"

void Union(SqList* lhs, const SqList& rhs) {
    int len_lhs = ListLength(*lhs);
    const int len_rhs = ListLength(rhs);
    ElemType e;
    for(int i=1; i<= len_rhs; ++i){
        GetElem(rhs, i, &e);

        if(!LocateElem(*lhs, e, Equal)){
            ListInsert(lhs, ++len_lhs, e);
        }
    }
}

Status Equal(const ElemType& lhs, const ElemType& rhs){
    return lhs == rhs? kTrue: kFalse;
}