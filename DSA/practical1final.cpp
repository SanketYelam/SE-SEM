#include<iostream>
#include<string>
using namespace std;
struct array
{
    string name;
    long int tel;
};

class sahil
{
    public:
    int n;
    int T;
    
    sahil()
    {
        cout<<"Size of table:";
        cin>>T;
        //cout<<"How many client:";
        //cin>>n;

    }
    struct array A[10];
    struct array B[10];
    long int te;
    char nm[10];
    void init();
    void hash();
    void display();
    void search();
    void display1();
    void qua();
};

void sahil::init() 
{
    for(int i=0;i<T;i++)
    {
        A[i].name="null";
        A[i].tel=0;
        B[i].name="null";
        B[i].tel=0;
    }
}

void sahil::hash()
{
  
        cout<<"How many client:";
        cin>>n;
  int y;
    for(int j=0;j<n;j++)
    {
        
        cout<<"Enter name:";
        cin>>nm;
        cout<<"Enter tel:";
        cin>>te;

        int k=0;
        int total=0;
        while(nm[k]!='\0')
        {
            total+=int(nm[k]);
            k++;

        }
        cout<<"TOTAL:"<<total<<"\n";
        int a;
        a=total%T;
        cout<<"base addr:"<<a<<"\n";
        int x;
      //int h=1;
        
        for(x=a;x<T;x=(x+1)%T)
        {   
            if(A[x].name=="null")
            {
                A[x].name=nm;
                A[x].tel=te;
                break;
            }
           
        }
        //quadratic
        int p=0;
        for(y=0;y<(T-1)/2;y++)
        {   cout<<"a="<<a;
            int kp=(a+p*p)%T;
            cout<<"k="<<kp;
            if(B[kp].name=="null")
            {
                B[kp].name=nm;
                B[kp].tel=te;
                break;
            }
            p++;
          
        }
    }

    
}
/*void sahil::qua()
{ 
 
        cout<<"How many client:";
        cin>>n;

    for(int j=0;j<n;j++)
    {
        

        cout<<"Enter name:";
        cin>>nm;
        cout<<"Enter tel:";
        cin>>te;

        int k=0;
        int total=0;
        while(nm[k]!='\0')
        {
            total+=int(nm[k]);
            k++;

        }
        cout<<"TOTAL:"<<total<<"\n";
        int a;
        a=total%T;
        cout<<"base addr:"<<a<<"\n";
        int x;
      //int h=1;
        
        for(x=a;x<T;x=(x+j*j)%T)
        {   
            if(B[x].name=="null")
            {
                B[x].name=nm;
                B[x].tel=te;
                break;
            }
          
        }     
    }
} */
void sahil::display()
{   cout<<"\n LINEAR PROBING\n";
    cout<<"   NAME     "<<"   TELEPHONE  \n";
    for(int m=0;m<T;m++)
    {  cout<<m<<". ";
       cout<<A[m].name<<"\t\t"<<A[m].tel<<"\n";
    }
    cout<<"\n QUADRATIC PROBING\n";
    cout<<"   NAME     "<<"   TELEPHONE  \n";
    for(int m=0;m<T;m++)
    {  cout<<m<<". ";
       cout<<B[m].name<<"\t\t"<<B[m].tel<<"\n";
    }
}
/*void sahil::display1()
{   cout<<"NAME     "<<"   TELEPHONE  \n";
    for(int m=0;m<T;m++)
    {
       cout<<B[m].name<<"\t"<<B[m].tel<<"\n";
    }
}*/
void sahil::search()
{
    string snm;
	cout<<"To search tel num of client(name): ";
	cin>>snm;
	int i=0,t=0,len=0,o=0,h=0;
	while(snm[i]!='\0')
    {
        t=t+int(snm[i]);
        i++;
    }
    t=t%T;
    for(int j=t;j<T;j=(j+1)%T)
    {
    		len++;
    		if(A[j].name==snm)
    		{  
    		cout<<"\n Name:"<<snm;
            cout<<"\nTEL:"<<A[j].tel<<"\n"; 
    			break;
    		}
            
    }
    cout<<"Comparisons in linear probing:"<<len<<"\n";

    len=0;
    for(int k=0;k=(T-1)/2;k++)
    { 	
    	h=t+o*o;
    	h=h%T;
    	len++;	
    	if(B[h].name==snm)
    	{   
    	   cout<<"\nName:"<<snm;
           cout<<"\nTEL:"<<B[h].tel<<"\n"; 	
           break;
    	}
        o++;
    }
    cout<<"Comparisons in quadratic probing:"<<len<<"\n";
}
int main()
{
    sahil s;
    s.init();
    char cp;
    int ch;
    do
    {
    cout<<"1.Create hash table\n2.Display\n3.search";
    cout<<"\nChoise:";
    cin>>ch;
    switch(ch)
    {
      case 1:
         s.hash();
         //s.display();
         break;
      case 2:
         s.display();
         break;
      case 3:
         s.search();
         break;
    }
    cout<<"\n More :";
    cin>>cp;
    }while(cp=='y'); 
    //s.display();
    //s.search();
    return 0;
}
