#include <stdio.h>
int main()
{
    char s[100];
    int i=0,l=0,r=0;
    while (1)
    {
        char c;
        printf("Enter L(left), R(right): ");
        scanf("%c",&c);
        while((getchar())!='\n');
        s[i]=c;
        int t;
        printf("Enter 0 to exit: ");
        scanf("%d",&t);
        while((getchar())!='\n');
        if (t==0)
            break;
        i++;
    }
    for(int j=0;j<i;j++)
    {
        if (s[j]=='l' || s[j]=='L')
        {
            l++;
            r=0;
        }
        if (s[j]=='r' || s[j]=='R')
        {
            r++;
            l=0;
        }
        if (l>=3)
            printf("Repeated command detected: LEFT\n");
        else if(r>=3)
            printf("Repeated command detected: RIGHT\n");
    }
    return 0;
}
