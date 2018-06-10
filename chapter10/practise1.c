#include <stdio.h>

int isSushu(unsigned);



int main(int argc, char const *argv[])
{
    /* code */
    FILE *fp = fopen("./prime.txt", "w+");
    for (int i=1, j=1; i<=1000; i++){
        if(isSushu(i)) {
            fprintf(fp, "%4d", i);
            
            if(!(j++%10)) {
                fprintf(fp, "\n");
            }
        }
    }
    fclose(fp);

    return 0;
}

int isSushu(unsigned number) 
{
    if (number <=3 ){
        return number;
    }

    unsigned half = number / 2;
    if(!(number % half)) {
        return 0;
    }

    for (int i=3; i<half; i+=2) {
        if(!(number % i)) {
            return 0;
        }
    }

    return 1;
}

