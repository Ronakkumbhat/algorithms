#include <bits/stdc++.h> 
using namespace std; 
struct node{
int data; node *next;
}*temp,*start,*rear;
void push(int d,int c)	///INSERTION(1,2)
{

if (start==NULL)
{
start=new node; start->data=d; start->next=NULL; rear=start;
}
else
{
if(c==2)
{
temp=new node; temp->data=d; temp->next=start; start=temp;
}
else if(c==1)
{
temp=new node; temp->data=d; temp->next=NULL; rear->next=temp; rear=temp;
}
else if(c==3)
{
int l;
cout<<"\n loc:"; cin>>l; temp=start;
for(int i=0;i<l-2;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
cout<<"\n invalid!!\n";
}
else
{
node *ptr=new node; ptr->data=d;
 
ptr->next=temp->next; temp->next=ptr;
}
}
else if(c==4)
{
int h;
cout<<"\n enter the prev data:"; cin>>h;
temp=start; while(temp!=NULL)
{
if(temp->data==h)
{
break;
}
else{
temp=temp->next;
}
}
if(temp==NULL)
{
cout<<"\n invalid";

}
else{
node *ptr=new node; ptr->data=d;
ptr->next=temp->next; temp->next=ptr;
}

}
}
}
void pop(int c)	////DELETION(3)
{

if (start==NULL)
{
cout<<"\ninvalid!";
}
else if(start->next==NULL)
{
free (start);
cout<<"\n list is now empty\n";
}
else
{
if(c==2)
{
 
node *temp; temp=start; start=start->next; free(temp);
}
else if(c==1)
{
temp=start; node *ptr;
while(temp->next!=NULL)
{
ptr=temp; temp=temp->next;
}
ptr->next=NULL; free (temp);
}
else if(c==3)
{
int l;
cout<<"\n loc:"; cin>>l; temp=start; node *ptr;
for(int i=0;i<l-2;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
cout<<"\n invalid!!\n";
}
else
{
ptr=temp->next;
temp->next=ptr->next; free (ptr);
}

}
else if(c==4)
{
int ds;
cout<<"\n enter the data:"; cin>>ds;
node *temp; int l=0,f=0; temp=start; if(temp==NULL)
{
cout<<"\n invalid\n";
 
}
else{
while(temp!=NULL)
{
l++;
if(temp->data==ds)
{
f=1;
break;
}
temp=temp->next;
}
if(f==0)
{
cout<<"\n data not found\n";
}
else{
temp=start;
node *ptr;
for(int i=0;i<l-2;i++)
{
temp=temp->next;
}
if(temp==NULL)
{
cout<<"\n invalid!!\n";
}
else
{
ptr=temp->next;
temp->next=ptr->next; free (ptr);
}

}
}
}
}
}
void searching()	////SEARCHING(5)
{
int ds;
cout<<"\n enter the data:"; cin>>ds;
node *temp; int l=0,f=0; temp=start; if(temp==NULL)
{
cout<<"\n invalid\n";
}
 
else
{
while(temp!=NULL)
{
l++;
if(temp->data==ds)
{
f=1;
break;
}
temp=temp->next;
}
if(f==0)
{
cout<<"\n data not found\n";
}
else{
cout<<"\n list at location:"<<l;
}
}
}
void reverse()	//////REVERSE(4)
{
node *c,*n,*t; if (start==NULL)
{
cout<<"\nlist is empty\n";

}
else
{
c=start; n=c->next;
c->next=NULL; while(n!=NULL)
{
t=c; c=n;
n=n->next; c->next=t;
}
start=c;
}
}
void middle(node *p)
{
int l=0; if(start==NULL)
{
cout<<"\n invalid!!\n";
}
 
else
{
while(p)
{
p=p->next; l++;
}
l=l/2;
cout<<"\nMIDDLE ELE IN LOCATION:"<<l+1;
p=start; while(l)
{
l--;
p=p->next;
}
cout<<"\nMIDDLE ELE DATA:"<<p->data;

}
}
void disp(node *p)
{
if(start==NULL)
{
cout<<"\n invalid!!\n";
}
else
{
while(p)
{
cout<<p->data; cout<<"->"; p=p->next;
}
}
}
int main()	////MAIN FUNCTION
{
start=rear=NULL; int da;
char ch='y'; while(ch!='n' || ch!='N')
{
int s;
cout<<"\n1.insertion\n2.deletion\n3.searching\n4.reverse\n5.middle element\n6.display\nenter your choice:";
cin>>s; switch(s)
{
case 1:
cout<<"data:"; cin>>da;
 
int m;
cout<<"\n1.end \n2.begin \n3.location \n4.data \nenter ur choice:"; cin>>m;
push(da,m);
cout<<"\ndo u want to continue?:"; cin>>ch;
break; case 2:
int bb;
cout<<"\n1.end \n2.begin \n3.location \n4.data\nenter ur choice:"; cin>>bb;
pop(bb);
cout<<"\ndo u want to continue?:"; cin>>ch;
break; case 3:
searching();
cout<<"\ndo u want to continue?:"; cin>>ch;
break;

case 4:
reverse();
cout<<"\ndo u want to continue?:"; cin>>ch;
break; case 5:
middle(start);
cout<<"\ndo u want to continue?:"; cin>>ch;
break;

case 6: disp(start);
cout<<"\ndo u want to continue?:"; cin>>ch;
break;
}
}
disp(start); return 0;
}
