#include <stdio.h>
//void view();
//void update();
//void emergency();

int main()
{
	char ch;
	int ch1=0;
	while (1)
	{
		printf("===============================\n");
		printf("-------------MENU--------------\n");
		printf("===============================\n");
		printf("1)View Robot State\n");
		printf("2)Update sensor/state values\n");
		printf("3)Toggle emergency stop\n");
		printf("4)Manual movement command\n");
		printf("5)Run autonomous decision cycle\n");
		printf("6)Exit\n");
		printf("===============================\n");
		printf("Enter your choice: ");
		scanf("%c",&ch);
		while((getchar()!='\n'));
		switch(ch)
		{
			case '1':
				printf("in 1\n");
				break;
			case '2':
				printf("in 2\n");
				break;
			case '3':
				printf("in 3\n");
				break;
			case '4':
				printf("in 4\n");
				break;
			case '5':
				printf("in 5\n");
				break;
			case '6':
				printf("Exiting...");
				ch1=1;
				break;
			default:
				printf("Invalid Choice\n");						
		}
		if (ch1==1)
			break;
	}
	return 0;
}