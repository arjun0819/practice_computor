#include <stdlib.h>
#include <stdio.h>

#include "./tree.h"

void visit(BinTree bt) 
{
    if (bt != NULL){
        printf("Data printing ...");
        printf("Node data = %d, data = '%c' \n", bt->data ? bt->data : -1, bt->data);
    }else {
        printf("NULL");
    }
}

void preorder(BinTree bt) 
{
    // printf("Print tree L = '%c' R = '%c' \n", bt->lchild->rchild->data, bt->rchild->data);
    if (bt != NULL)
    {
        visit(bt);
        if (bt->lchild == NULL)
            printf("lchild of '%c' is null", bt->data);
        if (bt->rchild == NULL)
            printf("rchild of '%c' is null", bt->data);
        preorder(bt->lchild);
        preorder(bt->rchild);
    }
}

void inorder(BinTree bt)
{
    if (bt != NULL)
    {
        inorder(bt->lchild);
        // inorder(NULL);
        visit(bt);
        inorder(bt->rchild);
    }
}

void postorder(BinTree bt) 
{
    if (bt != NULL)
    {
        postorder(bt->lchild);
        postorder(bt->rchild);
        visit(bt);
    }
}

int caculateBinTreeHeight(BinTree bt) 
{
    int lh, rh;
    if (bt == NULL) return 0;
    else 
    {
        lh = caculateBinTreeHeight(bt->lchild);
        rh = caculateBinTreeHeight(bt->rchild);
        return 1 + (lh > rh ? lh : rh);
    }
}

void error() 
{
    printf("There is an error, caller\n");
    // perror("There is an error xxx!");
    exit(1);
}

BinTree CreateTree(DataType pre[], DataType in[], int i, int j, int m, int n, char *str) 
{
    int k;
    BinTree p;
    // if (n < 0 || i > j || m > n) return NULL;
    // if (n < 0 || m > n || i > j ) return NULL;

    if ( n < 0 || m > n ) {
        printf("Starting... m=%d, n=%d str=%s root='%c'\n", m, n, str, pre[i]);
        return NULL;
    }

    p = InitBinTree();
    p->data = pre[i];
    // printf("pre[%d]='%c'\n", i, pre[i]);
    k = m;
    while ( ( k<=n ) && (in[k] != pre[i]) ) k++;
    if ( k > n ) 
    {
        error(); // Cannot find the root node
    }

    printf("a[%d]=%c op='%s' \n", i, pre[i], str);
    // if (k-1 < m) {
    //     p ->lchild = NULL;
    // }else {
    p->lchild = CreateTree(pre, in, i+1, i+k-m, m, k-1, "left");
    // }
    // if (k+1 > n) {
    //     p->rchild = NULL;
    // } else {
    p->rchild = CreateTree(pre, in, i+k-m+1, j, k+1, n, "right");
    // }


    return p;
}

void levelorder(BinTree bt) 
{
    LkQue Q;
    BinTree p;
    InitQueue(&*Q);
    if (bt != NULL){

        EnterQueue(&*Q, bt);
        while (!EmptyQueue(Q))
        {
            p = GetQueueHead(Q);
            OutQueue(&*Q);
            visit(p);
            if (p->lchild != NULL) EnterQueue(&*Q, p->lchild);
            if (p->rchild != NULL) EnterQueue(&*Q, p->rchild);
        }
    }
}

void InitQueue(LkQue q) 
{
    q = (LkQue)malloc(sizeof(LkQue));
    q->front = NULL;
    q->rear = NULL;
}

void EnterQueue(LkQue q, BinTree bt)
{
    if(bt == NULL) return error();

    Link p = (Link)malloc(sizeof(Link));
    p->bt = bt;
    p->next = NULL;

    if ( q->rear != NULL ) q->rear->next = p;
    q->rear = p;

    if ( q->front == NULL ) q->front = p;
}

void OutQueue(LkQue q) 
{
    if (q->front == NULL) return ;
    Link data = q->front;
    q->front = q->front->next;
    free(data);
}

BinTree GetQueueHead(LkQue q) 
{
    return q->front->bt;
}

int EmptyQueue(LkQue q)
{
    return q->front == NULL && q->rear ==NULL;
}

// manually build tree
BinTree CreateTreeForVisit() {
    BinTree p;
    p = (BinTree)malloc(sizeof(BinTree));
    p->data = 'A';
    p->lchild = (BinTree)malloc(sizeof(BinTree));
    p->lchild->data = 'B';
    p->lchild->lchild = (BinTree)malloc(sizeof(BinTree));
    p->lchild->lchild->data = 'D';
    p->lchild->lchild->lchild=NULL;
    p->lchild->lchild->rchild=NULL;
    p->lchild->rchild = (BinTree)malloc(sizeof(BinTree));
    p->lchild->rchild->data = 'E';
    p->lchild->rchild->lchild = (BinTree)malloc(sizeof(BinTree));
    p->lchild->rchild->lchild->data = 'G';
    p->lchild->rchild->lchild->lchild = NULL;
    p->lchild->rchild->lchild->rchild = NULL;
    p->lchild->lchild->rchild = NULL;
    p->rchild = (BinTree)malloc(sizeof(BinTree));
    p->rchild->data = 'C';
    p->rchild->lchild = NULL;
    p->rchild->rchild = (BinTree)malloc(sizeof(BinTree));
    p->rchild->rchild->data = 'F';
    p->rchild->rchild->lchild = NULL;
    p->rchild->rchild->rchild = NULL;
    return p;
}

BinTree InitBinTree() {
    BinTree p;
    p = (BinTree)malloc(sizeof(BinTree));
    p->data = -1;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

BinTree CreateBinTree() {
    BinTree p=NULL;
    BinTree q=NULL;

    p = InitBinTree();
    printf("P size of %lu, BinTree sizeof %lu\n", sizeof(*p), sizeof(BinTree));
    p->data = 'A';
    // p->lchild = (BinTree)malloc(sizeof(BinTree));
    // p->lchild->data = 'B';
    // p->lchild->lchild = NULL;
    // p->lchild->rchild = NULL;
    // p->rchild = NULL;

    p->lchild = InitBinTree();
    p->lchild->data = 'B';

    p->rchild = InitBinTree();
    p->rchild->data = 'C';
    
    // q = InitBinTree();
    // q->data = 'B';

    // p->lchild = q;
    // p->lchild = q;
    // p->rchild = q;
    return p;
}
 
int main(int argc, char const *argv[])
{
    /* code */
    BinTree p, p1;
    DataType pre[] = {'A', 'B', 'D', 'E', 'G', 'C', 'F'};
    DataType in[] = {'D', 'B', 'G', 'E', 'A', 'C', 'F'};
    p = CreateTree(pre, in, 0, 6, 0, 6, "root");
    if (p == NULL) printf("P is NULL, cannot build the tree");
    printf("Hello Preing Order!\n");
    preorder(p);
    // p1 = CreateTreeForVisit();
    // p1 = CreateBinTree();
    // inorder(p1);

    return 0;
}
