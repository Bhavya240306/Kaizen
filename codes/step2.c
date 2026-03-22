//clang step2.c -o test2
//./test2 
#include <stdio.h>
int battery=0,dist=0,stop=0,lm=0,rm=0;
char pos='N',mode='N';
void view();
int update(int *, int *, int *, char *, char *, int *, int*);
//void emergency();
void manual_mov(int *, int *, int *, char *, char *, int *, int*);
int sum(int *,int );
float moving_avg();
int autonomous(int *, int *, int *, char *, char *, int *, int*);
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
				view();
				break;
			case '2':
				update(&battery, &dist, &stop, &pos, &mode, &lm, &rm);
				break;
			case '3':
				printf("in 3\n");
				break;
			case '4':
				manual_mov(&battery, &dist, &stop, &pos, &mode, &lm, &rm);
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
void view()
{
	printf("Battery: %d\n",battery);
	printf("Obstacle Distance: %d cm\n",dist);
	
	if (pos=='N')
		printf("Line position: NONE\n");
	else if (pos=='C' || pos=='c')
		printf("Line position: Center\n");
	else if (pos=='R' || pos=='r')
		printf("Line position: Rignt\n");
	else if (pos=='L' || pos=='l')
		printf("Line position: Left\n");
		
	if (mode=='N')
		printf("Mode: NONE\n");
	else if (mode=='M' || mode=='m')
		printf("Mode: Manual\n");
	else if (mode=='A' || mode=='a')
		printf("Mode: Automatic\n");	
		
	if (*s==0)
		printf("Emergency stop: OFF\n");
	else
		printf("Emergency stop: ON\n");
	
	printf("Left motor: %d\n",lm);			
	printf("Right motor: %d\n",rm);			
}
int update()
{
	printf("1)Update Battery\n");
	printf("2)Update Obstacle Distance\n");
	printf("3)Update Line Position\n");
	printf("4)Update Mode\n");
	printf("5)Update left motor\n");
	printf("6)Update right motor\n");
	printf("7)Exit\n");
	char idk;
	printf("Enter your choice: ");
	scanf("%c",&idk);
	while((getchar()!='\n'));
	switch (idk)
	{
		case '1':
			printf("Current Battery: ");
			scanf("%d",&battery);
			while((getchar())!='\n');
			update();
			break;
		case '2':
			printf("Current obstacle distance: ");
			scanf("%d",&dist);
			while((getchar())!='\n');	
			break;
		case '3':
			printf("Current line position (Center(C), Right(R), Left(L)): ");
			{
				char p1;
				scanf("%c",&p1);
				if (p1!='c' && p1!='C' && p1!='r' && p1!='R' && p1!='l' && p1!='L')
						printf("Invalid input, couldn't update :(\n");
				else
						pos=p1;	
			}
			while((getchar())!='\n');
			break;	
		case '4':
			printf("Mode (Manual(M), Automatic(A)): ");
			{
				char m1;
				scanf("%c",&m1);
				if (m1!='m' && m1!='M' && m1!='A' && m1!='a')
					printf("Invalid input, couldn't update :(\n");
				else
					mode=m1;	
			}
			while((getchar())!='\n');
			break;
		case '5':
			printf("Left motor: ");
			scanf("%d",&lm);
			while((getchar())!='\n');
			break;
		case '6':
			printf("Right motor: ");
			scanf("%d",&rm);	
			while((getchar())!='\n');	
			break;
		case '7':	
			printf("Okayyy\n");
			return 0;
		default:
			printf("Invalid choice!!\n");	
	}
	return 0;	
}
void manual_mov(int *b, int *d, int *s, char *p, char *m, int *l, int *r)
{
	if ((*m=='M' || *m=='m') && *s==0 && *d>=20)
	{
		while (1)
		{
			char c[20];
			char c1;
			int s1=0,t=1,t1=0,t2=0;
			printf("Enter command(F B L R S): ");
			fgets(c,sizeof(c),stdin);
			int i=0;
			c1=c[i];
			while(c[i]!=' ')
				i++;
			if ((c1=='s') || (c1=='S'))
			{
				printf("Robot Stopping -_-\n");
				lm=0;
				rm=0;
				mode='n';
				stop=0;
				break;
			}	
			else if ((c1!='F' && c1!='f') && (c1!='B' && c1!='b') && (c1!='L' && c1!='l') && (c1!='R' && c1!='r'))
			{
				printf("Invalid Command :(\n");
				t2=1;
			}
			while(c[i]!='\0' && t2==0)
			{
				if (c[i]>='0' && c[i]<='9')
				{
					s1=s1*10 + (c[i]-'0');
					t1=1;
				}		
				i++;
			}
			if (t1==0 && t2==0)
			{
				printf("Invalid command format. Expected: %c <power>\n",c1);
				t2=1;
			}
			if ((s1<-100 || s1>100) && t2==0)
			{
				printf("Allowed power range -100 to 100\n");
				t2=1;
			}
			//==================================================
			if ((c1=='F' || c1=='f') && t2==0)
			{
				printf("move forward with power %d\n",s1); 
				lm=s1;
				rm=s1;
				break;
			}
			else if ((c1=='B' || c1=='b') && t2==0)
			{
				printf("move backward with power %d\n",s1);
				lm=-s1;
				rm=-s1; 
				break;
			}
			else if ((c1=='L' || c1=='l') && t2==0)
			{
				printf("move left with power %d\n",s1);
				lm=0;
				rm=s1; 
				break;
			}
			else if ((c1=='R' || c1=='r') && t2==0)
			{
				printf("move right with power %d\n",s1);
				lm=s1;
				rm=0;	
				break;
			}
		}
	}
	else if((mode!='M' || mode!='m'))
		printf("Not in manual mode :(\n");
	else if(stop==1)
		printf("Emergency ON :(\n");
	else if(dist<20)
		printf("Obstacle too close :(\n");	
}
int sum(int *a,int x)
{
    int s=0;
    for(int j=0;j<x;j++)
        s+=a[j];
    return(s);
}
float moving_avg()
{
	int n;
    int a[30];
    printf("Enter window size: ");
    scanf("%d",&n);
    while((getchar()!='\n'));
    int i=0,l=0;
    float avg;
    while (1)
    {
        printf("Enter:");
        int no;
        if (i<n)
        {
            scanf("%d",&no);
            a[i]=no;
            i++;
            avg=sum(a,i)/(i*1.0);
            for (int j=i;j<n;j++)
                a[j]=avg;
        }
        else
        {
            scanf("%d",&no);
            for(int j=1;j<n;i++)
                a[j-1]=a[j];
            a[n-1]=no;
            avg=sum(a,n)/n;
        }
        printf("Avg= %f\n",avg);
        printf("Enter 0 to exit:");
        scanf("%d",&no);
        if (no==0)
        	break;     
    }
    return (avg);
    
}
int autonomous(int *b, int *d, int *s, char *p, char *m, int *l, int *r)
{
	int nahi=1;
	if (*s==1)
	{
		printf("Emergency active. Robot stopped -_-");
		*l=0;
		*r=0;
		*m='n';
		*s=0;
		return 0;
	}
	else if(*d<20)
	{
		printf("Obstacle too close. Stopping robot -_-");
		*l=0;
		*r=0;
		*m='n';
		*s=0;
		return 0;
	}

	else if(*b<10)
	{
		printf("Battery level low, Stopping robot -_-");
		*l=0;
		*r=0;
		*m='n';
		*s=0;
		return 0;
	}
	else if(*m!='A' || *m!='a')
	{
		printf("Mode: Manual :(");
		return 0;
	}
	printf("Ready to move in automatic mode ^_^\n ");
	printf("Distance values will be accepted by sensors and will use moving average\n");
	if(moving_avg()>=20)
	{
		if (*p=='C' || *p=='c')
			printf("On Center\n");
		else if (*p=='R' || *p=='r')
			printf("Turning Right to follow line\n");
		else if (*p=='L' || *p=='l')
			printf("Turning Left to follow line\n");
	}
	else
	{
		printf("Sensor distance detection, too close\n");
	}
	return 0;
}

