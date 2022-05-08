#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *p;
    node *lc;
    int colour;//black-0 //red -1
    node*rc;
}*root;
void inorder(struct node *r)
{
   if (r != NULL)
   {
      inorder(r->lc);
      cout<<r->data<<"("<<r->colour<<")"<<" ";
      inorder(r->rc);
   }
}
void preorder(struct node *r)
{
   if (r != NULL)
   {
       cout<<r->data<<"("<<r->colour<<")"<<" ";
      preorder(r->lc);
      preorder(r->rc);
   }
}
void postorder(struct node *r)
{
   if (r != NULL)
   {
      postorder(r->lc);
      postorder(r->rc);
      cout<<r->data<<"("<<r->colour<<")"<<" ";
   }
}
void sch(int n)
{
    int p=1;
    node *t=root;
    while(t->data!=n && (t->lc!=NULL || t->rc!=NULL))
    {

        if(n<t->data && t->lc!=NULL)
        {
            t=t->lc;p++;
        }
        else if(n>t->data && t->rc!=NULL)
        {
            t=t->rc;p++;
        }

    }
    if(t->data!=n)
    {
        cout<<"\n element not found!";
        return;
    }
    cout<<"\n the element is at level:"<<p;
}
void min()
{
    node *t=root;
    while(t->lc!=NULL)
    {
        t=t->lc;
    }
    cout<<"\n min element is:"<<t->data;
}
void max()
{
    node *t=root;
    while(t->rc!=NULL)
    {
        t=t->rc;
    }
    cout<<"\n max element is:"<<t->data;
}
void leftrotate(node*x)
{
    node *y;
    y=x->rc;
    x->rc=y->lc;
    if(y->lc!=NULL)
    {
        y->lc->p=x;
    }
    y->p=x->p;
    if(x->p==NULL)
    {
        root=y;
    }
    else if(x==x->p->lc)
    {
        x->p->lc=y;
    }
    else{
        x->p->rc=y;
    }
    y->lc=x;
    x->p=y;
    
}
void rightrotate(node*y)
{
    node *x;
    x=y->lc;
    y->lc=x->rc;
    if(x->rc!=NULL)
    {
        x->rc->p=y;
    }
    x->p=y->p;
    if(y->p==NULL)
    {
        root=x;
    }
    else if(y==y->p->rc)
    {
        y->p->rc=x;
    }
    else{
        y->p->lc=x;
    }
    x->rc=y;
    y->p=x;
    
}
void correct(node *temp)
{
    if(temp==root)
    {
        temp->colour=0;
        return;
    }
    if(temp->colour==temp->p->colour && temp->colour==1 )
    {
        if(temp->p==temp->p->p->lc)
        {
            if(temp->p->p->rc!=NULL && temp->p->p->rc->colour==1)//case 1
            {
                temp->p->colour=0;
                temp->p->p->colour=1;
                temp->p->p->rc->colour=0;
                correct(temp->p->p);
            }
            else
            {
                //case 2 with the temp being the lc
                if(temp==temp->p->lc)
                {
                    //change the colour first
                    temp->p->colour=0;
                    temp->p->p->colour=1;
                    rightrotate(temp->p->p);
                }
                else{
                    leftrotate(temp->p);
                    temp->colour=0;
                    temp->p->colour=1;
                    rightrotate(temp->p);//after the left roration the parent of temp become the initial grandparent
                }
            }
        }
        else
        {
            if(temp->p->p->lc!=NULL && temp->p->p->lc->colour==1)//case 1
            {
                temp->p->colour=0;
                temp->p->p->colour=1;
                temp->p->p->lc->colour=0;
                correct(temp->p->p);
            }
            else
            {
                //case 2 with the children being in the left hand side
                if(temp==temp->p->rc)
                {
                    temp->p->p->colour=1;
                    temp->p->colour=0;
                   leftrotate(temp->p->p);
                }
                else{
                    rightrotate(temp->p);
                    temp->p->colour=1;
                    temp->colour=0;
                    leftrotate(temp->p);//after the right roration the parent of temp become the initial grandparent
                }
            }
        }
    }
}
void insert()
{
    node *temp= new node;
    node *t=root;
    cout<<"\n enter the data:";
    int n;
    cin>>n;
    temp->data=n;
    temp->colour=1;//red as default
    temp->p=NULL;
    temp->rc=NULL;
    temp->lc=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        while(temp->p==NULL)
        {
            if(temp->data<=t->data )
            {
                if(t->lc==NULL)
                {
                    t->lc=temp;
                    temp->p=t;

                }
                else
                {
                    t=t->lc;
                }
            }
            else if(temp->data>t->data )
            {
                if(t->rc==NULL)
                {
                    t->rc=temp;
                    temp->p=t;

                }
                else
                {
                    t=t->rc;
                }
            }
        }
    }
    correct(temp);
}
node* sach()
{
    int n,p=1;
    cout<<"\nenter the key:";
    cin>>n;
    node *t=root;
    while(t->data!=n && (t->lc!=NULL || t->rc!=NULL))
    {

        if(n<t->data && t->lc!=NULL)
        {
            t=t->lc;p++;
        }
        else if(n>t->data && t->rc!=NULL)
        {
            t=t->rc;p++;
        }

    }
    if(t->data!=n)
    {
        cout<<"\n element not found!";
    }
    else{
        return t;
    }
    node *temp=NULL;
    return temp;
}
void predecessor()
{
    node *pp,*i;
    pp=sach();
    if(pp==NULL)
    {
        return;
    }
    else{
        if(pp->lc!=NULL)
        {
            pp=pp->lc;
            while(pp->rc!=NULL)
            {
                pp=pp->rc;
            }
            cout<<"\n predecessor is:"<<pp->data;
        }
        else
        {
            i=pp->p;
            while(i->p!=NULL && pp==i->lc)
            {
                pp=i;
                i=i->p;
            }

           cout<<"\n predecessor is:"<<i->data;
        }
    }
}
void successor()
{
    node *pp,*i;
    pp=sach();
    if(pp==NULL)
    {
        return;
    }
    else{
        if(pp->rc!=NULL)
        {
            pp=pp->rc;
            while(pp->lc!=NULL)
            {
                pp=pp->lc;
            }
            cout<<"\n successor is:"<<pp->data;
        }
        else
        {
            i=pp->p;
            while(i->p!=NULL && pp==i->rc)
            {
                pp=i;
                i=i->p;
            }

           cout<<"\n successor is:"<<i->data;
        }
    }
}
node* succes(node *pp)
{
    node *i,*t=NULL;
    if(pp==NULL)
    {
        return t;
    }
    else{
        if(pp->rc!=NULL)
        {
            pp=pp->rc;
            while(pp->lc!=NULL)
            {
                pp=pp->lc;
            }
            return pp;
        }
        else
        {
            i=pp->p;
            while(i->p!=NULL && pp==i->rc)
            {
                pp=i;
                i=i->p;
            }
            if(i==root)
            {
                cout<<"\n the element is max.! ";
                return t;
            }
           return i;
        }
    }
}
void del()
{
    node *pp,*i,*t;
    pp=sach();
    i=pp->p;
    if(pp->rc==NULL && pp->lc==NULL)
    {
        if(i->rc==pp)
        {
            i->rc=NULL;
        }
        else{
            i->lc=NULL;
        }
    }
    else if(pp->rc==NULL || pp->lc==NULL)
    {
        if(pp->rc==NULL)
        {
            if(i->rc==pp)
            {
                i->rc=pp->lc;
                pp->lc->p=i;
            }
            else if(i->lc==pp)
            {
                i->lc=pp->lc;
                pp->lc->p=i;
            }
        }
        else
        {
            if(i->rc==pp)
            {
                i->rc=pp->rc;
                pp->rc->p=i;
            }
            else if(i->lc==pp)
            {
                i->lc=pp->rc;
                pp->rc->p=i;
            }
        }
    }
    else
    {
        t=succes(pp);
        if(pp->rc==t)
        {
            if(pp==root)
            {
                root=t;
            }
            t->lc=pp->lc;
            if(pp->p!=NULL)
            {
                t->p=pp->p;
                if(pp->p->lc==pp)
                {
                    pp->p->lc=t;
                }
                else{
                    pp->p->rc=t;
                }
            }
        }
        else
        {
            if(t->rc==NULL)
            {
                t->p->lc=NULL;
                t->p=pp->p;
                if(pp->p==NULL)
                {
                    root=t;
                }
                else if(pp->p->rc==pp)
                {
                    pp->p->rc=t;
                }
                else{
                    pp->p->lc=t;
                }
                t->lc=pp->lc;
                t->rc=pp->rc;
                if(pp->rc!=NULL)
                {
                    pp->rc->p=t;
                }
                if(pp->lc!=NULL)
                {
                    pp->lc->p=t;
                }
            }
            else
            {
                t->p->lc=t->rc;
                t->rc->p=t->p;
                t->p=pp->p;
                if(pp->p==NULL)
                {
                    root=t;
                }
                else if(pp->p->rc==pp)
                {
                    pp->p->rc=t;
                }
                else{
                    pp->p->lc=t;
                }
                t->lc=pp->lc;
                t->rc=pp->rc;
                if(pp->rc!=NULL)
                {
                    pp->rc->p=t;
                }
                if(pp->lc!=NULL)
                {
                    pp->lc->p=t;
                }
            }

        }


    }
}
int main()
{
    int n=1;
    while(n<=8)
    {
        cout<<"\n1.SEARCH\tO(h)\n2.PREDECESSOR\tO(h)\n3.SUCCESOR\tO(h)\n4.MINIMUM\tO(h)\n5.MAXIMUM\tO(h)\n6.INSERT\tO(h)\n7.DELETE\tO(h)\n8.DISPLAY\tO(N)\n9.EXIT";
        cout<<"\nENTER YOUR CHOICE:";
        cin>>n;
        switch(n)
        {
            case 1:
                    int n;
                    cout<<"\nenter the key:";
                    cin>>n;
                    sch(n);
                    break;
            case 2:
                    predecessor();
                    break;
            case 3:
                    successor();
                    break;
            case 4:
                    min();
                    break;
            case 5:
                    max();
                    break;
            case 6:
                    cout<<"\nenter the size:";
                    int t;
                    cin>>t;
                    while(t--)
                    {
                        insert();
                    }
                    break;
            case 7:
                    del();
                    break;
            case 8:
                    cout<<"\nPREORDER:";
                    preorder(root);
                    cout<<"\nINORDER:";
                    inorder(root);
                    cout<<"\nPOSTORDER:";
                    postorder(root);
                    break;

        }
    }
    return 0;
}
//12 5 18 2 9 15 19 1 3 13
