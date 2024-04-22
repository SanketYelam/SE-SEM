#include<iostream>
#include<queue>
#include<string>
using namespace std;
class bst
{
    public:
    int i,j,n,d,kp;
    string k;
    int p[5],q[5];
    string key[5];
    void input();
    void create();
    void display();
    void root();
    int w[5][5];
    int c[5][5];
    int r[5][5];

    int find(int i,int j)
    {
        int k,d;
        int min=3200;
        for(int k=i+1;k<=j;k++)
        {
            if((c[i][k-1]+c[k][j])<min)
            {
                min=c[i][k-1]+c[k][j];
                d=k;
            }
        }
        return d;
    }
};
void bst::input()
{   
    cout<<"How many keys:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter key:";
        cin>>key[i];
    }
    cout<<"\n Successful probability\n";
    for(i=1;i<=n;i++)
    {
        cout<<"Enter prob:";
        cin>>p[i];
    }
    cout<<"\n Unsuccessful probability\n";
    for(i=0;i<=n;i++)
    {
        cout<<"Enter prob:";
        cin>>q[i];
    }
}

void bst::create()
{
    for(int i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
    }
    for(i=0;i<n;i++)
    {   j=i+1;
        w[i][j]=q[j]+p[j]+w[i][j-1];
        c[i][j]=w[i][j];
        r[i][j]=j;
    }

    for(int d=2;d<=n;d++)
    {
        for(int i=0;i<=n-d;i++)
        {
            j=i+d;
            w[i][j]=q[j]+p[j]+w[i][j-1];
            kp=find(i,j);
            c[i][j]=w[i][j]+(c[i][kp-1]+c[kp][j]);
            r[i][j]=kp;
        }
    }
}

void bst::display()
{
    cout<<"\nDispla\n";
    for(int i=0;i<=n;i++)
    {
        cout<<w[i][i]<<endl;
        cout<<c[i][i]<<endl;
        cout<<r[i][i]<<endl;
    }
    for(i=0;i<n;i++)
    {   j=i+1;
        cout<<w[i][j]<<endl;
        cout<<c[i][j]<<endl;
        cout<<r[i][j]<<endl;
    }

    for(int d=2;d<=n;d++)
    {
        for(int i=0;i<=n-d;i++)
        {
            j=i+d;
            cout<<w[i][j]<<endl; 
            cout<<c[i][j]<<endl;
            cout<<r[i][j]<<endl;
        }
    }
}
void bst::root()
{
    cout<<"\n***************\n";
    cout<<"Root:"<<r[0][n];
    cout<<"\n Cost:"<<c[0][n];
    cout<<"\n NODE\tLeft child\tRight child";
    queue<int>q;
    int i,j;
    q.push(0);
    q.push(n);
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        j=q.front();
        q.pop();
        int np=r[i][j];
        cout<<"\n"<<np;
        if(r[i][np-1]!=0)
        {
            cout<<"\t"<<r[i][np-1];
                q.push(i);
                q.push(np-1);
        }
        else
        {
            cout<<"\t-";
        }
        if(r[np][j]!=0)
        {
            cout<<"\t"<<r[np][j];
                q.push(np);
                q.push(j);
        }
        else
        {
            cout<<"\t-";
        }
        
    }
    cout<<"\n";
}
int main()
{
  bst b;
  b.input();
  b.create();
  b.display();
  b.root();
}

