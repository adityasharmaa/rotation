#include<graphics.h>
#include<stdio.h>
#include<math.h>
int main()
{
    int gd=DETECT,gm,xin=1,ang=0,x1,y1,x2,y2,rat=70,ch;
    struct arccoordstype a1,a2;
    initgraph(&gd,&gm,"");
    printf("use UP/DOWN ARROW keys to change orientation");
    while(1)
    {
        setcolor(0);
        arc(0,0,ang,ang+1,100);
        getarccoords(&a1);
        arc(0,0,ang+90,ang+91,100);
        getarccoords(&a2);
        x1=a1.xstart;
        y1=a1.ystart*cos(rat*3.14159265359/180);
        x2=a2.xstart;
        y2=a2.ystart*cos(rat*3.14159265359/180);
        int arr1[10]={320+x1,190+y1,320+x2,190+y2,320-x1,190-y1,320-x2,190-y2,320+x1,190+y1};
        int arr2[10]={320+x1,290+y1,320+x2,290+y2,320-x1,290-y1,320-x2,290-y2,320+x1,290+y1};
        setcolor(15);
        drawpoly(5,arr1);
        drawpoly(5,arr2);
        line(320+x1,190+y1,320+x1,290+y1);
        line(320+x2,190+y2,320+x2,290+y2);
        line(320-x1,190-y1,320-x1,290-y1);
        line(320-x2,190-y2,320-x2,290-y2);
        if(kbhit())
        {
            ch=getch();
            if(ch==72)
            rat+=5;
            if(ch==80)
            rat-=5;
        }
        delay(20);
        cleardevice();
        ang++;
    }
    getch();
    closegraph();
    return 0;
}
