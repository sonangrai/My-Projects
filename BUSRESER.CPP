#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>

void login();
void busmenu();
void alpha();
void booking(int);
void customer();
void edit();
void cancel();
void deleterecord();
void print();

struct custinfo
{
	char name[30];
	char address[30];
	char phone[30];
	int seatno[20];
	int seat;
	int price;
}cust;

int y;
void main()
{
	clrscr();
	login();
	busmenu();
	getch();
}

void login()
{
	labellogin:
	char c,un[20], pwd[20];
	int index=0;
	printf("\t\t<<<<<<<< -------- LOGIN -------- >>>>>>>>>\n\n");
	printf("\t\t | \t Enter Username: ");
	scanf("%s",&un);
	printf("\t\t | \t Enter Password: ");
	while((c = getch()) != 13){
		if(index < 0)
		index = 0;
		if(c == 8){
			putch('\b');
			putch(NULL);
			putch('\b');
			index--;
			continue;
		}
		pwd[index++] = c;
		putch('*');
	}
	pwd[index] = '\0';

	printf("\n\t\t-----------------------------------------------");
	if(strcmp(un,"admin")==0 && strcmp(pwd,"admin")==0)
	{
		printf("\n\n");
	    printf("\t\t^_^_^_^_^_^ ACCESS GRANTED ^_^_^_^_^_^_^\n");
	    printf("\n\t\t\t Press any key to enter \n");
	    getch();
	    clrscr();
	    busmenu();

	}
	else
	{
		printf("\n");
		printf("\t\t !!!!!! ACCES DENIED !!!!!! \n");
		printf("\n\n\t\t Wrong username or password. Try again!!!\n\n");
		getch();
		clrscr();
		goto labellogin;
	}

}

void busmenu()
{
	bussel:
	clrscr();
	int choice;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setfillstyle(INTERLEAVE_FILL,RED);
	floodfill(0,0,RED);
	printf("\n\n\t\t****** WELCOME TO ALFA DELUXE ***********\n");
	printf("\n\t\t  Bus route -> Ktm - Pkr");
	printf("\n\t\t [1] VIEW SEATS AVAILABE AND DO BOOKING");
	printf("\n \t\t [2] VIEW PASSENGER");
	printf("\n\t\t [3] EXIT PROGRAM");
	printf("\n\n\n");
	printf("\n\n\t\t/\/\/\/\/\/\/\/ CHOOSE FROM THE MENU \/\/\/\/\/\/\/\/\ ");
	scanf("%d",&choice);
	closegraph();
	switch(choice)
	{
	     case 1:
		alpha();
		break;

	     case 2:
		customer();
		break;

	     case 3:
		exit(0);

	     default:
		printf("Choose from menu:");
		goto bussel;
	}
	getch();
}

void alpha()
{
	alphalabel:
	clrscr();
	int j,num,bookedseats,x=0;
	char ch,c;
	FILE *fp, *f1;
	fp = fopen("bookedseatsno.txt","r");
	while(fscanf(fp,"%d",&bookedseats)!= EOF)
	x = int(bookedseats);
	y=x;
	fclose(fp);
	int gd=DETECT,gm,i;
	initgraph(&gd,&gm,"C://TURBOC3//BGI");

	setbkcolor(GREEN);
	setcolor(WHITE);
	setfillstyle(XHATCH_FILL,WHITE);
	circle(50,50,40);
	floodfill(50,50,WHITE);
	setcolor(WHITE);
	setfillstyle(INTERLEAVE_FILL,WHITE);
	circle(550,50,40);
	floodfill(550,50,WHITE);

	setcolor(RED);

	outtextxy(100,50,"!! PLEASE CHOSE SEAT AND REMEMBER TO FOR BOOKING !!");
	outtextxy(100,30,"THE CIRCLE INDICATES THE SEATS ARE RESERVED");
	char ab[10];
	sprintf(ab,"%d",20-y);
	outtextxy(140,10,ab);
	outtextxy(150,10," No of seats are available");
	f1 = fopen("custinfo.txt","r+");
	while(fscanf(f1,"%s%s%s%d%d",&cust.name,&cust.address,&cust.phone,&cust.seatno,&cust.price) != EOF)
	{
	for(j=0;j<20;j++)
	{
	setcolor(WHITE);
	rectangle(50,400,500,100);
	rectangle(60,200,150,110);
	outtextxy(65,150,"DRIVER");
	rectangle(60,390,150,300);
	outtextxy(65,350,"STAFF");

	fscanf(f1,"%s%s%s%d%d",&cust.name[j],&cust.address[j],&cust.phone[j],&cust.seatno[j],&cust.price);
	rectangle(200,150,250,110);
	outtextxy(225,125,"1");
	if(cust.seatno[j] == 1)
	circle(225,125,16);
	rectangle(200,200,250,160);
	outtextxy(225,175,"2");
	if(cust.seatno[j] == 2)
	circle(225,175,16);
	rectangle(200,340,250,300);
	outtextxy(225,320,"3");
	if(cust.seatno[j] == 3)
	circle(225,320,16);
	rectangle(200,390,250,350);
	outtextxy(225,370,"4");
	if(cust.seatno[j] == 4)
	circle(225,370,16);

	rectangle(260,150,310,110);
	outtextxy(285,125,"5");
	if(cust.seatno[j] == 5)
	circle(285,125,16);

	rectangle(260,200,310,160);
	outtextxy(285,175,"6");
	if(cust.seatno[j] == 6)
	circle(285,175,16);

	rectangle(260,340,310,300);
	outtextxy(285,320,"7");
	if(cust.seatno[j] == 7)
	circle(285,320,16);

	rectangle(260,390,310,350);
	outtextxy(285,370,"8");
	if(cust.seatno[j] == 8)
	circle(285,370,16);

	rectangle(320,150,370,110);
	outtextxy(345,130,"9");
	if(cust.seatno[j] == 9)
	circle(345,130,16);

	rectangle(320,200,370,160);
	outtextxy(345,180,"10");
	if(cust.seatno[j] == 10)
	circle(345,180,16);

	rectangle(320,340,370,300);
	outtextxy(345,320,"11");
	if(cust.seatno[j] == 11)
	circle(345,320,16);

	rectangle(320,390,370,350);
	outtextxy(345,370,"12");
	if(cust.seatno[j] == 12)
	circle(345,370,16);

	rectangle(380,150,430,110);
	outtextxy(405,130,"13");
	if(cust.seatno[j] == 13)
	circle(405,130,16);

	rectangle(380,200,430,160);
	outtextxy(405,180,"14");
	if(cust.seatno[j] == 14)
	circle(405,180,16);

	rectangle(380,340,430,300);
	outtextxy(405,320,"15");
	if(cust.seatno[j] == 15)
	circle(405,320,16);

	rectangle(380,390,430,350);
	outtextxy(405,370,"16");
	if(cust.seatno[j] == 16)
	circle(405,370,16);

	rectangle(440,150,490,110);
	outtextxy(465,130,"17");
	if(cust.seatno[j] == 17)
	circle(465,130,16);

	rectangle(440,200,490,160);
	outtextxy(465,180,"18");
	if(cust.seatno[j] == 18)
	circle(465,180,16);

	rectangle(440,340,490,300);
	outtextxy(465,320,"19");
	if(cust.seatno[j] == 19)
	circle(465,320,16);

	rectangle(440,390,490,350);
	outtextxy(465,370,"20");
	if(cust.seatno[j] == 20)
	circle(465,370,16);
	}
	fclose(f1);
	outtextxy(20,450,"Press any key to continue booking...");
	getch();
	closegraph();
	}
	printf("Enter no. of seats to book:");
	scanf("%d",&num);
	x=x+num;

       if( x!=0 && x<=20-y)
	{
		clrscr();
		fp = fopen("bookedseatsno.txt","w");
		fprintf(fp,"%d",x);
		fclose(fp);
		printf("\t\t\t .:.:.:.:.:.:. press any key .:.:.:.:.:.:.:.\n");
		getch();
		booking(num);

	}
	else
	{
		y=20-y;
		printf("\nMore than %d seats are not available", y);
		printf("\n\n Do you want to continue booking bus ALPHA (y/n):");
		ch = getche();
		if( ch == 'y')
		{
		      goto alphalabel;
		}
		else
		{
		   busmenu();
		}
	}



}

void booking(int num)
{
	clrscr();
	printf("\n Please enter the datas carefully \n");
	FILE *fp;
	int i,dis;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setbkcolor(RED);
	fp = fopen("custinfo.txt","a+");
	for(i=0;i<num;i++)
	{
	printf("\n\nEnter Name:");
	scanf("%s",&cust.name[i]);
	printf("\nEnter Address:");
	scanf("%s",&cust.address[i]);
	printf("\nEnter Phone:");
	scanf("%s",&cust.phone[i]);
	printf("\nEnter Seat No:");
	scanf("%d",&cust.seat);
	printf("\nPrice = %d", 1200);
	printf("\n\nEnter discount amount:");
	scanf("%d",&dis);
	printf("\n THANK YOU \n");
	cust.price = 1200-dis;
	fprintf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cust.name, cust.address, cust.phone, cust.seat,cust.price);
	}
	fclose(fp);
	getch();
	closegraph();
	busmenu();
}

void customer()
{
	clrscr();
	char c;
	int n;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setfillstyle(BKSLASH_FILL,RED);
	floodfill(0,0,RED);
	printf("NAME \t\tADDRESS \tPHONE \t\t\tSEAT \t\tCOST\n");
	printf("-------------------------------------------------------------------------------\n\n");
	FILE *f1;
	f1 = fopen("custinfo.txt","r");

	while(fscanf(f1,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{
	   printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cust.name,cust.address,cust.phone,cust.seat,cust.price);

	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t Arrival time=4pm\n");
	printf("\t\t\t\t\t\t\t Departure time=5pm\n");
	printf("\n\n\n press any key to see file action menu\n");
	getch();
	clrscr();
	printf("\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("\n\t 1> Cancel Booking \n");
	printf("\n\t 2> Edit Customer Info\n");
	printf("\n\t 3> View ticket \n");
	printf("\n\t 4> Goto menu \n");
	printf("\t=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*\n");
	printf("\n\t PLEASE HAVE SELECTION \n");
	scanf("%d",&n);
	closegraph();
	switch (n)
	{
		case 1:
		deleterecord();
		break;

		case 2:
		edit();
		break;

		case 3:
		print();
		break;

		case 4:
		busmenu();
		break;

		default :
		printf("invalid selection\n");
		getch();
		busmenu();
		getch();
		break;
	}
}
void deleterecord()
{       int key,i,j,flag=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setbkcolor(BLUE);
	clrscr();
	FILE *f1,*f2;
	f1=fopen("custinfo.txt","r");
	printf("\n\n\n\t\tEnter seat number to delete seat record: ");
	scanf("%d",&key);
	while(fscanf(f1,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{	if(key==cust.seat)
		{
			flag=1;
			break;
		}
	}
       fclose(f1);
	if(flag==0)
	{
		clrscr();
		setcolor(RED);
		ellipse(300,100,0,360,70,50);
		outtextxy(200,100," The Seat is unavailable");
		outtextxy(200,90,"Please enter valid Seat !!!");
	}
    else
    {
	f1=fopen("custinfo.txt","r");
	f2=fopen("temp.txt","w");
	while(fscanf(f1,"%s%s%s%d%d",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{
		     if(key==cust.seat)
			continue;
		     else
		     {
			fprintf(f2,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cust.name, cust.address, cust.phone, cust.seat,cust.price);

		     }
	}
	printf("\n\n\n\t\t\tTHE BOOKING IS CANCELED");
	fclose(f1);
	fclose(f2);
	remove("custinfo.txt");
	rename("temp.txt","custinfo.txt");
	FILE *fp,*fo;
	int x,a;
	fo=fopen("tempseats.txt","a");
	fp=fopen("bookedseatsno.txt","r");
	fscanf(fp,"%d",&y);
	a=y-1;
	{
		fprintf(fo,"%d",a);
	}
	fclose(fo);
	remove("bookedseatsno.txt");
	rename("tempseats.txt","bookedseatsno.txt");
	getch();
	closegraph();
	busmenu();
      }
}
void edit()
{
	int key,i,j,dis,flag=0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\turboc3\\bgi");
	setbkcolor(GREEN);
	clrscr();
	FILE *f1,*f2;
	f1=fopen("custinfo.txt","r");
	printf("\n\n\n\t\tEnter seat number to modify record: ");
	scanf("%d",&key);
	while(fscanf(f1,"%s%s%s%d%d",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{	if(key==cust.seat)
		{
			flag=1;
			break;
		}
	}
       fclose(f1);
	if(flag==0)
	{          clrscr();
		printf("\n\n\n\t\t\t\tThe Seat is unavailable");
		printf("\n \t\t\tPlease enter valid Seat no");
		getch();
	}
    else
    {
	f1=fopen("custinfo.txt","r");
	f2=fopen("temp.txt","w+");
	while(fscanf(f1,"%s%s%s%d%d",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{
		     if(key==cust.seat)
			continue;
		     else
		     {
			fprintf(f2,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cust.name, cust.address, cust.phone, cust.seat,cust.price);

		     }
	}
	fclose(f1);
	fclose(f2);
	remove("custinfo.txt");
	rename("temp.txt","custinfo.txt");

	printf("\n\n\n\t\t\tONE RECORD DELETED");

	f1=fopen("custinfo.txt","a");

	printf("\n\nNOW ENTER NEW ONE ");
	printf("\n\nEnter Name:");
	scanf("%s",&cust.name);
	printf("\nEnter Address:");
	scanf("%s",&cust.address);
	printf("\nEnter Phone:");
	scanf("%s",&cust.phone);
	printf("\nEnter Seat No:");
	scanf("%d",&cust.seat);
	printf("\nPrice = %d", 1200);
	printf("\n\nEnter discount amount:");
	scanf("%d",&dis);
	printf("\n THANK YOU \n");
	cust.price = 1200-dis;
	fprintf(f1,"%s\t\t%s\t\t%s\t\t%d\t\t%d\n",cust.name, cust.address, cust.phone, cust.seat,cust.price);

	fclose(f1);
	getch();
	closegraph();
	busmenu();
	}
}

void print()
{
	int key,i,j,dis,flag=0;
	clrscr();
	FILE *f1;
	f1=fopen("custinfo.txt","r");
	top:
	printf("\n\n\n\t\tEnter seat number to view record: ");
	scanf("%d",&key);
	while(fscanf(f1,"%s%s%s%d%d",&cust.name,&cust.address,&cust.phone,&cust.seat,&cust.price) != EOF)
	{
		if(key==cust.seat)
		 {      flag=1;
			break;
		 }
	}
	print:
	fclose(f1);
	clrscr();
	if(flag==1)
		 {
			int gd=DETECT,gm;
			initgraph(&gd,&gm,"C:\\turboc3\\bgi");
			setcolor(RED);
			setfillstyle(XHATCH_FILL,RED);
			rectangle(15,250,600,10);
			rectangle(20,245,595,15);
			floodfill(130,425,RED);
			setcolor(BLUE);
			circle(300,50,5);
			circle(350,50,5);
			circle(360,50,5);
			rectangle(280,50,380,15);
			outtextxy(200,40,"ALFA");
			outtextxy(410,40,"DELUXE");
			setcolor(GREEN);
			outtextxy(100,200,"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
			printf("\n\n\n\n\t Name:");
			printf("%s",cust.name);
			printf("\n\t Address:");
			printf("%s",cust.address);
			printf("\n\t Phone:");
			printf("%s",cust.phone);
			printf("\n\t Seat No:");
			printf("%d",cust.seat);
			printf("\n\t Price : %d", 1200);
			outtextxy(250,180," HAVE A SAFE JOURNEY \n");
	}
		else
		     {
			printf("invalid seat no\n");
			getch();
			 goto top;
		     }
	getch();
	closegraph();
	busmenu();
}
