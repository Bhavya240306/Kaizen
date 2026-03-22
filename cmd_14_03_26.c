#include <stdio.h>
int power(int a)
{
    int b=1;
    for(int i=0;i<a;i++)
        b=b*10;
    return b;    
}
int main()
{
    char s[40];
    printf("Enter command: ");
    scanf("%s",s);
    char m[10];
    int r=0;
    float w[]={0,0,0,0};
    int i=0,sn=1,c=0,k=0,x=0;
    while (s[i]!='\0')
    {
        if (s[i]==':')
        {
            int j=0;
            i++;
            while(s[i]!=',')
            {
                m[j]=s[i];
                j++;
                i++;
            }
            x=j;
        }
        if (c==1)
        {
            //printf("R");
            while (s[i]!=',')
            {
                if (s[i]=='-')
                sn=-sn;
                else if ((s[i]>='0') && (s[i]<='9'))
                r=r*10+(s[i]-'0');
                i++;
            }
            r=r*sn;
            sn=1;
        }
        if (c>1)
        {
            //printf("SPEED");
            int d=0, count=0;
            sn=1;
            while((s[i]!=',') && (s[i]!='\0'))
            {
                if (s[i]=='-')
                    sn=-sn;
                if (s[i]=='.')
                    d=1;
                if ((s[i]>='0') && (s[i]<='9'))
                {
                    w[k]=w[k]*10+(s[i]-'0');
                    if (d==1)
                        count++;
                }
                i++;
            }
            w[k]=sn*w[k]/power(count);
            k++;
        }
        if (s[i]==',')
            c++;
        i++; 
        //printf("%c -",s[i]);
        //printf("%d",c);   
    }
    printf("mode= ");
    for(int i=0;i<x;i++)
    printf("%c",m[i]);
    printf("\n");
    printf("range= %d\n",r);
    printf("Wheel speeds:\n");
    for(int i=0;i<4;i++)
        printf("%f\n",w[i]);
}
