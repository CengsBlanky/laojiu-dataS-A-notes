#include "StaticLinkList.h"

int getFreeNode (StaticLinkList slList);

void releaseNodeByIndex (StaticLinkList slList, int index);

void initSLL (StaticLinkList slList) {
    for (int i = 0; i < MAX_SLL_SIZE; i++) {
        slList[i].data.id = -1;
        slList[i].data.name = "NULL";
        slList[i].cursor = i + 1;
    }
    // 最后一个元素游标初始化为0
    slList[MAX_SLL_SIZE - 1].cursor = 0;
    // 最后一个数据域元素游标为0
    slList[MAX_SLL_SIZE - 2].cursor = 0;
}

void printSLL (StaticLinkList slList) {
    for (int i = 0; i < MAX_SLL_SIZE; i++) {
        printf("index: %d\tcursor: %d\n", i, slList[i].cursor);
    }
}

void insertSLL (StaticLinkList slList, DataType * data, int position) {
    if (position < 1 || position > getSLLLength(slList) + 1) {
        printf("position out of range!");
        exit(1);
    }
    int insertIndex = getFreeNode(slList);
    int preIndex = slList[MAX_SLL_SIZE - 1].cursor; // 这是第一个插入的节点,以此开始遍历查找
    if (position == 1 || preIndex == 0) {
        slList[insertIndex].data = *data;
        slList[MAX_SLL_SIZE - 1].cursor = insertIndex;
        slList[insertIndex].cursor = preIndex;
        return;
    }
    if (insertIndex) {
        slList[insertIndex].data = *data;
        // find previous node
        for (int i = 1; i < position - 1; i++) {
            preIndex = slList[preIndex].cursor;
        }
        if (preIndex) {
            slList[insertIndex].cursor = slList[preIndex].cursor;
            slList[preIndex].cursor = insertIndex;
        }
    }
}

int getSLLLength (StaticLinkList slList) {
    int index = slList[MAX_SLL_SIZE - 1].cursor;
    int count = 0;
    while (index) {
        index = slList[index].cursor;
        count++;
    }
    return count;
}

int getFreeNode (StaticLinkList slList) {
    int freeIndex = slList[0].cursor;
    // allocate new free node
    if (slList[freeIndex].cursor) {
        slList[0].cursor = slList[freeIndex].cursor;
    }
    return freeIndex;
}

void printSLLDatas (StaticLinkList slList) {
    int firstDataIndex = slList[MAX_SLL_SIZE - 1].cursor;
    while (firstDataIndex) {
        printf("-----index: %d\nid: %d\tname: %s\n-----cursor: %d\n", \
        firstDataIndex,\
        slList[firstDataIndex].data.id,\
        slList[firstDataIndex].data.name,\
        slList[firstDataIndex].cursor);

        firstDataIndex = slList[firstDataIndex].cursor;
    }
}

void printAll (StaticLinkList slList) {
    printf("index\tid\t%-12scursor\n", "name");
    for (int index = 0; index < MAX_SLL_SIZE; index++) {
        if (index == 1 || index == MAX_SLL_SIZE - 1) {
            printf("%30s\n", "-----------------------------------");
        }
        printf("%d\t%d\t%-15s%-10d\n",\
        index,\
        slList[index].data.id,\
        slList[index].data.name,\
        slList[index].cursor\
        );
    }
}

void deleteByPosition (StaticLinkList slList, int position) {
    // 通过循环找到要删除节点的前一个结点
    int preIndex = slList[MAX_SLL_SIZE - 1].cursor;
    for (int i = 1; i < position - 1; i++) {
        preIndex = slList[preIndex].cursor;
    }
    int deleteIndex = slList[preIndex].cursor;
    // 使前一位游标指向待删除元素的下一个节点
    slList[preIndex].cursor = slList[deleteIndex].cursor;
    releaseNodeByIndex(slList, deleteIndex);
    /** 总的来说分三步:
     *  1.找到待删除元素的前一个节点
     *  2.将前一个节点游标指向被删除元素的下一个节点
     *  3.将待删除节点加入备用链表第一位,即第一个数组游标所指下标,实际并未删除其中的数据,但是后面加入或者插入节点会覆盖其中的数据
    */
}

void releaseNodeByIndex (StaticLinkList slList, int index) {
    // 这里的清理只是将对应的节点加入备用节点,但是在清理之前,必须将其后一位节点接到其前一位结点之后
    slList[index].cursor = slList[0].cursor;
    slList[0].cursor = index;
}