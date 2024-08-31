#include<bits/stdc++.h>

#define f1(x,y,z) (5-y-z)/2
#define f2(x,y,z) (15-3*x-2*z)/5
#define f3(x,y,z) (8-2*x-y)/4

using namespace std;

int main()
{
float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;

int step=1;
int itr,c=0;
cout<< setprecision(6)<< fixed;

cout<<"Enter total error: ";
cin>>e;

cout<< endl<<"Count\tx\t\ty\t\tz"<< endl;
do
{
x1 = f1(x0,y0,z0);
y1 = f2(x1,y0,z0);
z1 = f3(x1,y1,z0);
cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;

step++;

e1 = fabs(x0-x1);
e2 = fabs(y0-y1);
e3 = fabs(z0-z1);

x0 = x1;
y0 = y1;

z0 = z1;
c++;
}
while(e1>e && e2>e && e3>e);

cout<< endl<<"Solution: x = "<< x0<<", y = "<< y0<<" and z = "<<
z0;
return 0;
}
