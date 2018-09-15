/**
 * This is the binary tree definition via link
 **/
#include <stdlib.h>

typedef char DataType;

typedef struct btnode
{
    /* data */
    DataType data;
    struct btnode *lchild, *rchild;
} *BinTree;

typedef struct ttnode 
{
    DataType data;
    struct ttnode *lchild, *rchild, *parent;
} *TBinTree;

/**
 * 
 **/ 
void visit(BinTree bt);

void preorder(BinTree bt);

void inorder(BinTree bt);

void postorder(BinTree bt);

int caculateBinTreeHeight(BinTree bt);

void levelorder(BinTree bt);

/**
 * 使用二叉树的先序遍历和中序遍历构建二叉树
 * 数组a存储先序序列，i和j分别是数组a的下标的上、下界
 * 数组b存储中序序列，m和n分别是数组b的下标的上、下界
 **/
BinTree CreateTree(DataType a[], DataType b[], int i, int j, int m, int n, char *str);

BinTree InitBinTree();

/******
 * Link
 ******/
typedef struct link 
{
    BinTree bt;
    struct link *next;
} *Link;

/*******
 * Queue
 *******/
typedef struct queue
{
    Link lk;
    Link front, rear;
} *LkQue;

void InitQueue(LkQue q);

void EnterQueue(LkQue q, BinTree bt);

int EmptyQueue(LkQue q);

BinTree GetQueueHead(LkQue q);

void OutQueue(LkQue Q);
