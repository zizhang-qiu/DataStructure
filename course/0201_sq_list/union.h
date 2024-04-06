#ifndef COURSE_0201_SQ_LIST_UNION_H
#define COURSE_0201_SQ_LIST_UNION_H
#include "sq_list.h"
#include "status.h"

// Example 2-1 on page 20.
// Make union of 2 sq lists without out repetition, A = A \cup B.
void Union(SqList* lhs, const SqList& rhs);

Status Equal(const ElemType& lhs, const  ElemType& rhs);

#endif /* COURSE_0201_SQ_LIST_UNION_H */
