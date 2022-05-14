#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct dict
{
	char cWord[20];
	char cMeaning[20];

}; 	

class hashtable
{
	public:
		dict ht[max];
		hashtable()
		{
			for(int i=0;i<max;i++)
			{
				strcpy(ht[i].cWord,"");
				strcpy(ht[i].cMeaning,"");
			}
		}
		
		int hash(char ckey[10])
		{
			int i,s=0;
			for(i=0;ckey[i]!='\0';i++)
			{
				s=s+ckey[i];
			}
			return(s%max);
		
		}
		
		void insert_word(dict d);
		void display();
		int search_word(char cW[]);
		void del_word(char cW[]);
		
};

void hashtable::insert_word(dict d)
{
	int iIndex=10;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(d.cWord)+i*i)%max;
		cout<<"\n\n Position :"<<i<<" "<<iIndex;
		if(i>0)
		cout<<"\n Collision at "<<iIndex; 
		if(strcmp(ht[iIndex].cWord,"")==0)
		{
			ht[iIndex]=d;
			break;
		}
	}	
		
}

void hashtable::display()
{
	cout<<"Index\t\tWord\t\tMeaning";
	for(int i=0;i<max;i++)
	{
		cout<<"\n"<<i<<"\t\t"<<ht[i].cWord<<"\t\t"<<ht[i].cMeaning<<"\n";
	}

}


int hashtable::search_word(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0)
		{
			cout<<"\nWord Found and the Meaning is: "<<ht[iIndex].cMeaning;
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\nWord Not Found!";
	
}

void hashtable::del_word(char cW[10])
{
	int iIndex,iFlag=0;
	for(int i=0;i%max!=iIndex;i=(i+1)%max)
	{
		iIndex=(hash(cW)+i*i)%max;
		if(strcmp(ht[iIndex].cWord,cW)==0)
		{
			cout<<"\nWord Found and deleted: "<<ht[iIndex].cMeaning;
			strcpy(ht[iIndex].cWord,"");
			strcpy(ht[iIndex].cMeaning,"");
			iFlag=1;
			break;
		}
	}
	if(iFlag==0)
	cout<<"\nWord Not Found!";
	
}

	
int main()
{
	char cW[10];
	int iCh,iFlag=0;
	hashtable h;
	dic d;
	do
	{
		
		cout<<"\n--- Menu ---"<<"\n1. INSERT WORD   \n2. DISPLAY     \n3. SEARCH MEANING    \n4. DELETE     \n5. EXIT";
		cout<<"Enter your Choice: ";
		cin>>Ch;
		cout<<"\n";
		
		switch(Ch)
		{
			case 1:
				cout<<"\n Enter Word to Insert: ";
				cin>>d.cWord;
				cout<<"\n Enter Meaning: ";
				cin>>d.cMeaning;
				h.insert_word(d);
				break;
				
			case 2:
				h.display();
				break;
				
			case 3:
				cout<<"\n Enter Word to be Searched: ";
				cin>>cW;
				h.search_word(cW);
				break;
				
			case 4:
				cout<<"\n Enter the Word to be Deleted: ";
				cin>>cW;
				h.del_word(cW);
				break;
			
			case 5:
			    cout<<"\nThank You!!"
				
		}
	}			
return 0;
}