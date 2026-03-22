#include <stdio.h>
int main()
{
    float a,b;
    char o;
    printf("Enter two numbers: ");
    scanf("%f %f",&a,&b);
    while((getchar())!='\n');
    printf("Operator: ");
    scanf("%c",&o);
    if (o=='+')
        printf("%f",a+b);
    else if (o=='-')
        printf("%f",a-b);
    else if (o=='*')  
        printf("%f",a*b);
    else if (o=='/')
    {
        if(b==0.0)
            printf("Div by zero :(");
        else
            printf("%f",a/b);    
    }
    else
        printf("Invalid Operator");   

}