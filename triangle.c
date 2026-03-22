#include <stdio.h>
#include <math.h>
int main()
{
    float a,b,c;
    printf("Enter sides of triangle: ");
    scanf("%f %f %f",&a,&b,&c);
    if ((a+b)>c && (b+c)>a && (c+a)>b)
    {
        if(a==b && b==c)
            printf("Equilateral triangle");
        else if (((a==b) && c*100==(int)(a*sqrt(2)*100)) || ((c==b) && a*100==(int)(b*sqrt(2)*100)) || ((a==c) && b*100==(int)(c*sqrt(2)*100)))  
            printf("Isosceles right angled triangle");  
        else if((a==b) || (b==c) || (c==a))
            printf("Isosceles triangle");
        else    printf("Scalene Triangle");        
    }
    else
        printf(":( Sorry, triangle couldn't be formed");
}