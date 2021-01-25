#include<stdio.h>
#include <stdlib.h>

// 二叉树: 每个结点至多只有两课子树(即二叉树中不存在度大于2的结点), 并且二叉树的子树有左右之分, 其次序不能任意颠倒
typedef int elemtype;

typedef struct bitnode {
    elemtype data;
    struct bitnode *lchild, *rchild;
} bitnode, *bitree;

// 生成二叉树: 先序遍历
bitree CreateBiTree() {
    bitree t;
    char ch;
    scanf("%c", &ch);
    if (ch == ' ') {
        t = NULL;
    }else {
        t = (bitnode *) malloc(sizeof(bitnode));
        t->data = ch;
        t->lchild = CreateBiTree();
        t->rchild = CreateBiTree();
    }
    return t;
}
// 遍历二叉树: 先序遍历
void PreOrderTraverse(bitree bt) {
    if (bt != NULL) {
        printf("%c", bt->data);
        PreOrderTraverse(bt->lchild);
        PreOrderTraverse(bt->rchild);
    }
}

int main() {
    printf("Create Binary Tree: \n");
    bitree bt = CreateBiTree();
    printf("PreOrderTraverse: \n");
    PreOrderTraverse(bt);
    return 0;
}