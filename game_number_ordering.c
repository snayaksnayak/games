/* Program for a game to order numbers from 1 to 15*/
/* Date: 30 Sep 2003 */
/* Author: Srinivas Nayak */
/* Compile using Turbo C++ */

/* This code is distributed under the GPL License. */
/* For more info check: */
/* http://www.gnu.org/copyleft/gpl.html */


#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include"mouse.h"
#include<conio.h>
#include<time.h>
#include<alloc.h>
int j;
unsigned size;
int random1(),random2() ;
int n[20],nl=0,loopno=1;
int n1[20],nl1=0,loopno1=1;
char c1[2]={'1','\0'},c2[2]={'2','\0'};
char c3[2]={'3','\0'},c4[2]={'4','\0'},c5[2]={'5','\0'};
char c6[2]={'6','\0'},c7[2]={'7','\0'},c8[2]={'8','\0'};
char c9[2]={'9','\0'},c10[3]={'1','0','\0'},c11[3]={'1','1','\0'},c12[3]={'1','2','\0'};
char c13[3]={'1','3','\0'},c14[3]={'1','4','\0'},c15[3]={'1','5','\0'},c16[1]={'\0'};
int flag=0,a,b=0,r,x,y,h,ex,ey,cx,cy;
void far *buf;
void main()
{
  int gd=DETECT,gm,x,y,button,i;
 randomize();
 for(i=0;i<20;i++)
 {n[i]=20;}
 for(i=0;i<20;i++)
 {n1[i]=20;}

  initgraph(&gd,&gm," ");
  sound(2350);
  outtextxy(250,150,"WELCOME TO PUZZLSE ");
  sleep(1); nosound();cleardevice();
   setbkcolor(GREEN);
  mouse();
  rectangle(200,200,300,230);
  rectangle(400,200,450,230);
  outtextxy(203,203,"START");outtextxy(403,203,"EXIT");
  while(flag==0)
   {
       getmousepos(&button,&x,&y);
       if(button==1&&x>200&&x<300&&y>200&&y<230)
       {delay(500);hidemouseptr();number();}
	if(button==1&&x>400&&x<450&&y>200&&y<230)exit(0);
    }

}
 ////////////////////////////*BARS*///////////////////////////////////////////////
 number()
 {  cleardevice();

  rectangle(500,130,580,150);outtextxy(503,133,"EXIT");

  rectangle(200,100,400,300);

    for(a=100;a<300;a=a+50)
    {
      line(200,a,400,a);
    }
    for(a=200;a<400;a=a+50)
    {
      line(a,100,a,300);
    }
    while(b<=15)
    {
     r=random1();r++;
     h=random2();h++;
     switch(h)
     {
       case 1:x=225;y=125;break;
       case 2:x=225;y=175;break;
       case 3:x=225;y=225;break;
       case 4:x=225;y=275;break;
       case 5:x=275;y=125;break;
       case 6:x=275;y=175;break;
       case 7:x=275;y=225;break;
       case 8:x=275;y=275;break;
       case 9:x=325;y=125;break;
       case 10:x=325;y=175;break;
       case 11:x=325;y=225;break;
       case 12:x=325;y=275;break;
       case 13:x=375;y=125;break;
       case 14:x=375;y=175;break;
       case 15:x=375;y=225;break;
       case 16:x=375;y=275;break;
     }
     if(r==16)
     {
       ex=x;ey=y;
     }
     switch(r)
     {
       case 1: outtextxy(x,y,c1); break;
       case 2: outtextxy(x,y,c2);break;
       case 3: outtextxy(x,y,c3);break;
       case 4: outtextxy(x,y,c4);break;
       case 5: outtextxy(x,y,c5);break;
       case 6: outtextxy(x,y,c6);break;
       case 7: outtextxy(x,y,c7);break;
       case 8: outtextxy(x,y,c8);break;
       case 9: outtextxy(x,y,c9);break;
       case 10: outtextxy(x,y,c10);break;
       case 11: outtextxy(x,y,c11);break;
       case 12: outtextxy(x,y,c12);break;
       case 13: outtextxy(x,y,c13);break;
       case 14: outtextxy(x,y,c14);break;
       case 15: outtextxy(x,y,c15);break;
       case 16: outtextxy(x,y,c16);break;
     }
    b++;
     }
      showmouseptr();
   while(flag==0)
   {
       getmousepos(&button,&x,&y);

	if(button==1&&x>500&&x<580&&y>130&&y<150)exit(0);


 /////////////////main logic//////////////
	if(button==1&&((x>ex-75&&x<ex-25&&y<ey+25&&y>ey-25)||(x>ex-25&&x<ex+25&&y<ey-25&&y>ey-75)||(x>ex+25&&x<ex+75&&y>ey-25&&y<ey+25)||(x>ex-25&&x<ex+25&&y>ey+25&&y<ey+75))&&(x>200&&x<400&&y<300&&y>100))
       {  cx=x-(x%50);cy=y-(y%50);
	  size=imagesize(cx+2,cy+2,cx+48,cy+48);
	  buf=malloc(size);
	  hidemouseptr();
	  getimage(cx+2,cy+2,cx+48,cy+48,buf);
	  putimage(ex-23,ey-23,buf,0);
	  free(buf);
	  setfillstyle(SOLID_FILL,GREEN);
	  bar(cx+2,cy+2,cx+48,cy+48);
	  ex=cx+25;ey=cy+25;
	  showmouseptr();
       }
/////////////////

    }


  return(0);
  }

 random1()
 {  int b=1,c,i;

 abc:
 while(b==1)
  {
   c=random(16);
     if(loopno==1)
      {
      n[nl]=c; nl++;loopno++;
      }
     else
     {
   for(i=0;i<=nl;i++)
       {
      if(n[i]==c) goto abc;
	}
   n[nl]=c;nl++;
     }
     break;
  }
  return (n[nl-1]);
 }

random2()
 {  int b=1,c,i;
//  randomize();
abc1:
 while(b==1)
  {
   c=random(16);
     if(loopno1==1)
      {
      n1[nl1]=c; nl1++;loopno1++;
      }
     else
     {
   for(i=0;i<=nl1;i++)
       {
      if(n1[i]==c) goto abc1;
	}
   n1[nl1]=c;nl1++;
     }
     break;
  }
 return (n1[nl1-1]);
 }
