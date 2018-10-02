#include<stdio.h>
#include "data.h"
//#include<time.h>
int main()
{
	char ch;
	int n,m,i,p,j;
	fflush(stdin);
	a:
	system("cls");
	//delay(1000);
	ch=intro();

	ch=tolower(ch);
	if(ch==27)
		exit(0);
	if(ch=='n')
	{
		i++;
		registration();
		fflush(stdin);
		goto a;
	}

	if(ch=='e')
	       p=login();
	J:
	j=0;

	do
	{
	switch(p)
	{
		case 1:add();
		p=menu();
		break;
		case 2:balance();
		p=menu();
		break;
		case 3:payments();
		p=menu();
		break;
		case 4:transfer();
		p=menu();
		break;
		case 5:modify();
		p=menu();
		break;
		case 7:goto a;
		default:printf("\nEnter a valid choice...");
		delay(1000);
		p=menu();
	}
	j++;
	if(j==3)
	goto J;
	}while(j<4);
	return 0;
}
