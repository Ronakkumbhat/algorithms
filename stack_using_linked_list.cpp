#include <bits/stdc++.h>
using namespace std; 
struct stacks
{
 int data; stacks*next;
}*top;
void push()
{
cout<<"\nEnter element to push:"; stacks*t=new stacks;
cin>>t->data; if(top==NULL)
{
top=t;
top->next=NULL; return;
}
t->next=top; top=t;
}
void pop()
{
if(top==NULL)
{
cout<<"\nStack is empty!!"; return;
}
cout<<"\ndeleted element is:"<<top->data; stacks*t;
t=top;
top=top->next; free(t);
}
void disp()
{
 
if(top==NULL)
{
cout<<"\nStack is empty!!"; return;
}
cout<<"\nstack is..."; stacks*t=top; while(t!=NULL)
{
cout<<"\n"<<t->data; t=t->next;
}
}
int main()
{
top=NULL; int a;
do
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
