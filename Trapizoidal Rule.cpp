#include<iostream>
#include<math.h>

#define f(x) 1/(1+pow(x,2))
//#define f(x) 1/x

using namespace std;
int main()
{
 float lwr, upr, intgr=0.0, stepSize, k;
 int i, n;
 cout<<"Enter lower limit of intgration: ";
 cin>>lwr;
 cout<<"Enter upper limit of intgration: ";
 cin>>upr;
 cout<<"Enter number of sub intervals: ";
 cin>>n;

 stepSize = (upr - lwr)/n;

 intgr = f(lwr) + f(upr);

 for(i=1; i<= n-1; i++)
 {
  k = lwr + i*stepSize;
  intgr = intgr + 2 * (f(k));
 }

 intgr = intgr * stepSize/2;

 cout<< endl<<"The integrated result is: "<< intgr;

 return 0;
}

