#include <stdio.h>

void sort(int *a, int n);


int main(int argc, char const *argv[])
{
    /* code */
    int a[100], *p;
    int i=0, num=0;
    p=a;
    printf("Enter the number of elements in array:");
    scanf("%d", &num);
    printf("Enter the elements of the array:");
    for(i=0; i<num; i++){
        scanf("%d", p+i);
    }
    sort(p, num);
    printf("The array after sorting is:");
    for(i=0; i<num; i++) 
        printf("%4d", *(p+i));
    printf("\n");

    return 0;
}

/* Bubble sort */
void sort(int *a, int n) 
{
    int i=0, j=0, temp=0;
    for(i=0; i<n-1; i++) {
        for(j=0; j < n-1-i; j++) {
            if(*(a+j) > *(a+j+1)) {
                temp = *(a+j);
                *(a+j) = *(a+j+1);
                *(a+j+1)=temp;
            }
        }
    }
}