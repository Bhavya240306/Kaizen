#include <stdio.h>
int len(char *s)
{
    int c=0;
    while (s[c]!='\0')
        c++;
    return c;    
}
int main()
{
    char s[20];
    char ch;
   
    printf("Enter a string: ");
    scanf("%s",s);
    while((getchar())!='\n');
    printf("Enter char to split with: ");
    scanf("%c",&ch);
    char s1[20][20];
    int c=0,d=0;
    int l=len(s);
    while(c<l)
    {
        int i=0;
        while (c<l)
        {
            if (s[c]==ch)
            {
                c++;
                d++;
                break;
            }
            else
            {
                s1[d][i]=s[c];
                i++;
            }
            c++;
        }

    }
    for(int i=0; i<=d; i++)
        printf("%s\n",s1[i]);
    
}
