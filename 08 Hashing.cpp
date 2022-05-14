//Assignment no 8
#include<iostream>
#include<string.h>

using namespace std;

class Node{
public:
	int chain;
	string word;
	string mean;
}obj[10];

int hash_func(string wd){
	int key=0;
	for(int i=0;i<wd.size();i++){
		key += wd[i];
	}
	return key%10;
}

void collision(int key, string wd, string mn){
	int i=1;

	while(((key+i) % 10) < 10){
		if(obj[(key+i)%10].word == "-"){
			obj[(key+i) % 10].word = wd;
			obj[(key+i) % 10].mean = mn;
			obj[(key+i-1)%10].chain = (key+i)%10;
			break;
		}
		else{
			i++;		
		}
	}
}

void hash_ini(){

	for(int i=0;i<10;i++){
		obj[i].word = "-";
		obj[i].mean = "-";
		obj[i].chain = -1;
	}
}

void hash_table(){
	
	
	string wd,mn;
	cout<<"\nEnter a word :- ";
	cin>>wd;
	cout<<"Enter Meaning for word :- ";
	cin>>mn;
	cout<<endl;
	
	int hash_key = hash_func(wd);
	
	if(obj[hash_key].word == "-"){
		obj[hash_key].word = wd;
		obj[hash_key].mean = mn;
	}
	else{
		collision(hash_key, wd, mn);
	}
	
}

void display(){
    cout<<"Index"<<"\t"<<"Word"<<"\t"<<"Meaning"<<"\t"<<"Chain"<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<"\t"<<obj[i].word<<"\t"<<obj[i].mean<<"\t"<<obj[i].chain<<endl;
    }
}

void del_key(string word){
	int key = hash_func(word);
// what if number is present but it also contains a chain? what can we 
// do how to store the chain or how to replace the contents of chain

	if(obj[key].word == word){
		obj[key].word = "-";
		obj[key].mean = "-";
		obj[key].chain = -1;
	}
	else if(obj[key].word != word){
	    int target = obj[key].chain;
		while(true){
			if(obj[target].word == word){
				obj[target-1].chain = obj[target].chain;
				obj[target].word = "-";
				obj[target].mean = "-";
				obj[target].chain = -1;
				cout<<"Deletion Successful"<<endl;
				break;
			}
			target = obj[target].chain;
		}
	}
	else{
		cout<<"Word not Found"<<endl;
	}
}

void find(string word){
	int key = hash_func(word);

	if(obj[key].word == word ){
		cout<<"Found the Word"<<endl;
		cout<<obj[key].word<<" --> "<<obj[key].mean<<endl;
	}
	else if(obj[key].chain != -1){

		int target = obj[key].chain;
		while(true){
			if(obj[target].word == word){
				cout<<"Found the Word"<<endl;
				cout<<obj[target].word<<" --> "<<obj[target].mean<<endl;
				break;
			}
			target = obj[target].chain;
		}
	}
	else{
		cout<<"Not Found"<<endl;
	}

}

int main(){
	
	int ch;
	string del_wd;
	string src;
	hash_ini();

do{
	cout<<"\n********* Enter Your Choice **********"<<endl;
	cout<<"1. Insert data in hash table"<<endl;
	cout<<"2. Display Hash Table"<<endl;
	cout<<"3. Delete word from Hash Table"<<endl;
	cout<<"4. Find word in a Hash Table"<<endl;

	cout<<"5. Exit"<<endl;
	cout<<"Enter your choice :- ";
	cin>>ch;
	cout<<endl;

	switch (ch)
	{
	case 1:
		cout<<"Enter no of Entries you want to make :- ";
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			hash_table();
		}
		break;
	
	case 2:
		display();
		break;
	
	case 3:
		cout<<"Enter the word you want to Delete :- ";
		
		cin>>del_wd;
		del_key(del_wd);
		break;

	case 4:
		cout<<"Enter the word you want to Search :- ";
		
		cin>>src;
		find(src);
		break;
	

	}

}while(ch<5);

    cout<<"Done Successfully"<<endl;

return 0;
}