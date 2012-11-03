/* Program for a game */
/* Date: 17 Mar 2003 */
/* Author: Srinivas Nayak, Anil Kumar Mohapatra */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
int gd=DETECT,gm,flag,nc1,nc2,nc3,nc4,xc2,yc2,x1,y1,x2,y2,i1,j,k,a,b,maxx=639,score,xc1,yc1,botton,p,a1,b1,a2,b2,r1,c1,r2,c2,z;
char name[10];
clock_t start,end ;
void getmousepos();
union REGS i,o;
void main()
{
//char name[10];
//clock_t start,end ;
clrscr();
gotoxy(35,13);printf("PROGRAMMED BY \n\t\t\t\t\tANIL AND SRINIVAS");sound1();sleep(3);
clrscr();
gotoxy(10,10);printf("YOU HAVE TO PLAY THIS GAME WITHIN 100 SECONDS AND SCORE 30");
sound1();sleep(3);clrscr();
//start: flag=0;nc1=185;nc2=120;nc3=nc4=0;a=1;b=1;score=0;r1=10;r2=12;z=0;
initgraph(&gd,&gm,"");
gotoxy(30,10);printf(" NAME PLEASE ");sound1();gotoxy(35,15); scanf("%s",name);
cleardevice();gotoxy(30,10);printf("HAI MR. %s",name);
gotoxy(3,11);printf("CLICK LEFT BUTTON TO CHOOSE A COIN AND RIGHT BUTTON TO PLACE IT");
gotoxy(3,12);printf("YOU HAVE TO PLACE THE COIN IN ONE BLOCK DIFFERENCE HORIZONTALLY OR VERTICALLY");
sound1();sleep(7);
level1();  getch();
}
level1()
{
start: flag=0;nc1=185;nc2=120;nc3=nc4=0;a=1;b=1;score=0;r1=10;r2=12;z=0;

cleardevice();
setbkcolor(BLUE);x1=85;y1=100;
setcolor(WHITE);
for(a=1;a<=8;a++)
	{
	  i1=x1+80;j=x1+200;
	  if(a==3  || a==4  || a==5  || a==6)
	    {i1=x1;j=x1+280;}
	  line(i1,y1,j,y1);y1=y1+40;
	}

x1=85;y1=100;
for(a=1;a<=8;a++)
	{
	  i1=y1+80;j=y1+200;
	  if(a==3  || a==4  || a==5  || a==6)
	    {i1=y1;j=y1+280;}
	  line(x1,i1,x1,j);x1=x1+40;
	}
x1=105;y1=120;
for(a=0;a<7;a++)
 {
  for(b=0;b<7;b++)
	{
	if(a<2 && b<2 ) continue;if(a>4 && b<2 ) continue;
	if(a<2 && b>4 ) continue;if(a>4 && b>4 ) continue;if(a==3 && b==3)continue;
	circle1(x1+a*40,y1+b*40);
	}
 }
setcolor(BLUE);
circle(225,240,10); setcolor(RED);
rectangle(470,5,550,25);outtextxy(475,11,"RESTART");
rectangle(470,45,550,65);outtextxy(475,51,"QUIT");
rectangle(470,93,550,113);outtextxy(475,91,"  ");
rectangle(470,125,550,145);
gotoxy(60,9 ); printf("%s",name);
rectangle(470,175,550,195);outtextxy(474,180,"SCORE");
start = clock();
setviewport(0,0,639,479,1);
if(initmouse()==0)
	{ closegraph();restorecrtmode();exit(1); }
   restrictmouseptr(0,0,maxx,479);
showmouseptr();sound1();
while(flag==0)
{
	botton=0;
	end=clock();
	if((end-start)/CLK_TCK<=100){circle1(nc1,nc2);}


	if((end-start)/CLK_TCK<=100){
	gotoxy(60,7);printf("%0.2f",(end-start)/CLK_TCK);     }
	if((end-start)/CLK_TCK>=100)
	{gotoxy(10,15);printf(" TIME OVER SO GAME OVER. RESTART AGAIN");gotoxy(60,7);printf("      "); }
	getmousepos(&botton,&x1,&y1);
	//gotoxy(70,20);
	//printf("%d",botton);
	if(botton==1 && x1<550 && y1<25 && x1>470 && y1>5)
	{score=0;nc1=nc2=nc3=nc4=700;goto start;}
	if(botton==1 && x1<550 && y1<65 && x1>470 && y1>45)
	{closegraph();quit();}
	if((end-start)/CLK_TCK<=100){
	if(botton==1){a1=x1;b1=y1;r1=roomno10(a1,b1); }
	if(botton==2)
		{getmousepos(&botton,&x1,&y1);
		    a2=x1;b2=y1;r2=roomno10(a2,b2);c2=color10(x1,y1);

		xc2=xc10(a2,b2);yc2=yc10(a2,b2); xc1=xc10(a1,b1);yc1=yc10(a1,b1);
		if(((((abs(a2-a1)<120&&abs(a2-a1)>40))&&((abs(b2-b1)<40))&&(r1==r2))||(((abs(b2-b1)<120&&abs(b2-b1)>40))&&((abs(a2-a1)<40))&&(r1==r2)))&&((c2==1)||(c2==0))&&(getpixel(xc1,yc1)==RED)&&(getpixel((xc1+xc2)/2,(yc1+yc2)/2)==RED))
		{
	    circle1(xc2,yc2);
	    circle2(xc1,yc1); circle2(((xc1+xc2)/2),((yc1+yc2)/2));score+=1;
	   /* if(score==15) {gotoxy(15,12);printf("CONGRATULATION!!\n\t\tYOU WON THE MATCH");
				sound1();sleep(3);break;}  */
	    gotoxy(67,12);printf("%d",score);nc1=xc2;nc2=yc2;nc3=xc1;nc4=yc1;
	    sound2();
	    if(score==29) {gotoxy(15,5);printf("CONGRATULATION!!\n\t\tYOU WON THE MATCH");
				sound1();sleep(3);
		setcolor(BLUE);setfillstyle(1,BLUE); bar(nc3-19,nc4-19,nc3+19,nc4+19);bar((nc1+nc3)/2-19,(nc2+nc4)/2-19,(nc1+nc3)/2+19,(nc2+nc4)/2+19);
		level2();}
		}
		}
	if(botton==1){setcolor(BLUE);setfillstyle(1,BLUE); bar(nc3-19,nc4-19,nc3+19,nc4+19);bar((nc1+nc3)/2-19,(nc2+nc4)/2-19,(nc1+nc3)/2+19,(nc2+nc4)/2+19);}

}
}/*while end*/   level2();
getch();closegraph();return(0);
}
roomno10(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=1;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=1;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=1;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=1;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=2;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=3; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=3;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=3;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=3;//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=4;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=4;//return(p);}

	return(p);
}

color10(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=getpixel(185,120);//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=getpixel(105,200);// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=getpixel(105,280);// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=getpixel(185,200);//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=getpixel(185,280);//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=getpixel(185,360);//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=getpixel(265,120);//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=getpixel(265,200);//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=getpixel(265,280);//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=getpixel(265,360);//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=getpixel(345,200);//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=getpixel(345,280);//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=getpixel(145,200);//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=getpixel(145,280);//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=getpixel(225,120);//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=getpixel(225,200);//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=getpixel(225,280);//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=getpixel(225,360);//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=getpixel(305,200);//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=getpixel(305,280);//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=getpixel(105,240); //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=getpixel(185,160);//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=getpixel(185,240);//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=getpixel(185,320);//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=getpixel(265,160);//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=getpixel(265,240);//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=getpixel(265,320);//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=getpixel(345,240);//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=getpixel(145,240);//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=getpixel(225,160);//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=getpixel(225,240);//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=getpixel(225,320);//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=getpixel(305,240);//return(p);}

	return(p);
}
xc10(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=185;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=105;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=105;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=185;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=265;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=345;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=345;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=145;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=145;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=225;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=305;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=305;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=105; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=185;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=265;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=345;//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=145;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=225;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=305;//return(p);}

      return(p);
}
yc10(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=200;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=280;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=280;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=280;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=240; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=240;//return(p);}

	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=240;//return(p);}
     return(p);
}

circle1(int c,int d)
{
	setcolor(RED);setfillstyle(1,RED);
	ellipse(c,d,0,360,10,10);fillellipse(c,d,10,10);
	return(0);
}
circle2(int c,int d)
{
	setcolor(BLUE);setfillstyle(1,BLUE);
       ellipse(c,d,0,360,15,15);fillellipse(c,d,15,15);
	return(0);
}

int initmouse()
	{
		i.x.ax=0;int86(0x33,&i,&o);return(o.x.ax);
	}

showmouseptr()
	{
		i.x.ax=1;int86(0x33,&i,&o);return(0);
	}
restrictmouseptr(int x1,int y1,int x2,int y2)
	{
		i.x.ax=7;i.x.cx=x1;i.x.dx=x2;int86(0x33,&i,&o);i.x.ax=8;
		i.x.cx=y1;i.x.dx=y2;int86(0x33,&i,&o);return(0);
	}
void getmousepos(int *botton,int *x,int *y)
	{
		i.x.ax=3;int86(0x33,&i,&o);
		*botton=o.x.bx;*x=o.x.cx;*y=o.x.dx;//return(0);
	}
quit()
{
exit(0);return(0);
}
sound1()
{
sound(1700);delay(150);nosound();
sound(1800);delay(150);nosound();
sound(1750);delay(150);nosound();
sound(1850);delay(150);nosound();
sound(1900);delay(150);nosound();
return(0);
}
sound2()
{
sound(1850);delay(100);
nosound();return(0);
}

level2()
{
start: flag=0;nc1=185;nc2=120;nc3=nc4=0;a=1;b=1;score=0;r1=10;r2=12;z=0;

cleardevice();
setbkcolor(BLUE);x1=85;y1=100;
setcolor(WHITE);
for(a=1;a<=8;a++)
	{
	  i1=x1+80;j=x1+200;
	  if(a==3  || a==4  || a==5  || a==6)
	    {i1=x1;j=x1+280;}
	  line(i1,y1,j,y1);y1=y1+40;
	}

x1=85;y1=100;
 for(a=1;a<=8;a++)
	{
	  i1=x1;j=x1+280;line(i1,y1,j,y1);y1=y1+40;
	}

x1=85;y1=100;
for(a=1;a<=8;a++)
	{
	  i1=y1;j=y1+280;line(x1,i1,x1,j);x1=x1+40;
	}

x1=105;y1=120;
for(a=0;a<7;a++)
 {
  for(b=0;b<7;b++)
	{
	if(a==3 && b==3)continue;circle1(x1+a*40,y1+b*40);
	}
 }

setcolor(BLUE);
circle(225,240,10); setcolor(RED);
rectangle(470,5,550,25);outtextxy(475,11,"RESTART");
rectangle(470,45,550,65);outtextxy(475,51,"QUIT");
rectangle(470,93,550,113);outtextxy(475,91,"  ");
rectangle(470,125,550,145);
gotoxy(60,9 ); printf("%s",name);
rectangle(470,175,550,195);outtextxy(474,180,"SCORE");
start = clock();
setviewport(0,0,639,479,1);
if(initmouse()==0)
	{ closegraph();restorecrtmode();exit(1); }
   restrictmouseptr(0,0,maxx,479);
showmouseptr();sound1();
while(flag==0)
{
	botton=0;
	end=clock();
	if((end-start)/CLK_TCK<=100){circle1(nc1,nc2);}


	if((end-start)/CLK_TCK<=100){
	gotoxy(60,7);printf("%0.2f",(end-start)/CLK_TCK);     }
	if((end-start)/CLK_TCK>=100)
	{gotoxy(10,15);printf(" TIME OVER SO GAME OVER. RESTART AGAIN");gotoxy(60,7);printf("      "); }
	getmousepos(&botton,&x1,&y1);
	//gotoxy(70,20);
	//printf("%d",botton);
	if(botton==1 && x1<550 && y1<25 && x1>470 && y1>5)
	{score=0;nc1=nc2=nc3=nc4=700;goto start;}
	if(botton==1 && x1<550 && y1<65 && x1>470 && y1>45)
	{closegraph();quit();}
	if((end-start)/CLK_TCK<=100){
	if(botton==1){a1=x1;b1=y1;r1=roomno20(a1,b1); }
	if(botton==2)
		{getmousepos(&botton,&x1,&y1);
		    a2=x1;b2=y1;r2=roomno20(a2,b2);c2=color20(x1,y1);

		xc2=xc20(a2,b2);yc2=yc20(a2,b2); xc1=xc20(a1,b1);yc1=yc20(a1,b1);
		if(((((abs(a2-a1)<120&&abs(a2-a1)>40))&&((abs(b2-b1)<40))&&(r1==r2))||(((abs(b2-b1)<120&&abs(b2-b1)>40))&&((abs(a2-a1)<40))&&(r1==r2)))&&((c2==1)||(c2==0))&&(getpixel(xc1,yc1)==RED)&&(getpixel((xc1+xc2)/2,(yc1+yc2)/2)==RED))
		{
	    circle1(xc2,yc2);
	    circle2(xc1,yc1); circle2(((xc1+xc2)/2),((yc1+yc2)/2));score+=1;
	  /*  if(score==15) {gotoxy(15,12);printf("CONGRATULATION!!\n\t\tYOU WON THE MATCH");
				sound1();sleep(3);;}  */
	    gotoxy(67,12);printf("%d",score);nc1=xc2;nc2=yc2;nc3=xc1;nc4=yc1;
	    sound2();
	    if(score==45) {gotoxy(15,5);printf("CONGRATULATION!!\n\t\tYOU WON THE MATCH");
				sound1();sleep(3);
			  setcolor(BLUE);setfillstyle(1,BLUE); bar(nc3-19,nc4-19,nc3+19,nc4+19);bar((nc1+nc3)/2-19,(nc2+nc4)/2-19,(nc1+nc3)/2+19,(nc2+nc4)/2+19);
			  level1();}

	    }
		}
	if(botton==1){setcolor(BLUE);setfillstyle(1,BLUE); bar(nc3-19,nc4-19,nc3+19,nc4+19);bar((nc1+nc3)/2-19,(nc2+nc4)/2-19,(nc1+nc3)/2+19,(nc2+nc4)/2+19);}

}
}/*while end*/
getch();closegraph();return(0);
}

roomno20(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=1;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=1;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=1;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=1;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=1;//return(p);}
	if((x1>85&&x1<125)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>100&&y1<140))p=1;//return(p);}
	if((x1>325&&x1<365)&&(y1>340&&y1<380))p=1;//return(p);}
	if((x1>85&&x1<125)&&(y1>340&&y1<380))p=1;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=2;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=2;//return(p);}
	if((x1>125&&x1<165)&&(y1>100&&y1<140))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>100&&y1<140))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>340&&y1<380))p=2;//return(p);}
	if((x1>125&&x1<165)&&(y1>340&&y1<380))p=2;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=2;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=3; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=3;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=3;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=3;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=3;//return(p);}
	if((x1>85&&x1<125)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>325&&x1<365)&&(y1>140&&y1<180))p=3;//return(p);}
	if((x1>325&&x1<365)&&(y1>300&&y1<340))p=3;//return(p);}
	if((x1>85&&x1<125)&&(y1>300&&y1<340))p=3;//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=4;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=4;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=4;//return(p);}
	if((x1>125&&x1<165)&&(y1>140&&y1<180))p=4;//return(p);}
	if((x1>285&&x1<325)&&(y1>140&&y1<180))p=4;//return(p);}
	if((x1>285&&x1<325)&&(y1>300&&y1<340))p=4;//return(p);}
	if((x1>125&&x1<165)&&(y1>300&&y1<340))p=4;//return(p);}

	return(p);
}

color20(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=getpixel(185,120);//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=getpixel(105,200);// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=getpixel(105,280);// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=getpixel(185,200);//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=getpixel(185,280);//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=getpixel(185,360);//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=getpixel(265,120);//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=getpixel(265,200);//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=getpixel(265,280);//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=getpixel(265,360);//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=getpixel(345,200);//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=getpixel(345,280);//return(p);}
	if((x1>85&&x1<125)&&(y1>100&&y1<140))p=getpixel(105,120);//return(p);}
	if((x1>325&&x1<365)&&(y1>100&&y1<140))p=getpixel(345,120);//return(p);}
	if((x1>325&&x1<365)&&(y1>340&&y1<380))p=getpixel(345,360);//return(p);}
	if((x1>85&&x1<125)&&(y1>340&&y1<380))p=getpixel(105,360);//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=getpixel(145,200);//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=getpixel(145,280);//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=getpixel(225,120);//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=getpixel(225,200);//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=getpixel(225,280);//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=getpixel(225,360);//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=getpixel(305,200);//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=getpixel(305,280);//return(p);}
	if((x1>125&&x1<165)&&(y1>100&&y1<140))p=getpixel(145,120);//return(p);}
	if((x1>285&&x1<325)&&(y1>100&&y1<140))p=getpixel(305,120);//return(p);}
	if((x1>285&&x1<325)&&(y1>340&&y1<380))p=getpixel(305,360);//return(p);}
	if((x1>125&&x1<165)&&(y1>340&&y1<380))p=getpixel(145,360);//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=getpixel(105,240); //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=getpixel(185,160);//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=getpixel(185,240);//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=getpixel(185,320);//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=getpixel(265,160);//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=getpixel(265,240);//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=getpixel(265,320);//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=getpixel(345,240);//return(p);}
	if((x1>85&&x1<125)&&(y1>140&&y1<180))p=getpixel(105,160);//return(p);}
	if((x1>325&&x1<365)&&(y1>140&&y1<180))p=getpixel(345,160);//return(p);}
	if((x1>325&&x1<365)&&(y1>300&&y1<340))p=getpixel(345,320);//return(p);}
	if((x1>85&&x1<125)&&(y1>300&&y1<340))p=getpixel(105,320);//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=getpixel(145,240);//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=getpixel(225,160);//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=getpixel(225,240);//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=getpixel(225,320);//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=getpixel(305,240);//return(p);}
	if((x1>125&&x1<165)&&(y1>140&&y1<180))p=getpixel(145,160);//return(p);}
	if((x1>285&&x1<325)&&(y1>140&&y1<180))p=getpixel(305,160);//return(p);}
	if((x1>285&&x1<325)&&(y1>300&&y1<340))p=getpixel(305,320);//return(p);}
	if((x1>125&&x1<165)&&(y1>300&&y1<340))p=getpixel(145,320);//return(p);}

	return(p);
}
xc20(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=185;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=105;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=105;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=185;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=265;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=345;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=345;//return(p);}
	if((x1>85&&x1<125)&&(y1>100&&y1<140))p=105;//return(p);}
	if((x1>325&&x1<365)&&(y1>100&&y1<140))p=345;//return(p);}
	if((x1>325&&x1<365)&&(y1>340&&y1<380))p=345;//return(p);}
	if((x1>85&&x1<125)&&(y1>340&&y1<380))p=105;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=145;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=145;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=225;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=305;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=305;//return(p);}
	if((x1>125&&x1<165)&&(y1>100&&y1<140))p=145;//return(p);}
	if((x1>285&&x1<325)&&(y1>100&&y1<140))p=305;//return(p);}
	if((x1>285&&x1<325)&&(y1>340&&y1<380))p=305;//return(p);}
	if((x1>125&&x1<165)&&(y1>340&&y1<380))p=145;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=105; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=185;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=185;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=265;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=265;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=345;//return(p);}
	if((x1>85&&x1<125)&&(y1>140&&y1<180))p=105;//return(p);}
	if((x1>325&&x1<365)&&(y1>140&&y1<180))p=345;//return(p);}
	if((x1>325&&x1<365)&&(y1>300&&y1<340))p=345;//return(p);}
	if((x1>85&&x1<125)&&(y1>300&&y1<340))p=105;//return(p);}


	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=145;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=225;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=225;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=305;//return(p);}
	if((x1>125&&x1<165)&&(y1>140&&y1<180))p=145;//return(p);}
	if((x1>285&&x1<325)&&(y1>140&&y1<180))p=305;//return(p);}
	if((x1>285&&x1<325)&&(y1>300&&y1<340))p=305;//return(p);}
	if((x1>125&&x1<165)&&(y1>300&&y1<340))p=145;//return(p);}

      return(p);
}
yc20(int x1,int y1)
{
	if((x1>165&&x1<205)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>85&&x1<125)&&(y1>180&&y1<220))p=200;// return(p);}
	if((x1>85&&x1<125)&&(y1>260&&y1<300))p=280;// return(p);}
	if((x1>165&&x1<205)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>165&&x1<205)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>165&&x1<205)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>245&&x1<285)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>245&&x1<285)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>245&&x1<285)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>245&&x1<285)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>325&&x1<365)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>325&&x1<365)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>85&&x1<125)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>325&&x1<365)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>325&&x1<365)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>85&&x1<125)&&(y1>340&&y1<380))p=360;//return(p);}

	if((x1>125&&x1<165)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>125&&x1<165)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>205&&x1<245)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>205&&x1<245)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>205&&x1<245)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>205&&x1<245)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>285&&x1<325)&&(y1>180&&y1<220))p=200;//return(p);}
	if((x1>285&&x1<325)&&(y1>260&&y1<300))p=280;//return(p);}
	if((x1>125&&x1<165)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>285&&x1<325)&&(y1>100&&y1<140))p=120;//return(p);}
	if((x1>285&&x1<325)&&(y1>340&&y1<380))p=360;//return(p);}
	if((x1>125&&x1<165)&&(y1>340&&y1<380))p=360;//return(p);}

	if((x1>85&&x1<125)&&(y1>220&&y1<260))p=240; //return(p);}
	if((x1>165&&x1<205)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>165&&x1<205)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>165&&x1<205)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>245&&x1<285)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>245&&x1<285)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>245&&x1<285)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>325&&x1<365)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>85&&x1<125)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>325&&x1<365)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>325&&x1<365)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>85&&x1<125)&&(y1>300&&y1<340))p=320;//return(p);}

	if((x1>125&&x1<165)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>205&&x1<245)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>205&&x1<245)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>205&&x1<245)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>285&&x1<325)&&(y1>220&&y1<260))p=240;//return(p);}
	if((x1>125&&x1<165)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>285&&x1<325)&&(y1>140&&y1<180))p=160;//return(p);}
	if((x1>285&&x1<325)&&(y1>300&&y1<340))p=320;//return(p);}
	if((x1>125&&x1<165)&&(y1>300&&y1<340))p=320;//return(p);}
     return(p);
}
