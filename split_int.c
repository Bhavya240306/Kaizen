 #include <stdio.h>
int main()
{
    char s[20];
    printf("Enter a string: ");
    scanf("%s",s);
    int a[20];
    int i=0,d=0,t=0,x=0;
    while (s[i]!='\0')
    {
        if (s[i]==',')
        {
            a[d]=t;
            t=0;
            d++;
            x=i;
        }
        else
            t=t*10+(s[i]-'0');
        i++;    
    }
    if(x!=i-1)
    a[d]=t;
    for(int i=0; i<=d; i++)
    printf("%d\n",a[i]);
}
