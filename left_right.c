#include <stdio.h>
int main()
{
    int i=0,l=0,r=0;
    while (1)
    {
        char c;
        printf("Enter L(left), R(right): \n");
        scanf("%c",&c);
        while((getchar())!='\n');
        if (c=='l' || c=='L')
        {
            l++;
            r=0;
        }
        if (c=='r' || c=='R')
        {
            r++;
            l=0;
        }
        if (l>=3)
            printf("Repeated command detected: LEFT\n");
        else if(r>=3)
            printf("Repeated command detected: RIGHT\n");
        int t;
        printf("Enter 0 to exit: \n");
        scanf("%d",&t);
        while((getchar())!='\n');
        if (t==0)
            break;
        i++;
    }
    return 0;
}