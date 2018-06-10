#include <stdio.h>

void swap1(int, int);
void swap2(int *, int *);
void swap3(int *, int *);

void fun(int *x, int *y){
    printf("%d, %d", *x, *y);

    *x = 3;
    *y = 4;
}
int main(int argc, char const *argv[])
{
    /* code */
    int a = 9, b = 12;
    int *p1 = &a, *p2 = &b;

    if( a < b) swap1(a, b);
    printf("%d, %d\n", a, b);

    if( a < b) swap2(p1, p2);
    printf("%d, %d\n", a, b);

    a=9, b=12;
    if( a < b) swap3(&a, &b);
    printf("%d, %d\n", a, b);

    int x=1, y=2;
    fun(&y, &x);
    printf("%d, %d",x, y);

    return 0;
}

void swap1(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void swap2(int *x, int *y)
{
    int temp;
    temp=*x; *x=*y; *y=temp;
}

void swap3(int *x, int *y)
{
    int *temp;
    temp=x; x=y; y=temp;
}


