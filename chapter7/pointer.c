#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* code */
    int *p, *p2, *p3, i=5000, b=4000;

    p = &b;
    p2 = &i; // will be 
    p3 = &i;

    printf("%d %d %d\n", *(++p), *p2++, *p3);

    char *s="Hello there, this is chepter 7";
    printf("%s\n", s);

    printf("%s\n", s);

    printf("%s\n", "Helloworld"+1);

    char ch[] = {"abc\0def"}, *p1=ch;
    printf("%c %c\n", *p1+4, *p1+2);

    int a1[] = {1, 2}, *p4 = a1;
    printf("%d, %d\n", *p4, *(p4+2));

    char str[] = "Helloworld";
    char *a2 = str, *b2 = str, c2;
    c2 = *a2 + *b2;
    
    int a3[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printf("%d, %d, %d, %d", *a3, **a3, *a3[0], *(*(a3+0)+0));

    return 0;
}
