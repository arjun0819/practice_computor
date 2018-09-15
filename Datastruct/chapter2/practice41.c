/**
 * 
 * Q: 设线性表存放在数组A[arrsize]的前elenum个分量中，且递增有序。试写一算法，将x插入到线性表的适当位置，以保持线性表的
 * 元素依然是递增有序的，并分析算法的时间复杂度。
 * */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    int arrsize = 100;
    int *a = (int *)malloc(arrsize * sizeof(int));

    for (int i = 0; i < arrsize; i++)
    {
        a[i] = random();
    }

    printf("%d\n", *a + 2);

    free(a);
    return 0;
}

int * sort(int * unsort)
{
    
}
