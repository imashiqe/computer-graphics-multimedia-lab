#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
    initwindow(640,480,"DDA algo");
    int X,Y;
    X=getmaxx();
    Y=getmaxy();
    rectangle(0,0,X,Y);
    line(0,Y/2,X,Y/2);
    line(X/2,0,X/2,Y);
    double x1,y1,x2,y2,dx,dy,inc1,inc2,d,m;
    cout<<"Enter 1st point"<<endl;
    cin>>x1>>y1;
    cout<<"Enter 2nd point"<<endl;
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    inc1=2*dy;
    inc2=2*(dy-dx);
    d=inc1-dx;
    m=dy/dx;
    putpixel(X/2+x1,Y/2-y1,WHITE);
    cout<<"m="<<m<<endl;

    if(m<1)
    {
        cout<<"for m<1"<<endl;
        while(x1<=x2)
        {
            if(d<0)
            {
                d=d+inc1;
            }
            else
            {
                d=d+inc2;
                y1=y1+1;
            }
            x1=x1+1;
            int xaxis,yaxis;
            xaxis=X/2+x1;
            yaxis=Y/2-y1;
            putpixel(xaxis,yaxis,WHITE);
            cout<<"x="<<x1<<" y="<<y1<<endl;
        }
    }
    else
    {
        cout<<"for m>1"<<endl;
    }

    while(!kbhit())
    {
        delay(100);
    }
}

