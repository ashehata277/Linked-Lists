#include<iostream>
#include<fstream>                                                            // to use files
using namespace std;
struct accountrequire                                                       //type including the data which need to make a one record 
{
	long long int acountnumber;
	char firstname[10];
	char lastname[10];
	float balance;
	//char address[30];
	//char date[10];
	//char job[50];
};
struct link                                                                         // type of link to make a linked list
{
	accountrequire data;                                                           // type of accountrequire include the all data about account  
	link* next;
};
class record
{
	private:                                                                        // private methods 
		link* first;                                                               // private pointer point to the first link in the list 
	public:
	    record()
		{
			first=NULL;
		}
		void write();
		void search(long long int a);
		void updata( long long int b);
		void read ();
		void deleting(long long int a);
		void writinginfile();
		//void SavebeforeDelete();	
};
void record::write()
{
	link* newrecord=new link;
	cout<<"Enter the information about record "<<endl;                     //the information about any record and do new record and to insert the information about account from user 
	cout<<"1-Account number"<<endl;
	cin>>newrecord->data.acountnumber;
	cout<<"2-First name"<<endl;
	cin>>newrecord->data.firstname;
	cout<<"3-Last name"<<endl;
	cin>>newrecord->data.lastname;
	cout<<"4-The balance"<<endl;
	cin>>newrecord->data.balance;
	newrecord->next=first;
	first=newrecord;
	cout << "*******************************************" << endl;
    cout << "***********Successful  Process*************" << endl;
    cout << "*******************************************" << endl;
}
void record::read()                                                           // this function display the accounts of all clients
{
	link* current=first;         
	if(current==NULL)
	cout<<"the program dont have any accounts "<<endl;                        // this statment when we dont insert any accounts from user 
	while(current!=NULL)
	{
	    cout << "*******************************************" << endl;
	    cout << "***************Information*****************" << endl;
	    cout << "*******************************************" << endl;
		cout<<"The Account Number is: "<<current->data.acountnumber<<endl;
		cout<<"The First Name is: "<<current->data.firstname<<endl;
		cout<<"The Last Name is: "<<current->data.lastname<<endl;
		cout<<"The Balance of The account is: "<<current->data.balance<<endl;
		current=current->next;
	}
}
void record::search(long long int a)                                             // this function to search about custom account by account number from user 
{
	link* check=new link;
	check=first;
	while(check!=NULL)                                                        // to check the linked list is empty or not  
	{
		if(check->data.acountnumber==a)
		{
    	cout << "*******************************************" << endl;
        cout << "***************Information*****************" << endl;
	    cout << "*******************************************" << endl;
		cout<<"The Account Number is: "<<check->data.acountnumber<<endl;
		cout<<"The First Name is: "<<check->data.firstname<<endl;
		cout<<"The Last Name is: "<<check->data.lastname<<endl;
		cout<<"The Balance of The account is: "<<check->data.balance<<endl;
		return;
		}
		check=check->next;                                                    //to change the pointer destination 
	}
	cout<<"The Account searching not found"<<endl;
}
void record::updata(long long int b)                                  // The Function to change the Balance
{
	link* searcher=new link;
	searcher=first;
	while(searcher!=NULL)
	{
		if(searcher->data.acountnumber==b)
		{
			cout<<"Enter new balance"<<endl;
			cin>>searcher->data.balance;
		}
		searcher=searcher->next;
		cout<<"The Account Number not found"<<endl;
	}
}
void record::deleting(long long int a)                         //The Function to hide link from the list  
{
	link* deleter = new link;
	link* checker = new link;
	link* next    = new link; 
	deleter = first;                                               //pointer to determined the account we need yo delete
	checker = first;                                              //pointer to determined the account before account we need  
	next    = first;                                             // pointer to check the linked list is empty or not 
	bool Isexist=false;
    while(next!=NULL)
	{
	     if(next->data.acountnumber==a)
		 {
		    Isexist=true;
		    break;	
		 } 
		 next=next->next; 	
	}
	if(Isexist==false)
	{
	    cout<<"We Dont Have Accounts Have This Number Check The Account Number And Try Again "<<endl;	
	}	
	if(deleter==NULL)
	{
		cout<<"The Program Is Empty"<<endl;
	    return ;
	}
	if(deleter->data.acountnumber==a)
	{
		first=deleter->next;
		cout<<"The Acount Is Deleted "<<endl;
		return ;
	}
	while(deleter->next!=NULL)
	{
		if(deleter->data.acountnumber==a)
		{
			break;
		}
		deleter=deleter->next;
	}
	while(deleter->next!=NULL)
	{
		if(checker->next==deleter)
		{
			break;
		}
		checker=checker->next;
	}
	checker->next=deleter->next;
	return ;
}
void record::writinginfile()                                             // The Function to Save The Data In File 
{
	ofstream myFile("StorageData",ios :: app);
    link* current = new link;
    current=first; 
	while(current!=NULL)
	{
	    myFile << "*******************************************" << endl;
	    myFile << "***************Information*****************" << endl;
	    myFile << "*******************************************" << endl;
		myFile <<"The Account Number is: "<<current->data.acountnumber<<endl;
		myFile <<"The First Name is: "<<current->data.firstname<<endl;
		myFile <<"The Last Name is: "<<current->data.lastname<<endl;
		myFile <<"The Balance of The account is: "<<current->data.balance<<endl;
		current=current->next;
	}
	    cout << "*******************************************" << endl;
	    cout << "********The Information IS Saved***********" << endl;
	    cout << "*******************************************" << endl;
}
int main()
{
int x; 
record a;
int z=1;
while(z==1)
{   
   while(z==1)
   {
    cout << "***********************************************************************************************************************" << endl;
	cout << "****************************************************Program Bank*******************************************************" << endl;
	cout << "***********************************************************************************************************************" << endl;
	cout<< "Enter What You Need From This Processors"<<endl;
	cout<<" 1-Search for account"<<endl;
	cout<<" 2-Make account"<<endl;
	cout<<" 3-Updata balance"<<endl;
	cout<<" 4-Read all accounts"<<endl;
	cout<<" 5-Delete account"<<endl;
	cout<<" 6-Save The Data Of All Accounts You Inserted"<<endl;
	cout<<" 7-Quite The Program"<<endl;
	cin>> x;
	switch(x)
	{
		case 1:                //case 1 to search about info's accounts by name
			long long int r;
	        cout<<"Enter The Account Number which need to search about"<<endl;
			cin>>r;	
			a.search(r);
			break;
		case 2:                       //to search about info's accounts by ID
			a.write();
			break;
		case 3:                      //to change in info
		    long long int f;
		    cout<<"Enter The Account Number which need to updata balance"<<endl;
		    cin>>f; 
 		    a.updata(f);
			 break;
		case 4:                        //to show information's account 
		    a.read();
			break;
		case 5:                       //to hide information 
		    long long int q;
		    cout<<"Enter The Account Number which need to delete"<<endl;
		    cin>>q;
		    a.deleting(q);
			break;
		case 6:
			a.writinginfile();
			break;
		case 7:                           //case 7 to quite switch    
			z=0;
			break; 				
	}
   }
}
/* static_cast<double>(variable) that's mean change the value without change in type variable  casting 
static int =0;
that's mean when we call function do this line in once calling
pointers is a best way to deal with array of char
we can print pointer of character by the same way which can print array of character
remember that:1- the the friend functions with class
              2- structure 
              3- enumeration
              4- call by pointers
              5- call by reference
remeber that:
when we print array of pointers we can print by address of the first element
and we use two demion array we can print the first row by the address of the first element in the row               
*/
system("pause");
return 0; 
}
