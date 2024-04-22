#include<iostream>
using namespace std;
struct node
{
        int data;
	node *left,*right;
};
node *nnode,*temp;
node *root;
class bst
{
	public:
		//node* root;
		bst()
		{
			root=NULL;
		}
		int key;
	void create();
	void display(node* temp1);
	void mirror(node* temp);
	void min(node* temp);
	void max(node* temp2);
	void search(node* temp);
};

void bst::create()
{
	nnode=new node;
	nnode->left=NULL;
	nnode->right=NULL;
	cout<<"\n Enter data:";
	cin>>nnode->data;
	if(root==NULL)
	{
		root=nnode;
	}
	else
	{
	   temp=root;
		while(1)
		{
		if((temp->data)>(nnode->data))
		{
		  if(temp->left==NULL)
		  {
		  	temp->left=nnode;
		  	break;
		  }
		  else
		  {
		  temp=temp->left;
		  }
		}
		else
		{
			if(temp->right==NULL)
			{
				temp->right=nnode;
				break;
			}
			else
			{
			temp=temp->right;
		}
		}
		
	}
}
}

void bst::display(node* temp1)
{
 if(temp1!=NULL)
 {
 	display(temp1->left);
 	cout<<temp1->data<<" ";
 	display(temp1->right);
 	
 }	
}
void bst::mirror(node* temp)
{
 if(temp!=NULL)
 {
 	mirror(temp->right);
 	cout<<temp->data<<" ";
 	mirror(temp->left);
 		
 }	
}
void bst::min(node *temp)
{   
	    temp=root;
		while(1)
		{  
		  if(temp->left==NULL)
		  {
		  	cout<<"\n Min:"<<temp->data;
		  	break;
		  }
		  else
		  {
		  temp=temp->left;
	     }
		
}
}

void bst::max(node* temp2)
{      int count=0;
	   temp=root;
		while(1)
		{  // count++;
			if(temp->right==NULL)
			{   
				break;
			}
			else
			{
			count++;
			temp=temp->right;
		    }
		}
		cout<<"\n NUMBER OF NODES:"<<count+1;

		
	}


void bst::search(node* temp)
{
	cout<<"\n Enter data to search:";
	cin>>key;
	int flag=0;
	
	   temp=root;
		while(1)
		{
		if((temp->data)>(key))
		{
		  if(temp->data==key)
		  { flag==1;
		  	//temp->left=nnode;
		  	break;
		  }
		  else
		  {
		  temp=temp->left;
	     }
		}
		else
		{
			if(temp->data==key)
			{    flag=1;		//temp->right=nnode;
				break;
			}
			else
			{
			temp=temp->right;
		}
		}
		
	}

if(flag==0)
{
	cout<<"Not found";
}
else
{
	cout<<"Found";
}
}

int main()
{
	char ch;
	bst b1;
	do
	{
		b1.create();
		cout<<"Add More Node! : ";
		cin>>ch;
	}while(ch=='y');
	cout<<"\n BST: ";
	b1.display(root);
	b1.min(root);
	b1.max(root);
	b1.search(root);
	cout<<"\n Mirror:";
	b1.mirror(root);
	
	return 0;
}
