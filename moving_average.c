#include <stdio.h>
int sum(int *a,int x)
{
    int s=0;
    for(int j=0;j<x;j++)
        s+=a[j];
    return(s);
}
int main()
{
    int n;
    int a[30];
    printf("Enter window size: ");
    scanf("%d",&n);
    int i=0;
    float avg;
    //printf("Enter:");
    while (1)
    {
        printf("Enter:");
        int no;
        if (i<n)
        {
            scanf("%d",&no);
            a[i]=no;
            i++;
            avg=sum(a,i)/(i*1.0);
            for (int j=i;j<n;j++)
                a[j]=avg;
        }
        else
        {
            scanf("%d",&no);
            for(int j=1;j<n;j++)
                a[j-1]=a[j];
            a[n-1]=no;
            avg=sum(a,n)/n;
        }
        printf("Avg= %f\n",avg);
        printf("Enter 0 to exit:");
        scanf("%d",&no);
        if (no==0)
            break;
    }
return 0;
}
