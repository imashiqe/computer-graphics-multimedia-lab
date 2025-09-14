#include<iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
int main()
{
	initwindow(640,480,"Direct line equation");
	int X=getmaxx();
    int Y=getmaxy();
    rectangle(0,0,X,Y);
    line(0,Y/2,X,Y/2);
    line(X/2,0,X/2,Y);

    double x1,y1,x2,y2;
    cout<<"Enter 1st point"<<endl;
    cin>>x1>>y1;
    cout<<"Enter 2nd point"<<endl;
    cin>>x2>>y2;
    double dx,dy;
    double m,b;
    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;
    b=y1-m*x1;
    cout<<"m="<<m<<endl;
    double y=y1;
    if(m<1)
    {
        cout<<"for m<1"<<endl;
        while(x1<=x2)
        {
            int x_axis,y_axis;
            cout<<"x="<<x1<< " y="<<y<<endl;
            x_axis=X/2+x1;
            y_axis=Y/2-y;
            putpixel(x_axis,y_axis,WHITE);
            x1=x1+1;
            y=m*x1+b;
            y=floor(y+0.5);

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
    return 0;
}