#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student
{
    public:
    int roll;
    string name,div,addr;
    void getdata()
    {
        cout<<"Enter data(roll,name,div,address):";
        cin>>roll>>name>>div>>addr;
    }
    void putdata()
    {
       cout<<roll<<"\t"<<name<<"\t"<<div<<"\t"<<addr<<"\n";
    }

};
class sahil
{
    public:
    fstream file;
    student s;
    char a1,a2,a3,a4;

    void create()
    {
        file.open("file.dat",ios::out);
        do
        {
            s.getdata();
            file.write((char*)&s,sizeof(s));
            cout<<"more!";
            cin>>a1;
        }while(a1=='y');
        file.close();
    }

    void append()
    {
        file.open("file.dat",ios::app);
        do
        {
            s.getdata();
            file.write((char*)&s,sizeof(s));
            cout<<"more!";
            cin>>a2;
        }while(a2=='y');
        file.close();
    }

    void display()
    {
        file.open("file.dat",ios::in);

            while(!file.eof())
            {
            file.read((char*)&s,sizeof(s));
            if(!file.eof())
            {
            s.putdata();
            }
            }
        file.close();
    }

    void search()
    {
        int key,flag=0;
        file.open("file.dat",ios::in);
        cout<<"Enter roll no to search:";
        cin>>key;
            while(!file.eof())
            {
            file.read((char*)&s,sizeof(s));
            if(!file.eof() && s.roll==key)
            { 
                flag=1;
                cout<<"ROLL\tNMAE\tDIV\tADDRESS\n";
                s.putdata();
                break;
            } 
            }
        file.close();
        if(flag==0)
        {
            cout<<"Data not found";
        }
    }

    void del()
    {
     int key1;
     cout<<"Enter roll to delete:";
     cin>>key1;
    fstream temp;
    file.open("file.dat",ios::in);
    temp.open("temp.dat",ios::out);
    while(file.read((char*)&s,sizeof(s)))
    {
        if(!file.eof() && s.roll!=key1)
        {
         //file.read((char*)&s,sizeof(s));
         temp.write((char*)&s,sizeof(s));

        }
    }
    file.close();
    temp.close();
    remove("file.dat");
    rename("temp.dat","file.dat");    
    }
};

int main()
{
    sahil sp;
    int choise;
    char a;
    do
    {
        cout<<"1.create\n2.append\n3.display\n4.search\n5.delete\nchoise:";
        cin>>choise;
        switch(choise)
        {
            case 1:
            {
                sp.create();
                break;
            }
            case 2:
            {
                sp.append();
                break;
            }
            case 3:
            {   
                cout<<"ROLL\tNMAE\tDIV\tADDRESS\n";
                sp.display();
                break;
            }
            case 4:
            {
                sp.search();
                break;
            }
            case 5:
            {
                sp.del();
                break;
            }
            default:
            break;     
        }
        cout<<"Main menu!:";
        cin>>a;
    }while(a=='y');
}