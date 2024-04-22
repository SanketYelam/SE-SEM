#include<iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
struct node
{
    char data;
    node *left;
    node *right;
};
node *nnode,*temp,*c1,*c2;
class post
{
    public:
    node *root;
    char exp[20];
    stack<node*>s1;
    post()
    {
        root=NULL;
    }
    void create();
    void display();
    void del();
};

void post::create()
{
  cout<<"Enter Expression:";
  cin>>exp;
  int i=strlen(exp)-1;
  while(i>=0)
  { 
    char ch=exp[i];
    nnode=new node;
    nnode->data=ch;
    nnode->left=nnode->right=NULL;
    if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
    {
        s1.push(nnode);
    }
    else
    {
        c1=s1.top();
        s1.pop();
        nnode->left=c1;
        if(!s1.empty())
        {
            c2=s1.top();
            s1.pop();
            nnode->right=c2;
        }
        s1.push(nnode);        
    }
    i--;
  }
}

void post::display()
{
    node *current;
    stack<node*>s2;

    while(!s1.empty())
    {
        current=s1.top();
        s1.pop();
        s2.push(current);

        if(current->left!=NULL)
        {
            s1.push(current->left);
        }
        if(current->right!=NULL)
        {
            s1.push(current->right);
        }
    }
    while(!s2.empty())
    {
        current=s2.top();
        cout<<current->data;
        s2.pop();
    }
}

void post::del()
{   node *root;
    root->left=root->right=NULL;
    root=NULL;
    cout<<"\nTreee deleted";
    
}
int main()
{
    post p;
    p.create();
    p.display();
    p.del();
}