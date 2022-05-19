#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *p;
    node *lc;
    node*rc;
}*root;
void inorder(struct node *r)
{
   if (r != NULL)
   {
      inorder(r->lc);
      cout<<r->data<<" ";
      inorder(r->rc);
   }
}
void preorder(struct node *r)
{
   if (r != NULL)
   {
       cout<<r->data<<" ";
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
      cout<<r->data<<" ";
   }
}
void sch(int n)
{
    int p=1;
    node *t=root;
    if(t==NULL)
    {
        cout<<"\n tree is empty!";
        return;
    }
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
void insert()
{
    node *temp= new node;
    node *t=root;
    cout<<"\n enter the data:";
    int n;
    cin>>n;
    temp->data=n;
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
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    cout<<"\nenter the key:";
                    cin>>n;
                    sch(n);
                    }
                    break;
            case 2:
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    predecessor();
                    }
                    break;
            case 3:
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    successor();
                    }
                    break;
            case 4:
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    min();}
                    break;
            case 5:
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    max();}
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
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    del();}
                    break;
            case 8:
                    if(root==NULL)
                    {
                        cout<<"\n tree is empty!";
                    }
                    else{
                    cout<<"\nPREORDER:";
                    preorder(root);
                    cout<<"\nINORDER:";
                    inorder(root);
                    cout<<"\nPOSTORDER:";
                    postorder(root);}
                    break;

        }
    }
    return 0;
}
//12 5 18 2 9 15 19 1 3 13
