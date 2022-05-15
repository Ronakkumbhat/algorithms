#include <bits/stdc++.h> 
using namespace std; 
struct node{
int data; node *next;
}*rear;
void insert()
{
node*temp=new node; int d;
cout<<"\n enter the data:"; cin>>d;
temp->data=d; int a;
cout<<"\n1.insert at the begin\n2.insert at the end\n3.insert at a location\nenter ur choice:"; cin>>a;
if(a==1)
{
if(rear==NULL)
{
temp->next=temp; rear=temp;
}
else{
temp->next=rear->next; rear->next=temp;
}
}
else if(a==2)
{
if(rear==NULL)
{
temp->next=temp; rear=temp;
}
else{
temp->next=rear->next; rear->next=temp; rear=temp;
}
}
else if(a==3)
{
 
int loc;
cout<<"\nenter the location:"; cin>>loc;
node*temp1,*prev; prev=rear;
if(rear==NULL && loc==1)
{
temp->next=temp; rear=temp;
return;
}
else if(rear==NULL && loc!=1)
{
cout<<"\n list is empty"; return;
}
if(rear->next==rear && loc==1)
{
temp->next=rear; rear->next=temp;

return;
}
temp1=rear->next; while(loc>1)
{
prev=temp1; temp1=temp1->next; loc--;

}
if(prev==rear)
{
temp->next=rear->next; rear->next=temp; rear=temp;
}
else{
temp->next=prev->next; prev->next=temp;
}
}
else{
cout<<"\ninvalid"; insert();
}
}
void disp()
 
{
if(rear==NULL)
{
cout<<"\n list is empty"; return;
}
else
{
node*t,*tt; t=tt=rear; t=t->next; while(t!=tt)
{
cout<<t->data<<"->"; t=t->next;
}
cout<<t->data<<"->";
}
}
void nodes()
{
node*t,*tt; t=tt=rear; t=t->next; int a=0; while(t!=tt)
{
a++;
t=t->next;
}
cout<<"\n no. of nodes:"<<a+1;
}
int main()
{
rear=NULL; int a;
char ch='y'; while(ch!='n' || ch!='N')
{
cout<<"\n1.insert n times\n2.no. of nodes\n3.display\nenter ur choice:"; cin>>a;
switch(a)
{

case 2:
nodes();
cout<<"\n do u want to continue:"; cin>>ch;
 
break;

case 3:
disp();
cout<<"\n do u want to continue:"; cin>>ch;
break; case 1:
int n;
cout<<"\n no. of nodes:"; cin>>n;
while(n--)
{
insert();
}
cout<<"\n do u want to continue:"; cin>>ch;
break;
}
}
return 0;
}
