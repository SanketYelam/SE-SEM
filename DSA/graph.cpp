#include<iostream>
#include<string>
using namespace std;
class graph
{
    public:
    int no,k1,k2,p,fuel;
    string name,c1,c2;
    void create();
    void display();
    void check();
    
};
void graph::create()
{
    int i;
    cout<<"How many cities:";
    cin>>no;
    string city[no];
    int carray[no];
    int mat[no][no];
    for(i=0;i<no;i++)
    {
        cout<<"Enter name:";
        cin>>city[i];
    }
    for(i=0;i<no;i++)
{
    for(int j=0;j<no;j++)
    {
      mat[i][j]=0;
    }
}

    cout<<"\n How many pths:";
    cin>>p;
    for(int j=0;j<p;j++)
    {   cout<<"\n Details of path no "<<j+1;
        cout<<"\nEnter city 1:";
        cin>>c1;
        cout<<"Enter city 2:";
        cin>>c2;
        for(int i=0;i<no;i++)
        {
            if(c1==city[i])
            {
                k1=i;
            }
            if(c2==city[i])
            {
                k2=i;
            }
        }
        cout<<"\n Fuel used in litres";
        cin>>fuel;
        mat[k1][k2]=mat[k2][k1]=fuel;

    }

    cout<<"Displaying Matrix:\n";
    cout<<"\t"<<city[0]<<"\t"<<city[1]<<"\t"<<city[2]<<"\t"<<city[3]<<"\n";
    for(int i=0;i<no;i++)
    {   
        cout<<city[i]<<"\t";
        for(int j=0;j<no;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void graph::display()
{
    
}
int main()
{
    graph g;
    g.create();
    g.display();
    
}