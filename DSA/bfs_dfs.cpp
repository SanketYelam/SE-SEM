#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
struct node
{
    string area;
    node* next;
};
node *nnode,*temp,*data;
node *head[10];
class sahil
{
    public:
    int n,t;
    sahil()
    {
        for(int i=0;i<n;i++)
        {
            head[i]=NULL;
        }
    }
    void create();
    void display();
    void bfs();
    void dfs();

};
void sahil::create()
{   
    cout<<"How many areas:";
    cin>>n;
    for(int i=0;i<n;i++)
    {   head[i]=new node;
        head[i]->next=NULL;
        cout<<"Enter area name:";
        cin>>head[i]->area;
        cout<<"\n How many areas connected to area "<<head[i]->area<<":";
        cin>>t;
        for(int j=0;j<t;j++)
        {
            nnode=new node;
            nnode->next=NULL;
            cout<<"Enter area:";
            cin>>nnode->area;
            temp=head[i];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nnode;
        }
    }
}
void sahil::display()
{
    cout<<"\n Display:\n";
    
    for(int i=0;i<n;i++)
    {
        cout<<head[i]->area<<"->";
        for(int j=0;j<t;j++)
        {
            temp=head[i]->next;
            while(temp!=NULL)
            {
                cout<<temp->area<<" ";
                temp=temp->next;
            }
        }
        cout<<"\n";
    }
}

void sahil::bfs()
{
    int visited[10];
    queue<string>q;
    int i,j,index;
    string start,v1,v2;
    cout<<"\n****BFS TRAVERSAL****\nEnter starting vertex:";
    cin>>start;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(start==head[i]->area)
        {
            index=i; 
        }
    }
    q.push(start);
    visited[index]=1;
    while(!q.empty())
    {
        v1=q.front();
        cout<<v1<<" ";
        for(i=0;i<n;i++)
        {
            if(v1==head[i]->area)
            {
                break;
            }
        }
        temp=head[i]->next;
        while(temp!=NULL)
        {
            for(j=0;j<n;j++)
            {
                if(temp->area==head[j]->area)
                {
                    break;
                }
            }
            if(visited[j]==0)
            {
                q.push(temp->area);
                visited[j]=1;
            }
            temp=temp->next;
        }
        q.pop();
    }

}

void sahil::dfs()
{
    stack<string>s;
    int visit[10];
    int i,j,k,index;
    string start,v1;
    cout<<"\n***DFS TRAVERSAL***\nEneter starting area:";
    cin>>start;
    s.push(start);
    for(i=0;i<n;i++)
    {
        visit[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(start==head[i]->area)
        {
            index=i;
        }
    }
    visit[index]=1;
    cout<<start<<" ";
    while(!s.empty())
    {
        v1=s.top();
        
        for(i=0;i<n;i++)
        {
            if(v1==head[i]->area)
            {
                break;
            }
        }
        temp=head[i]->next;
        if(temp!=NULL)
        {
            while(temp!=NULL)
            {
               for(j=0;j<n;j++)
                {  
                    if(temp->area==head[j]->area)
                    {
                        break;
                    }
                }
                if(visit[j]==0)
                {
                    s.push(temp->area);
                    visit[j]=1;
                    cout<<temp->area<<" ";
                    break;
                }
                else
                {
                    temp=temp->next;
                }
                if(temp==NULL)
                {
                    s.pop();
                }
            }
        }
    }
}
int main()
{
    sahil s1;
    s1.create();
    s1.display();
    s1.bfs();
    s1.dfs();
}