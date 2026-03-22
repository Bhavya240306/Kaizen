#include <stdio.h>
int main()
{
    int a[100];
    int i=0;
    while (1)
    {
        int no;
        scanf("%d",&no);
        a[i]=no;
        printf("Enter 0 to stop:");
        scanf("%d",&no);
        if (no==0)
            break;
        i++;
    }
    for (int j=0;j<=i;j++)
    {
        if(a[j]<9)
        printf("Alert triggered at value: %d  at position: %d\n",a[j],(j+1));
    }
    return 0;
}