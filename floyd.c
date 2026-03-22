#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of rows: ");
    scanf("%d",&n);
    int c=1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            printf("%d ",c);
            c++;
        }
        printf("\n");
    }
    for(int i=n; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            printf("%d ",c);
            c++;
        }
        printf("\n");
    }
}