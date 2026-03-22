#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of rows: ");
    scanf("%d",&n);
    int c=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=i; j++)
        {
            c++;
            printf("%d ",c); 
        }
        printf("\n");
    }
    //printf("%d---\n",c);
    for(int i=n; i>0; i--)
    {
        c-=i;
        for(int j=0; j<i; j++)
        {
            c++;
            printf("%d ",c);
        }
        c-=i;
        printf("\n");
    }
}