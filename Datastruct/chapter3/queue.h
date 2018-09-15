
typedef int DataType;
typedef struct queue
{
    /* data */
    DataType data;
    struct queue *front, *rear;
};
