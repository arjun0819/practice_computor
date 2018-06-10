#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    /* code */
    char w[][10] = {"ABCD", "EFGH", "IJKL", "MNOP"};
    for(int k=0; k<4; k++) {
        printf("%s\n", w[k]);
    }
    return 0;
}
