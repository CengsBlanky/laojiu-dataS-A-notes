/**
 * @author: zengshuai (zengs1994@gmail.com)
 * @created: 2021/04/21 16:38:22 中国标准时间 Wednesday
 * @filename: Brother.h
 */

#ifndef BROTHER_H_INCLUDED
#define BROTHER_H_INCLUDED

#include "ElementType.h"

typedef struct cbNode {
    ElementType data;
    struct cbNode * firstChild; // 长子结点
    struct cbNode * nextSibling; // 兄弟结点
}CBNode, * CBTree;

void InitCBTree(CBTree * tree);

#endif

