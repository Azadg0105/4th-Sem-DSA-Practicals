#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;

class student
{
 int rollno;
 char name[50];
 char addr[50];
 public:
 void setData()
 {
  cout<<"\nEnter Roll Number: ";
  cin>>rollno;
  cout<<"Enter the Name: ";
  cin>>name;
  cout<<"Enter the Address: ";
  cin>>addr;
 }
        void showData()
        {
               cout<<"\nStudent's Roll No.: "<<rollno;
               cout<<"\nStudent's Name: "<<name;
               cout<<"\nAddress: "<<addr;
        }
        int retrollno()
        {
            return rollno;
        }
};
        void write_record()
        {
              ofstream outFile;
              outFile.open("student.dat",ios::binary|ios::app);
              student obj;
              obj.setData();
              outFile.write((char*)&obj,sizeof(obj));
              outFile.close();
        }
         void display()
        {
              ifstream inFile;
              inFile.open("student.dat",ios::binary);
              student obj;
              while(inFile.read((char*)&obj,sizeof(obj)));
              {
                obj.showData();
              }
              inFile.close();
        }
         void search(int n)
        {
              ifstream inFile;
              inFile.open("student.dat",ios::binary);
              int flag=0;
              student obj;
              while(inFile.read((char*)&obj,sizeof(obj)));
              {
                if(obj.retrollno()==n) 
                {
                    obj.showData();
                    flag=1;
                }
              }
              if(flag==0)
              cout<<"\nRecord Not Found";
              inFile.close();
        }
        void delete_record(int n)
        {
              student obj;
              ifstream inFile;
              inFile.open("student.dat",ios::binary);
              ofstream outFile;
              outFile.open("temp.dat",ios::binary|ios::app);
              while(inFile.read((char*)&obj,sizeof(obj)));
              {
                if(obj.retrollno()!=n) 
                {
                    outFile.write((char*)&obj,sizeof(obj));
                }
              }
              inFile.close();
              outFile.close();
              remove("student.dat");
              rename("temp.dat","student.dat");
        }
int main()
{
int ch;
do
{
cout<<"\n--- File Operations ---\n1. Write\n2. Display\n3. Search\n4. Delete";
cout<<"\nEnter your Choice: ";
cin>>ch;
switch(ch)
{
case 1: 
cout<<"\nEnter Number of Records: ";
int n;
cin>>n;
for(int i=0; i<n; i++) 
write_record(); 
break;
case 2:
cout << "\nList of Records"; 
display();
break;
case 3:
cout<<"Enter Student Roll No: ";
int s;
cin>>s;
search(s);
break;
case 4:
cout<<"Enter Number to be Deleted: ";
int d;
cin>>d;
delete_record(d); 
cout << "\nRecord Deleted!";
break;
case 5:
return 0;
}
}while(ch!=5);
};
