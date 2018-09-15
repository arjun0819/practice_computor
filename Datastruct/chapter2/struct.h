/**
 * data struct
 **/
typedef int DataType;

/**
 * data link
 **/
typedef struct node {
    DataType data;
    struct node *next;
} Node, *LinkList;


