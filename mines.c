/* Program for a game like mines */
/* Date: 30 Sep 2003 */
/* Author: Srinivas Nayak, Sujit Mohanty */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdlib.h>
#include"mouse.h"
#define A (x>=100&&x<=230&&y>=100&&y<=130)
#define B (x>=350&&x<=480&&y>=100&&y<=130)
#define C (x>=100&&x<=230&&y>=180&&y<=210)
#define D (x>=350&&x<=480&&y>=180&&y<=210)

int flag=0,a,blast(int x,int y),blastx,blasty,blstrem;
char name[20];
static int mark=0;
//////////////////////////////////////////////////////////////////////////
void main()
{
  int gd=DETECT,gm,x,y,button;
  initgraph(&gd,&gm," ");
  sound(2350);
  outtextxy(250,150,"KHATARNAK ");
  outtextxy(230,185,"PROGRAMED BY");
  outtextxy(200,200,"SUJIT MOHANTY  &  SRINIVAS NAYAK");
  sleep(2); nosound();cleardevice();    outtextxy(250,150,"ENTER UR NAME");
  rectangle(200,200,400,230);gotoxy(28,14);scanf("%s",name); cleardevice();
   setbkcolor(GREEN);
  mouse();
  rectangle(200,200,300,230);
  rectangle(400,200,450,230);
  outtextxy(203,203,"START");outtextxy(403,203,"EXIT");
  while(flag==0)
   {
       getmousepos(&button,&x,&y);
       if(button==1&&x>200&&x<300&&y>200&&y<230){delay(500);mine();}
	if(button==1&&x>400&&x<450&&y>200&&y<230)exit(0);
    }

}
 ////////////////////////////*BARS*///////////////////////////////////////////////
 mine()
 { hidemouseptr();
 cleardevice();   mark=0;

    rectangle(500,50,580,80);  gotoxy(65,5);  printf("%s",name);
  rectangle(500,130,580,150);outtextxy(503,133,"EXIT");
  rectangle(500,200,580,230);

  rectangle(50,100,400,400);

    for(a=150;a<400;a=a+50)
    {
      line(50,a,400,a);
    }
    for(a=100;a<400;a=a+50)
    {
      line(a,100,a,400);
    }
     showmouseptr();
    while(flag==0)
   {
       getmousepos(&button,&x,&y);
	if(button==1&&x>50&&x<400&&y>100&&y<400)
	{
	hidemouseptr();
	blstrem=x%50;
	blastx=x-blstrem+25;
	blstrem=y%50;
	blasty=y-blstrem+25;
	blast(blastx,blasty);
	showmouseptr();
	}
	if(button==1&&x>500&&x<580&&y>130&&y<150)break;
    }
    cleardevice();
     setbkcolor(GREEN);
  mouse();
  rectangle(200,200,300,230);
  rectangle(400,200,500,230);
  outtextxy(203,203,"START");outtextxy(403,203,"EXIT");


  return(0);
  }
////////////////////// *FLOWER*////////////////////
blast(int x,int y)
{
int p,q,r,s,i,luck=0;
randomize();
luck=random(100);
delay(luck);
p=x-25;
q=y-25;
if((luck>10&&luck<20)||(luck>20&&luck<30)||(luck>40&&luck<50)||(luck>70&&luck<80)||(luck>90&&luck<100))
{
for(i=1;i<=160;i++)
{ setcolor(BROWN);
  r=random(49);
  s=random(49);
  line(x,y,p+r+1,q+s+1);
}
sleep(1);
cleardevice();
setcolor(WHITE);
outtextxy(300,200,"GAME OVER");   sleep(3);
main();
}
else
{
for(i=1;i<=160;i++)
{ setcolor(i);
  r=random(49);
  s=random(49);
  line(x,y,p+r+1,q+s+1);
}
setcolor(WHITE);
mark+=100;
gotoxy(65,14);printf("%d",mark);
}
return 0;

}
