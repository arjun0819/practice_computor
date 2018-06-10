#include <stdio.h>

int l=3, w=4, h=5;
int vs(int l, int w) 
{
    extern int h;
    int v;
    v=l*w*h;

    return v;
}


int main(int argc, char const *argv[])
{
    /* code */

    printf("%d\n", vs(l, w));

    return 0;
}
