#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class student 
{
     public:
     int large,i,no,n,right,left,temp;
     int A[10];
     void init(int n)
     {
        for(int i=0;i<n;i++)
        {
            cout<<"Enter element:";
            cin>>A[i];
        }
        heapsort(A,n);
        del(A,n);
        output(A,n);
         
     }
     void heapsort(int A[],int n)
     {
       for(int i=floor((n/2)-1);i>=0;i--)
       {
        heapify(A,n,i);
       }
     }
     void heapify(int A[],int n,int i)
     {
        large=i;
        left=2*i+1;
        right=2*i+2;
        if(left<n && A[left]>A[large])
        {
            large=left;
        }
        if(right<n && A[right]>A[large])
        {
            large=right;
        }
        if(large!=i)
        {
            temp=A[i];
            A[i]=A[large];
            A[large]=temp;
            heapify(A,n,large);

        }
     }
     void del(int A[],int n)
     {  int temp1;
        for(int i=n-1;i>0;i--)
        {
        temp1=A[i];
        A[i]=A[0];
        A[0]=temp1;
        heapify(A,i,0);
        }

     }
     void output(int A[],int n)
     {
        for(int i=0;i<n;i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n Min:"<<A[0]<<"\n Max:"<<A[n-1];
     }
};
int main()
{
    student s;
    int np;
    cout<<"Hoew many element:";
    cin>>np;
    s.init(np);
}