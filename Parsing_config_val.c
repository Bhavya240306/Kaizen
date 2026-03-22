#include <stdio.h>
int main()
{
    char ch[30];
    while (1)
    {
        printf("Enter: ");
        fgets(ch,sizeof(ch),stdin);
        //while((getchar())!='0');
        char c[20];
        int s=0,i=0,t=0,j=0,x=1;
        while(ch[i]!='=')
            {
                c[j]=ch[i];
                j++;
                i++;
                t=1;
            }
        //printf("%d\n",j);  
        i--;  
        while (ch[i]!='\0')    
        {if (ch[i]>='0' && ch[i]<='9')
            {
                s=s*10+(ch[i]-'0');
            }
            i++;
        }
        for(int k=0; k<j; k++)
            printf("%c",c[k]);
        printf("\n");
        printf("%d\n",s);
        printf("Enter 0 to exit: ");
        scanf("%d",&x);
        if (x==0)
            break;
    }
}