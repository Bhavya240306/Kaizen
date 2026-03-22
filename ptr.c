#include <stdio.h>
int main()
{
    int a[]={1,2,3,4,5};
    int *ptr;
    ptr=a;
    for(int i=0;i<5;i++)
    {
        printf("%d, ",*ptr);
        ptr++;
    }
    printf("\n");
    ptr=ptr-(5/2-1);
    printf("Mid= %d",*ptr);
}