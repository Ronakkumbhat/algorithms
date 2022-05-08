#include<bits/stdc++.h>
using namespace std;
void heapify(int v[],int i,int n)
{
    int left=1+(2*i);
    int right =2+(2*i);
    int max=i;
    if(v[i]<v[right] && right<n)
    {
        max=right;
    }
    if(left<n && v[max]<v[left])
    {
        max=left;
    }
    if(max!=i)
    {
        int t=v[max];
        v[max]=v[i];
        v[i]=t;
        heapify(v,max,n);
    }
}
void makeheap(int v[],int n)
{
    int m=n/2;
    m--;
    for(int i=m;i>=0;i--)
    {
        heapify(v,i,n);
    }
}
void heapsort(int v[],int n)
{
     makeheap(v,n);
    for(int i=n-1;i>=0;i--)
    {
        int t=v[i];
        v[i]=v[0];
        v[0]=t;
        heapify(v,0,i);
    }   
    cout<<"sorted array:";
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}
void extractmax(int v[],int n)
{
        makeheap(v,n);
        cout<<"\n the max element which is extracted:";
        cout<<v[0];
        v[0]=v[n-1];
        int m=n-1;
        heapify(v,0,m);
}
void returnmax(int v[],int n)
{
    makeheap(v,n);
    cout<<"\nthe max element is:";
    cout<<v[0];
}
void increasekey(int v[],int n)
{
    makeheap(v,n);
    cout<<"\n the position and value of the element:";
    int i,k;
    cin>>i>>k;
    if(v[i-1]>k)
    {
        cout<<"\n Error:the entered value is lesser than the value of the element";
        return ;
    }
    else{
        v[i-1]=k;
        int t,j=i-1;
        while(j>=0 && v[(j-1)/2]<k)
        {
            t=v[j];
            v[j]=v[(j-1)/2];
            v[(j-1)/2]=t;
            j=(j-1)/2;
        }
    }
}
void heapdelete(int v[],int n)
{
    makeheap(v,n);
    cout<<"\n enter the position of  element to be deleted:";
    int i;
    cin>>i;
    cout<<"\n the element that  is deleted is:";
    cout<<v[i-1];
    int j=i-1;
    v[j]=v[n-1];
    heapify(v,j,n-1);
}
void heapinsert(int v[],int n)
{
                    
    cout<<"\nenter the element:";
    int k;
    cin>>k;
    v[n]=k;
    int t,j=n;
        while(j>=0 && v[(j-1)/2]<k)
        {
            t=v[j];
            v[j]=v[(j-1)/2];
            v[(j-1)/2]=t;
            j=(j-1)/2;
        }                  
}
void search(int v[],int n)
{
    makeheap(v,n);
    cout<<"\nenter the element:";
    int m,f=0;;
    cin>>m;
    for(int i=0;i<n;i++)
    {
        if(v[i]==m)
        {
            f=1;
            cout<<"\n the element is at:"<<i+1<<" position";
            break;
        }
    }
    if(f==0)
    {
        cout<<"\n element not found";
    }
}
void disp(int v[],int n)
{
    cout<<"\n the heap is:";
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    int n,size=50;
    cout<<"\n enter the size:";
    cin>>n;
    int v[50];
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    makeheap(v,n);
    disp(v,n);
    // 4 1 3 2 16 9 10 14 8 7 
    int m=0;
    while(m<=8)
    {
        cout<<"\n1.heap sort \n2.extract max \n3.return max \n4.heap increase key \n5.heap deletion \n6.heap insert \n7.searching an element\n8.display\n enter ur choice:";
        cin>>m;
        switch(m)
        {
            case 1:heapsort(v,n);
                    makeheap(v,n);
                    break;
            case 2:extractmax(v,n);
                    n--;
                    cout<<"\n the heap is:";
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i]<<" ";
                    }
                    break;
            case 3:returnmax(v,n);
                    break;
            case 4:increasekey(v,n);
                    cout<<"\n the heap is:";
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i]<<" ";
                    }
                    break;
            case 5:
                    heapdelete(v,n);
                    n--;
                    cout<<"\n the heap is:";
                    for(int i=0;i<n;i++)
                    {
                        cout<<v[i]<<" ";
                    }
                    break;
            case 6:
                     if(n==size)
                    {
                        cout<<"\n heap is full";
                    }
                    else
                    {
                         heapinsert(v,n);
                        n++;
                        for(int i=0;i<n;i++)
                        {
                            cout<<v[i]<<" ";
                        }
                    }
                    break;
            case 7:
                        search(v,n);
                        break;
            case 8:
                        disp(v,n);
                        break;
        }
    }
    return 0;
}
// 4 1 3 2 16 9 10 14 8 7
 