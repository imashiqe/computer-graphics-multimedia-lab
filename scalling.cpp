#include <iostream>
#include<graphics.h>
#include<math.h>
#include<dos.h>
using namespace std;
int X,Y;

void Multiple(float A[][3], float B[][3], float C[][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void Output(float A[][3]){
	line(X/2-A[0][0],Y/2+A[1][0],X/2-A[0][1],Y/2+A[1][1]);
	line(X/2-A[0][0],Y/2+A[1][0],X/2-A[0][2],Y/2+A[1][2]);
	line(X/2-A[0][1],Y/2+A[1][1],X/2-A[0][2],Y/2+A[1][2]);
}
 
 
void scaling(float A[][3]){
    Output(A);
	int sx,sy;
	cout<<"Enter sx and sy:"<<endl;
	cin>>sx>>sy;
	float B[3][3] = {{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    float C[3][3];
    cout<<"Enter tx and ty :"<<endl;
    int tx,ty;
    cin>>tx>>ty;
    float tv[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};
    float t_v[3][3]={{1,0,-tx},{0,1,-ty},{0,0,1}};
    float result[3][3];
    float temp[3][3];
    Multiple(tv,B,C);
    Multiple(C,t_v,result);
    Multiple(result,A,temp);
 
	Output(temp);
}
 
 
int main()
{
	initwindow(640,580,"Transformation");
	setbkcolor(WHITE);
	X=getmaxx();
	Y=getmaxy();
	rectangle(0,0,X,Y);
	line(0,Y/2,X,Y/2);
	line(X/2,0,X/2,Y);
	float A[3][3]= {{30, 75, 150}, {30, 100, 80}, {1, 1, 1}};
 
    scaling(A);
 
 
	while(!kbhit()){
		delay(100);
	}
    return 0;
}