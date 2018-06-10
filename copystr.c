#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */
    char s[12];
    char str[] = {"12345678901"};
    strcpy(s, str);

    printf("%s\n", s);

    char s1[10] = {"Internet"}, str2[] = {"net"};
    strcpy(s1, str2);
    printf("%s\n", s1);

    int a[4][5], a1[][4]={0,1,2,3}, a2[10][10]={0}, a3[4][5] = {{0}, {1,2}, {3,4}, {5,6,7}};

    int b[][4] = {1, 2,3,4,5,6,7};
    printf("a[1][3]=%d\n", b[1][3]);
    return 0;
}
