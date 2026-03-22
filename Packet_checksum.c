#include <stdio.h>
int main()
{
    char s[30];
    printf("Enter the packet: ");
    scanf("%s",s);
    int i=0,s1=0,s2=0;
    while(s[i]!='\0')
    {
        if (s[i]==',')
        {
            s2+=s1;
            s1=0;
        }
        else
            s1=s1*10+(s[i]-'0');
        i++;
    }
    if (s1==s2)
        printf("Packet Valid");
    else
        printf("Packet Invalid");
    return 0;
}