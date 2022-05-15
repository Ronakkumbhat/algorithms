#include <bits/stdc++.h> 
#define size 5
using namespace std; 
struct stk
{
int data[size]; int top;
}*p;
void push()
{
if(p->top==size-1)
{
cout<<"\n over flow"; return;
}
cout<<"\nEnter element to push:"; int d;
cin>>d;
if(p->top==-1)
{
p->top=p->top+1; p->data[p->top]=d; return;
}
p->top=p->top+1; p->data[p->top]=d; return;
}
void pop()
{
if(p->top==-1)
{
cout<<"\nunderflow"; return;
}
cout<<"\ndeleted element is:"<<p->data[p->top]; p->top=p->top-1;
}
void disp()
{
if(p->top==-1)
{
cout<<"\nempty"; return;
}
cout<<"\nStack is..."; for(int i=p->top;i>=0;i--)
{
cout<<"\n"<<p->data[i];
}
}
int main()
{
p=new stk; p->top=-1;
 
int a; do
{
cout<<"\n***stack menu***\n1.push\n2.pop\n3.display\n4.exit\nenter ur choice(1-4):"; cin>>a;
switch(a)
{
case 1:
push(); break;
case 2:
pop(); break;
case 3:
disp(); break;

}
}while(a!=4); return 0;
}
