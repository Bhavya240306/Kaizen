#include <stdio.h>
#include <math.h>
void arithmetic(int,int,char);
void eve_odd(int);
void prime(int);
void quad(int,int,int);
int num_analysis();
int main()
{
	char ch;
	int t=1;
	while (t)
	{
		int a,b,c,n;
		char o;
		printf("=========================================\n");
		printf("------------------MENU-------------------\n");
		printf("=========================================\n");
		printf(" 1) Basic Arithmetic functions (+,-,*,/)\n");
		printf(" 2) Number Analysis\n");
		printf(" 3) Quadratic\n");
		printf(" 4) Exit\n");
		printf("=========================================\n");
		printf("Enter choice ^_^: ");
		scanf("%c",&ch);
		while((getchar())!='\n');
		switch (ch)
		{
			case '1':
				printf("Enter 2 numbers: ");
				scanf("%d %d",&a,&b);
				while((getchar())!='\n');
				printf("Enter operator: ");
				scanf("%c",&o);
				while((getchar())!='\n');
				arithmetic(a,b,o);
				break;
			case '2':
				num_analysis();
				break;
			case '3':
				printf("ax^2 + bx +c\n");
				printf("Enter a,b,c: \n");
				scanf("%d %d %d",&a,&b,&c);
				while((getchar())!='\n');
				quad(a,b,c);
				break;
			case '4':
				printf("Exiting... -_-");
				t=0;
				break;
			default:
				printf("Invalid Input!! +_+\n");				
		}
	}
}
void arithmetic(int a,int b,char o)
{
	switch (o)
	{
		case '+':
			printf("%f\n",(a+b)*1.0);
			break;
		case '-':
			printf("%f\n",(a-b)*1.0);
			break;
		case '*':
			printf("%f\n",a*b*1.0);
			break;
		case '/':
			if (b==0)
				printf("Div by 0!! o_o\n");
			else
				printf("%f\n",a/(b*1.0));
			break;		
		default:
			printf("Invalid operator!! *_* \n");						
	}
}
int num_analysis()
{
	int n,c;
	printf("----------------\n");
	printf("1) even or odd\n");
	printf("2) prime\n");
	printf("3) exit\n");
	printf("----------------\n");
	printf("Enter choice: ");
	scanf("%d",&c);
	while((getchar())!='\n');
	if (c==1)
	{
		printf("Enter a number: ");
		scanf("%d",&n);
		while((getchar())!='\n');
		eve_odd(n);
	}
	else if (c==2)
	{
		printf("Enter a number: ");
		scanf("%d",&n);
		while((getchar())!='\n');
		prime(n);
	}
	else if (c==3)
	{
		printf("Okayyy ^_^\n");
		return 0;
	}
	num_analysis();
	return 0;	

}
void eve_odd(int n)
{
	if (n%2==0)
		printf("Even\n");
	else
		printf("Odd\n");	
}
void prime(int n)
{
	int temp=0;
	for(int i=2; i<=(int)sqrt(n); i++)
	{
		if(n%i==0)
			temp++;
	}
	if (temp==0)
		printf("Prime\n");
	else
		printf("Not Prime\n");	
}
void quad(int a,int b,int c)
{
	if (a!=0)
	{
		int d = b*b - 4*a*c;
		if (d<0)
		{
			float e,f;
			e=-b/(2*a);
			f=sqrt(-d)/(2*a);
			printf("%f + %fi\n",e,f);
			printf("%f - %fi\n",e,f);
		}
		else
		{
			printf("%f\n",((-b+sqrt(d))/(2*a)));
			printf("%f\n",((-b-sqrt(d))/(2*a)));
		}
	}
	else if(a==0 && b!=0)
	{
		printf("Linear Equation '_'\n");
		printf("x= %f\n",-c/(b*1.0));
	}	
	else if(a==0 && b==0)
	{
		printf("Not an equation -_-\n");
	}	
}