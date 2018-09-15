/**
 * P57 - 4.（2）
 * */
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct node
{
    DataType data;
    struct node *next;
} Node, *LinkList;

// declarete the function
LinkList initLinkList(int n);
int count(LinkList head, DataType x);

int main(int argc, char const *argv[])
{
    /* code */
    LinkList l = initLinkList(14);
    LinkList head = l;
    int c = count(l, 3);

    while(l != NULL && l->next != NULL) {
        printf("%d, ", l->data);
        l = l->next;
    }
    printf("\ncount = %d\n", c);

    return 0;
}

/**
 * Init Link List
 */
LinkList initLinkList(int n)
{
    LinkList linkList, head;
    head = (LinkList) malloc(sizeof(LinkList));
    head->data = random() % 5;

    linkList = head;
    for (int i = 1; i < n; i++)
    {
        linkList->next = (LinkList) malloc(sizeof(LinkList));
        linkList->next->data = random() % 5;

        linkList = linkList->next;
    }
    linkList->next = NULL;

    return head;
}

int count(LinkList head, DataType x)
{
    if (head == NULL)
        return 0;

    int count = 0;
    do
    {
        head->data == x ? ++count : 0;
        head = head->next;
    } while (head->next != NULL);

    return count;
}