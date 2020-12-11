#include <iostream>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#define bucketSize 512
using namespace std;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void bucketinput(int a,int b)
{
     if(a>bucketSize)
        cout<<"\n\t\tBucket overflow";
     else
     {
         delay(500);
         while(a>b)
         {
             cout<<"\n\t\t"<<b<<" bytes outputted.";
             a-=b;
             delay(500);
         }
         if (a>0)cout<<"\n\t\tLast "<<a<<" bytes sent\t";
         cout<<"\n\t\tBucket output successful";
     }
}
int main()
{
     int op, pktSize;
     cout<<"Enter output rate : ";
     cin>>op;
     for(int i=1;i<=5;i++)
     {
         delay(1000);
         cout<<"\n\nEnter Packet Size : \n ";
         cin>>pktSize;
         cout<<"\nPacket no "<<i<<"\tPacket size = "<<pktSize;
         bucketinput(pktSize,op);
     }
     return 0;
}
