int amt,i=1,b;
char un[30];
int pos=0;

void change_username(char name[])
{
	FILE *fp,*fp1;
	int i=0;
	char user[30];
	system("cls");
	fp=fopen("name1.txt","r");
	fp1=fopen("tempu.txt","w");
	while(fscanf(fp,"%s",user)>0)
	{
		if(i==pos)
			fprintf(fp1,"%s\n",name);
		else
			fprintf(fp1,"%s\n",user);
		i++;
	}
	fclose(fp);
	fclose(fp1);
	fp=fopen("name1.txt","w");
	fp1=fopen("tempu.txt","r");
	while(fscanf(fp1,"%s",user)>0)
	{
		fprintf(fp,"%s\n",user);
	}
	fclose(fp);
	fclose(fp1);
}

void change_password(char passw[])
{
	FILE *fp,*fp1;
	int i=0;
	char pswd[30];
	fp=fopen("password.txt","r");
	fp1=fopen("tempp.txt","w");
	while(fscanf(fp,"%s",pswd)>0)
	{
		if(i==pos)
			fprintf(fp1,"%s\n",passw);
		else
			fprintf(fp1,"%s\n",pswd);
		i++;
	}
	fclose(fp);
	fclose(fp1);

	fp=fopen("password.txt","w");
	fp1=fopen("tempp.txt","r");
	while(fscanf(fp1,"%s",pswd)>0)
	{
		fprintf(fp,"%s\n",pswd);
	}
	fclose(fp);
	fclose(fp1);
	}

char intro()
{
	FILE *fp3;
	char ch,choice;
	fflush(stdin);
	fp3=fopen("intro.txt","r");
	while((ch=getc(fp3))!=EOF)
		printf("%c",ch);
	scanf("%c",&choice);
	fclose(fp3);
	return choice;
}

struct newuser
{
	char name[30];
	char acc[20];
	char ifsc[20];
	char bcode[10];
	char country[20];
	char mob[15];
	char pwd[20];
	char cpwd[20];
	int amt;
}a;

void ini()
{
	FILE *fp;
	int a;
	fp=fopen("Balance.txt","a");
	a=0;
	fprintf(fp,"%d\n",a);
	fclose(fp);
}

void registration()
{
	int n,c;
	FILE *fp2,*fpp,*fpn;
	clrscr();
	ini();
	fpn=fopen("name1.txt","a");
	printf("\nName:");
	scanf("%s",a.name);
	fprintf(fpn,"%s\n",a.name);
	fp2=fopen("user.txt","a");
	printf("\nAccount no.:");
	scanf("%s",a.acc);
	printf("\nIFSC code:");
	scanf("%s",a.ifsc);
	printf("\nBranch code:");
	scanf("%s",a.bcode);
	printf("\nCountry:");
	scanf("%s",a.country);
	printf("\nRegistered mobile no.:");
	scanf("%s",a.mob);
	clrscr();
	fclose(fp2);
	fclose(fpn);
	j:
	fpp=fopen("password.txt","a");
	printf("\nType a password:");
	scanf("%s",a.pwd);
	printf("\nConfirm your password:");
	scanf("%s",a.cpwd);
	if(strcmp(a.pwd,a.cpwd)!=0)
	{
		printf("\nPasswords are not same");
		delay(1000);
		goto j;
	}
	fprintf(fpp,"%s\n",a.pwd);
	clrscr();
	printf("\nREGISTRATION SUCCESSFUL:");
	printf("\nName:%s",a.name);
	i++;
	delay(1000);
	fclose(fpp);

     /*	randomize();
	while(n<=size)
	{
		ch=(char) random(127);
		if(((ch>='a')&&(ch<='z')||(ch>='A')&&(ch<='Z'))||(ch>='0')&&(ch<='9'))
		{
			c[n++]=ch;
		}
	}    */
}

int menu()
{
	char ch;
	int choice;
	FILE *fp4;
	clrscr();
	fp4=fopen("menu.txt","r");
	while((ch=getc(fp4))!=EOF)
		printf("%c",ch);
	printf("\n\n\t\tEnter your choice:");
	scanf("%d",&choice);
	fclose(fp4);
	return choice;
}

int login()
{
	char pass[30],pswd[30],ch,n[20],pass1[30];
	int p,v,u;
	FILE *fp1,*fpn,*fpp;
	A:
	u=0;
	clrscr();
	fflush(stdin);
	printf("\n\n\n\t\tUSERNAME:");
	gets(un);
	if(strcmp(un,"1")==0)
		exit(0);
	fpn=fopen("name1.txt","r");
	fpp=fopen("password.txt","r");
	while(fscanf(fpn,"%s",n)>0)
	{
		if(strcmp(n,un)==0)
		{
			goto i1;
		}
		u++;
	}
	printf("\nIncorrect Username");
	printf("\nEnter the Correct Username again...");
	delay(1500);
	goto A;
	i1:
	printf("\n\t\tPASSWORD:");
	for(i=0;pass[i]!=13;i++)
	{
		pass[i]=getch();
		if(pass[i]==68)
			goto i1;
		if(pass[i]==13)
			break;
		printf("*");
	}
	pass[i]='\0';
	v=0;
	while(fscanf(fpp,"%s",pass1)>0)
	{
		if(strcmp(pass1,pass)==0)
		{
			goto i;
		}
		v++;
	}
	printf("\nIncorrect Password");
	printf("\nEnter the correct password...");
	delay(1500);
	goto A;
	i:
	if(u==v)
	{
		pos=u;
		p=menu();
	}
	else
	{
		printf("\nEnter the same Username and password....");
		delay(1500);
		goto A;
	}
	fclose(fpn);
	fclose(fpp);
	return p;
}

void credit(long int cash)
{
	FILE *fp,*fp1;
	long int money;
	i=0;
	fp=fopen("Balance.txt","r");
	fp1=fopen("temb.txt","w");
	while(fscanf(fp,"%ld",&money)>0)
	{
		if(i==pos)
		{
			money+=cash;
			fprintf(fp1,"%ld\n",money);
		}
		else
			fprintf(fp1,"%ld\n",money);
		i++;
	}
	fclose(fp);
	fclose(fp1);
	fp=fopen("Balance.txt","w");
	fp1=fopen("temb.txt","r");
	while(fscanf(fp1,"%ld",&money)>0)
	{
		fprintf(fp,"%ld\n",money);
	}
	fclose(fp);
	fclose(fp1);
}

void debit(long int cash)
{
	FILE *fp,*fp1;
	long int money;
	i=0;
	fp=fopen("Balance.txt","r");
	fp1=fopen("temb.txt","w");
	while(fscanf(fp,"%ld",&money)>0)
	{
		if(i==pos)
		{
			money-=cash;
			fprintf(fp1,"%ld\n",money);
		}
		else
			fprintf(fp1,"%ld\n",money);
		i++;
	}
	fclose(fp);
	fclose(fp1);
	fp=fopen("Balance.txt","w");
	fp1=fopen("temb.txt","r");
	while(fscanf(fp1,"%ld",&money)>0)
	{
		fprintf(fp,"%ld\n",money);
	}
	fclose(fp);
	fclose(fp1);
}


void add()
{
	int i,cvv[3],fp,a,b;
	char cno[20],c,cardname[30];
	clrscr();
	printf("\n\n\n\n\t\t\tEnter Amount:");
	scanf("%d",&amt);
	clrscr();
	Y:
	printf("\nPress ESC at any time to go back to main menu");
	printf("\n\n\tDEBIT CARD NUMBER:");
	i=0;
	while(i<16)
	{
		c=getch();
		if(c==27)
			goto r;
		printf("%c",c);
		if(i==3||i==7||i==11)
			printf("-");
		i++;
		if(i==16)
			break;
	}
	fflush(stdin);
	printf("\n\nEnter expiration/Valid thru(MM-YY):");
	i=0;
	while(i<5)
	{
		c=getch();
		if(c==27)
			goto r;
		printf("%c",c);
		if(i==0&&c!='1'&&c!='0')
		{
			printf("\n\n\n\n\t\tPlease enter a valid MONTH");
			delay(2000);
			clrscr();
			goto Y;
		}
		if(i==0&&c=='0')
		a=1;
		if(a==1&&i==1&&c=='0')
		{
			printf("\n\n\n\n\t\tPlease enter a valid MONTH");
			delay(2000);
			clrscr();
			goto Y;
		}
		if(i==0&&c=='1')
		b=1;
		if(b==1&&i==1&&c!='0'&&c!='1'&&c!='2')
		{
			printf("\n\n\n\n\t\tPlease enter a valid MONTH");
			delay(2000);
			clrscr();
			goto Y;
		}
		if(i==1)
			printf("-");
		if((i==2)&&(c=='0'||c=='1'))
		{
			printf("\n\n\n\n\t\tPlease enter a valid YEAR");
			delay(2000);
			clrscr();
			goto Y;
		}
		i++;
		if(i==4)
			break;
	}
	printf("\n\nNAME ON CARD:");
	gets(cardname);
	printf("\n\nEnter CVV:");
	for(i=0;i<3;i++)
	{
		cvv[i]=getch();
		printf("*");
	}
	printf("\n\nDo you want to continue with these details??");
	printf("\n\nPress Enter to continue or Esc to reset:");
	c=getch();
	if(c==27)
	{
		clrscr();
		goto Y;
	}
	clrscr();
	textcolor(15);
	cprintf("\n\nVerifing your details with your bank...");
	delay(3000);
	printf("\n\n\t\tVerification successful");
	delay(500);
	printf("\n\t\tRs.%d added to your account",amt);
	delay(2000);
	credit(amt);
	printf("\n\tRedirecting you to the main menu....please wait");
	delay(4000);
	r:

}

char cine()
{
	FILE *fpc;
	char ch,p;
	clrscr();
	fpc=fopen("c1.txt","r");
       //	fflush(stdout);
	while((ch=fgetc(fpc))!=EOF)
		printf("%c",ch);
	fflush(stdin);
	scanf("%c",&p);
	fclose(fpc);
	return p;
}

void balance()
{
	FILE *fp;
	long int money;
	clrscr();
	fp=fopen("Balance.txt","r");
	i=0;
	while(fscanf(fp,"%ld",&money)>0)
	{
		if(i==pos)
		{
			printf("\n\n\n\n\n\n\n\t\t\t\tBalance is:%ld",money);
			getch();
		}
		i++;
	}
	fclose(fp);
}

char cine1()
{
	FILE *fpc1;
	char ch,p1;
	clrscr();
	fpc1=fopen("c2.txt","r");
       //	fflush(stdout);
	while((ch=fgetc(fpc1))!=EOF)
		printf("%c",ch);
	fflush(stdin);
	scanf("%c",&p1);
	fclose(fpc1);
	return p1;
}

char cine2()
{
	FILE *fpc2;
	char ch,p2;
	clrscr();
	fpc2=fopen("c3.txt","r");
       //	fflush(stdout);
	while((ch=fgetc(fpc2))!=EOF)
		printf("%c",ch);
	fflush(stdin);
	scanf("%c",&p2);
	fclose(fpc2);
	return p2;
}


void mobile()
{
	FILE *fpm;
	int choice,a,amt1;
	char ch,num[15],b[15];
	w:
	clrscr();
	fpm=fopen("mobile.txt","r");
	while((ch=getc(fpm))!=EOF)
		 printf("%c",ch);
	printf("\n\n\n\t\tEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:strcpy(b,"Airtel");
		break;
		case 2:strcpy(b,"Aircel");
		break;
		case 3:strcpy(b,"BSNL");
		break;
		case 4:strcpy(b,"Idea");
		break;
		case 5:strcpy(b,"Jio");
		break;
		case 6:strcpy(b,"Reliance");
		break;
		case 7:strcpy(b,"Tata docomo");
		break;
		case 8:strcpy(b,"Vodafone");
		break;
		case 9:goto N;
		default:printf("\nEnter a valid choice...");
		delay(1000);
		goto w;
	}
	A:
	clrscr();
	printf("\n\n\n\t\tEnter your %s number: +91",b);
	scanf("%s",num);
	if(strlen(num)!=10)
	{
		printf("Please enter a valid number\n");
		delay(2000);
		goto A;
	}
	printf("\n\t\tEnter amount to be recharged:");
	scanf("%d",&amt1);
	delay(1000);
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\t\t\tRecharge successful");
	printf("\n\t\t\tRedirecting you to the main menu......");
	delay(2000);
	debit(amt1);
	N:
	fclose(fpm);

}

void stb()
{
	FILE *fps;
	char a[20],ch,sid[20];
	int amnt,choice;
	fps=fopen("stb.txt","r");
	T:
	clrscr();
	while((ch=getc(fps))!=EOF)
		printf("%c",ch);
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:strcpy(a,"Airtel Digital TV");
		break;
		case 2:strcpy(a,"Asianet STB");
		break;
		case 3:strcpy(a,"DEN STB");
		break;
		case 4:strcpy(a,"Dish TV");
		break;
		case 5:strcpy(a,"Reliance Digital TV");
		break;
		case 6:strcpy(a,"Sun Direct");
		break;
		case 7:strcpy(a,"Tata sky");
		break;
		case 8:goto N;
		default: printf("\nEnter a valid choice");
		delay(1000);
		goto T;
	}
	clrscr();
	printf("\nOPERATOR:%s",a);
	printf("\n\nEnter your subscriber ID:");
	scanf("%s",sid);
	printf("\nEnter the amount:");
	scanf("%d",&amnt);
	clrscr();
	printf("\n\n\n\t\tRecharge details sent to your operator office...");
	delay(3000);
	printf("\n\n\t\tRecharge will be done shortly....");
	printf("\n\n\t\tRedirecting you to the main menu....");
	delay(4000);
	debit(amnt);
	N:
	fclose(fps);

}

void broadband()
{
	FILE *fpb;
	char a[20],ch,sid[20];
	int choice,amnt;
	fpb=fopen("bb.txt","r");
	B:
	clrscr();
	while((ch=getc(fpb))!=EOF)
		printf("%c",ch);
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:strcpy(a,"Airtel Broadband");
		break;
		case 2:strcpy(a,"Asianet Broadband");
		break;
		case 3:strcpy(a,"BSNL Broadband");
		break;
		case 4:strcpy(a,"Connect Broadband");
		break;
		case 5:strcpy(a,"DEN Broadband");
		break;
		case 6:strcpy(a,"Hathway Broadband");
		break;
		case 7:goto N;
		default: printf("\n\nEnter a valid choice1");
		delay(1000);
		goto B;
	}
	clrscr();
	printf("\nOPERATOR:%s",a);
	printf("\n\n\nEnter your subscriber ID:");
	scanf("%s",sid);
	printf("\nEnter the amount:");
	scanf("%d",&amnt);
	clrscr();
	printf("\n\n\n\t\tRecharge details sent to your operator office...");
	delay(3000);
	printf("\n\n\t\tRecharge will be done shortly....");
	printf("\n\n\t\tRedirecting you to the main menu....");
	delay(4000);
	debit(amnt);
	N:
	fclose(fpb);

}

void pvr()
{
	FILE *fpv;
	int choice;
	char ch,p,p1,p2;
	clrscr();
	fpv=fopen("pvr.txt","r");
	while((ch=fgetc(fpv))!=EOF)
		printf("%c",ch);
	printf("\n\tEnter your choice:");
	scanf("%d",&choice);
	//delay(1000);
	//clrscr();
	switch(choice)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:Q:
			   system("cls");
		       p=cine();
		       for(; ; )
		       {

		 fflush(stdin);
		 if(p=='n')
		{
		    p=0;
		    p1=cine1();
		    goto L;
		}
		W:
		if(p1=='n')
		{
		    p1=0;
		    p2=cine2();
		    goto L;
		}
		if(p2=='p')
		{
		    p2=0;
		    p1=cine1();
		    goto L;
		}
		if(p1=='p')
		{
		    p1=0;
		    p=cine();
		    goto L;
		}
		if(p=='1'||p=='2'||p=='3')
			goto I;
		if(p1=='4'||p1=='5'||p1=='6'||p1=='7')
			goto I;
		if(p2=='8'||p2=='9'||p2=='10'||p2=='11')
			goto I;
		if(p!='p')
			goto Q;
		if(p2!='n')
		{
			p1='n';
			goto W;
		}
		L:
		delay(1);
		      }
	}
	I:
	system("cls");
	printf("\nHii");
	delay(1000);
	fclose(fpv);
}


void payments()
{
	FILE *fpa;
	int choice,a;
	char ch;
	clrscr();
	fpa=fopen("P_menu.txt","r");
	while((ch=getc(fpa))!=EOF)
		printf("%c",ch);
	printf("\n\n\n\t\tEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:mobile();
		break;
		case 2:stb();
		break;
		case 3:broadband();
		break;
		case 4:pvr();
		break;
		case 5:break;

	}
	fclose(fpa);
}

void transfer()
{
    char ch[4],pin[5],c,acc[20];
    int p=0,amount,cvv[3];
    M:
    system("cls");
    printf("\n\n\n\n\n\n\t\tWelcome to the MONEY transfer portal");
    printf("\n\n\n\t\tPress enter key to continue....");
    getch();
    system("cls");
    printf("\n\t\t\t\tMoney transfer portal");
    printf("\n\n\nEnter the account number:");
    scanf("%s",&acc[i]);
    printf("\n\nEnter the amount to be transferred:");
    scanf("%d",&amount);
    printf("\n\nDo you want to continue with these details??");
    printf("\n\nPress Enter to continue or Esc to reset:");
    c=getch();
    if(c==27)
	goto M;
    else
    {
	system("cls");
	printf("\n\n\tProcessing your Bank details...");
	delay(1000);
	printf("\n\n\tChecking your Account balance...");
	delay(2000);
	printf("\n\n\tChecking your pin and cvv...");
	delay(1000);
	printf("\n\n\tTransferring your Money....");
	delay(2000);
	printf("\n\n\tTransfer SUCCESSFUL!!");
	printf("\n\n\tPress Enter to continue...");
	getch();
	system("cls");
	printf("\n\n\n\n\t\tTHANK YOU FOR USING OUR MONEY");
	printf("\n\t\tTRANSFER PORTAL...HOPE YOU HAVE A GOOD DAY");
	printf("\n\nPress Enter to continue to Main menu...");
	getch();
	debit(amount);
    }
}

void modify()
{
	char ch,newun[30],oldun[30],newpass[30],oldpass[30],cun[30],cpass[30];
	int choice,p;
	G:
	system("cls");
	printf("\n\n\tWhat do you want to modify??");
	printf("\n\n\t1.. Username");
	printf("\n\n\t2.. Password");
	printf("\n\n\t3.. Goto to main menu");
	printf("\n\n\tEnter your Choice:");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
		case 1:printf("\n\nEnter your old User name:");
		scanf("%s",oldun);
		printf("\n\n\nPress enter Your new Username:");
		scanf("%s",newun);
		printf("\n\n\nEnter your new username again:");
		scanf("%s",cun);
		p=0;
		if(strcmp(newun,cun)!=0)
		{
			printf("\nEnter your username correctly...");
			delay(1000);
			goto G;
		}
		break;

		case 2:printf("\n\nEnter your old Password:");
		scanf("%s",oldpass);
		printf("\n\n\nPress enter Your new Password:");
		scanf("%s",newpass);
		printf("\n\n\nEnter your new Password again:");
		scanf("%s",cpass);
		p=1;
		if(strcmp(newpass,cpass)!=0)
		{
			printf("\nEnter your Password correctly...");
			delay(1000);
			goto G;
		}
		break;

		case 3:goto N;

		default:printf("\nEnter a Valid choice...");
		goto G;

	}
	if(p==0)
		change_username(newun);
	if(p==1)
		change_password(newpass);
	system("cls");
	printf("\n\n\n\t\tYour change has been recorded in the bank records....");
	delay(1000);
	printf("\n\n\t\tYour Username/Password will be changed within an hour....");
	delay(2000);
	N:
}

