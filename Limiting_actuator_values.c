#include <stdio.h>
int main()
{
    int n;
    printf("Enter motor command value: ");
    scanf("%d",&n);
    if (n>100)
        n=100;
    else if(n<-100)
        n=-100;
    printf("%d",n);
    return 0;
}