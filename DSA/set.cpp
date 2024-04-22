#include<iostream>

using namespace std;
template<typename T>
class set
{
    public:
    int n,m;
    T A[10];
    T B[10];
    T U[20];
    T key;
    void create();
    void display();
    void contain();
    void union1();
    void inter();
    void diff();
    void removee();
};
template<typename T>
void set<T>::create()
{
    cout<<"\n How many ele in set A:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter ele:";
        cin>>A[i];
    }

    cout<<"\n How many ele in set B:";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cout<<"Enter ele:";
        cin>>B[i];
    }

}
template<class T>
void set<T>::display()
{   
    cout<<"\n A={";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<"}\nB={";
    for(int i=0;i<m;i++)
    {
        cout<<B[i]<<" ";
    }
    cout<<"}";
}
template<class T>
void set<T>::contain()
{   int flag=0;
    cout<<"\n Enter key to search:";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(key==A[i])
        {
            flag=1;
            cout<<"Key found";
        }
    }
    if (flag==0)
    {
        cout<<"\n Not found";
    }
    flag=0;
    for(int i=0;i<m;i++)
    {
        if(key==B[i])
        {
            flag=1;
            cout<<"Key found";
        }
    }
    if (flag==0)
    {
        cout<<"\n Not found";
    }
}
template<class T>
void set<T>::inter()
{  cout<<"intersection";
    cout<<"\n AB={";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i]==B[j])
              {
               cout<<A[i]<<",";
              
              }
              
        }
    }
  
    cout<<"}";
}

template<class T>
void set<T>::diff()
{
    int i;
    int j;
    cout<<"Diff={";
    for(i=0;i<n;i++)
    {   int flag =0;
        for(j=0;j<m;j++)
        {
            if(A[i]==B[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<A[i]<<",";
        }
    }
    cout<<"}";
}

int main()
{
    set<int> s;
    s.create();
    s.display();
    s.contain();
    s.inter();
    s.diff();
}