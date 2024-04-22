#include<iostream>
using namespace std;
struct node
{
    int number;
    char name[10];
    node *child[5];
};
node *nnode,*temp;
class sahil
{
    public:
    node *root;
    void create();
    void display();
};
void sahil::create()
{
    nnode=new node;
    root=nnode;
    cout<<"Enter Book Name:";
    cin>>nnode->name;

    cout<<"How many chapters:";
    cin>>nnode->number;

    for(int i=0;i<(nnode->number);i++)
    {   
        nnode->child[i]=new node;
        cout<<"\tEnter chapter name:";
        cin>>nnode->child[i]->name;

        cout<<"\tHow many sections:";
        cin>>nnode->child[i]->number;

        for(int j=0;j<(nnode->child[i]->number);j++)
        {   
            nnode->child[i]->child[j]=new node;
            cout<<"\t\tEnter Section name:";
            cin>>nnode->child[i]->child[j]->name;

            cout<<"\t\tHow many Subsections:";
            cin>>nnode->child[i]->child[j]->number;

            for(int k=0;k<(nnode->child[i]->child[j]->number);k++)
            {
                nnode->child[i]->child[j]->child[k]=new node;
                cout<<"\t\t\tEnter subsection:";
                cin>>nnode->child[i]->child[j]->child[k]->name;

                nnode->child[i]->child[j]->child[k]->number=0;
                nnode->child[i]->child[j]->child[k]->child[i]=NULL;
            }
        }

    }
}
void sahil::display()
{
    temp=root;
    cout<<"BOOK:"<<temp->name<<"\n";
    for(int i=0;i<(temp->number);i++)
    {
       cout<<"\tCHAPTER:"<<temp->child[i]->name<<"\n";
       for(int j=0;j<(temp->child[i]->number);j++)
       {
        cout<<"\tSECTOIN:"<<temp->child[i]->child[j]->name<<"\n";
       
            for(int k=0;k<(temp->child[i]->child[j]->number);k++)
            {
                cout<<"\t\tSUBSECTOIN:"<<temp->child[i]->child[j]->child[k]->name<<"\n";
            }
    }
    }
}
int main()
{
    sahil s;
    s.create();
    s.display();
}