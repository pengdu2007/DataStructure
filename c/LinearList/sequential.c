#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量

int InitList(); // 初始化线性表
int Insert(); // 插入元素
int Delete(); // 删除元素
int Locate(); // 查找元素

// 线性表顺序存储结构
typedef struct {
    int *elem; // 存储空间基址
    int length; // 当前长度
    int listSize; // 当前分配存储容量
} SqList;

int main() {
    SqList list;
    // printf("list.length: %d, listSize: %d\n", list.length, list.listSize);
    InitList(&list);
    // printf("list.length: %d, listSize: %d\n", list.length, list.listSize);
    for (int i = 0; i < 10; i++) {
        Insert(&list, i + 1, i + 1);
    }

    printf("list: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");
    printf("Locate: %d: %d\n", 5, Locate(list, 5));
    printf("list.length: %d\n", list.length);
    int d = Delete(&list, 2);
    printf("Delete: %d, list.length: %d\n", d, list.length);

    printf("list: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");
    printf("Locate: %d: %d\n", 5, Locate(list, 5));
    return 0;
}

// 初始化线性表
int InitList(SqList *L) {
    L->elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L->elem) { // 分配存储空间失败
        exit(-1);
    }
    L->length = 0; // 空表长度为0
    L->listSize = LIST_INIT_SIZE; // 初始存储容量
    return 0;
}

// 线性表插入
// 往第i个元素前插入一个元素e
int Insert(SqList *L, int i, int e) {
    if ((i < 1) || (i > L->length + 1)) {
        //printf("插入位置i值不合法");
        return -1;
    }
    if (L->length >= L->listSize) { // 当前存储空间已满, 增加分配
        //printf("当前存储空间已满, 需增加存储空间");
        int *new = (int *) realloc(L->elem, (L->listSize + LISTINCREMENT) * sizeof(int));
        if (!new) {
            return -1;
        }
        L->elem = new;
        L->listSize += LISTINCREMENT;
    }
    int *p, *q;
    q = &(L->elem[i - 1]);
    for (p = &(L->elem[L->length - 1]); p >= q; p--) {
        *(p + 1) = *p;
    }
    *q = e;
    L->length++;
    return 0;
}
// 在表L中删除第i个元素, 并用e返回其值
int Delete(SqList *L, int i) {
    if ((i < 1) || (i > L->length)) { // 检查i边界
        return -1;
    }
    int *p, *q;
    p = &(L->elem[i - 1]); // p 指向被删除的元素的地址
    int e = *p;
    q = &(L->elem[L->length - 1]); // q指向最后一个元素的位置
    for (++p; p <= q; ++p) { // 从p的下一个位置开始遍历
        *(p - 1) = *p; // 每次往前移动一个元素
    }
    L->length --;
    return e;
}
// 线性表查找
int Locate(SqList L, int e) {
    int i = 1;
    printf("list.length: %d\n", L.length);
    printf("i :");
    while (i <= L.length && L.elem[i] != e) {
        printf("%d ", i);
        i++;
    }
    if (i <= L.length ) {
        return i + 1;
    }else {
        return -1;
    }
}