#include <stdio.h>
int main()
{
    float a,b;
    int c=0;
    while (c<5-1)
    {
        printf("Enter: ");
        scanf("%f",&a);
        if (a==b)
        c++;
        b=a;
    }
    printf("WARNING: Sensor timeout detected");
    return 0;
}