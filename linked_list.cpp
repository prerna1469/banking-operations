#include <iostream>
using namespace std;
class node
{
	friend class list;
	int acc_no;//to store account no
	string name;//to store name
	float balance;//to store balance
	node *link;
public:
	node()//constructor
	{
		acc_no=0;
		name="\0";
		balance=0.0;
		link=NULL;
	}
};
class list
{
	node *head;
public:
	list()//constructor
	{
		head=NULL;
	}
	void create_customer();
	void display();
    void add_customer();
	void delete_customer();
	void search();
	void update_balance();
	
};
void list::create_customer()//to create list of customers
{
	node *ptr;//pointer
	node *temp;//to ceate new node
	char ch='0';//to take choice from user

	//temp->link=NULL;
    do
    {temp=new node();//creating new node
    	cout<<"\n Enter data";
		cout<<"\n Enter account number ";
		cin>>temp->acc_no;
		cout<<"\n Enter name ";
		cin>>temp->name;
		cout<<"\n Enter account balance ";
		cin>>temp->balance;


		if(head==NULL)//check if list is empty
		{
			head=temp;
		}
		else
		{
			ptr=head;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;
			}
			ptr->link=temp;
			temp->link=NULL;
		}
		cout<<"\n Do you want to continue?";
		cout<<"\n Enter y or n : ";
		cin>>ch;

	}while(ch=='y');

}

void list::display()
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n Account no= "<<ptr->acc_no;
		cout<<"\n Name is "<<ptr->name;
		cout<<"\n Account balance= Rs "<<ptr->balance;
		ptr=ptr->link;
	}

}
void list::add_customer()
{
    node *ptr;
    node *temp;
    node *prev;
    ptr=head;
    int pos=0;
    int i=0;
    cout<<"\n Enter the position at which customer is to be inserted ";
    cin>>pos;
    if(pos==1)//to insert at first pos
    {
        temp=new node();//create new node
    	cout<<"\n Enter data";
		cout<<"\n Enter account number ";
		cin>>temp->acc_no;
		cout<<"\n Enter name ";
		cin>>temp->name;
		cout<<"\n Enter account balance ";
		cin>>temp->balance;
		temp->link=head;
		head=temp;
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            prev=ptr;
            ptr=ptr->link;
        }
        
        temp=new node();
        cout<<"\n Enter data";
		cout<<"\n Enter account number ";
		cin>>temp->acc_no;
		cout<<"\n Enter name ";
		cin>>temp->name;
		cout<<"\n Enter account balance ";
		cin>>temp->balance;
		
		prev->link=temp;
		temp->link=ptr;
    }
}
void list::delete_customer()
{
    node *ptr;
    node *prev;
    node *temp;
	ptr=head;
	int flag=0;
	int flag1=0;
    int acc_no1=0;
    cout<<"\n Enter account number to be deleted ";
    cin>>acc_no1;
    if(head==NULL)//check if list is empty
    {
        cout<<"\n List is empty";
    }
    else
    {
            while(ptr!=NULL)
            {
                
                if(ptr->acc_no==acc_no1)
                {
                    flag=1;
                    prev->link=ptr->link;
                    ptr->link=NULL;
                    delete ptr;
                }
                prev=ptr;
                ptr=ptr->link;
                
            }
        }
        if(flag==1)
        {
            cout<<"\n Rest of the acc nos are: ";
            display();
        }
        
        if(flag==0)
        {
            cout<<"\n Account number not found ";
        }
    
    
}
void list::search()
{
    node *ptr;
    ptr=head;
    int acc_no1=0;
    int flag=0;
    cout<<"\n Enter account number to be searched ";
    cin>>acc_no1;
    if(head==NULL)//check if list is empty
    {
        cout<<"\n List is empty";
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->acc_no==acc_no1)
            {
                flag=1;
                cout<<"\n Account no= "<<ptr->acc_no;
    		    cout<<"\n Name is "<<ptr->name;
    		    cout<<"\n Account balance= Rs "<<ptr->balance;
            }
            ptr=ptr->link;
        }
    }
    if(flag==0)
    {
        cout<<"\n Account number not found";
    }
}
void list::update_balance()
{
    node *ptr;
    ptr=head;
    int choice=0;
    float balance1=0.0f;
    int acc_no1=0;
    int flag=0;
    cout<<"\n Enter account number whose balance is to be updated ";
    cin>>acc_no1;
    if(head==NULL)
    {
        cout<<"\n List is empty";
    }
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->acc_no==acc_no1)//check if acc_no entered is present
            {
                flag=1;
                cout<<"\n Account information: ";//display information 
                cout<<"\n Account no= "<<ptr->acc_no;
    		    cout<<"\n Name is "<<ptr->name;
    		    cout<<"\n Account balance= Rs"<<ptr->balance;
    		    cout<<"\n 1.For withdrawal";
    		    cout<<"\n 2.For deposit";
    		    cout<<"\n Enter choice ";
    		    cin>>choice;
    		    switch(choice)
    		    {
    		        case 1: do
    		                {
        		                cout<<"\n Enter amount to be withdrawn ";
        		                cin>>balance1;
        		                if(balance1>ptr->balance)//validation for withdrawal
        		                {
        		                    cout<<"\n Withdrawal amount is greater than balance, please enter agagin";
        		                }
    		                }while(balance1>ptr->balance);
    		                ptr->balance=ptr->balance-balance1;
    		                cout<<"\n Updated balance = Rs "<<ptr->balance;
    		                break;
    		        case 2: cout<<"\n Enter amount to be deposited";
    		                cin>>balance1;
    		                ptr->balance=ptr->balance+balance1;
    		                cout<<"\n Updated balance = Rs "<<ptr->balance;
    		                break;
    		        default:cout<<"\n Invalid input";
    		                break;
    		    }
            }
            ptr=ptr->link;
        }
    }
    if(flag==0)
    {
        cout<<"\n Account number not found";
    }
}

int main()
{
	int ch=0;
	list ob1;
	do
	{
    	do
    	{
    	    cout<<"\n Menu";
        	cout<<"\n 1.Create list of customers";
        	cout<<"\n 2.Display list of customers";
        	cout<<"\n 3.Add a customer ";
        	cout<<"\n 4.Delete customer";
        	cout<<"\n 5.Search customer details";
        	cout<<"\n 6.Update balance of a customer";
        	cout<<"\n 0.Exit";
        	cout<<"\n Enter choice = ";
        	cin>>ch;
    	}while(ch<0 && ch>6);
    	switch(ch)
    	{
    	    case 1: ob1.create_customer();
    	            break;
    	    case 2: ob1.display();
    	            break;
    	    case 3: ob1.add_customer();
    	            break;
    	    case 4: ob1.delete_customer();
    	            break;
    	    case 5: ob1.search();
    	            break;
    	    case 6: ob1.update_balance();
    	            break;
    	    case 0: cout<<"\n End of program.Thank you";
    	            break;
    	    default: cout<<"\n Invalid entry,please enter again";
    	            break;
    	    
    	}
    	
	}while(ch!=0);
	return 0;
}
/*
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 4

 Enter account number to be deleted 2

 List is empty
 Account number not found 
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 1

 Enter data
 Enter account number 11023451

 Enter name Prerna

 Enter account balance 1000

 Do you want to continue?
 Enter y or n : y

 Enter data
 Enter account number 11023452

 Enter name Deepak

 Enter account balance 2000

 Do you want to continue?
 Enter y or n : y

 Enter data
 Enter account number 11023453

 Enter name Hema

 Enter account balance 3000

 Do you want to continue?
 Enter y or n : n

 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 2

 Account no= 11023451
 Name is Prerna
 Account balance= Rs 1000
 Account no= 11023452
 Name is Deepak
 Account balance= Rs 2000
 Account no= 11023453
 Name is Hema
 Account balance= Rs 3000
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 3

 Enter the position at which customer is to be inserted 1

 Enter data
 Enter account number 11023454

 Enter name Amruta

 Enter account balance 4000

 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 3

 Enter the position at which customer is to be inserted 3

 Enter data
 Enter account number 11023455

 Enter name Isha

 Enter account balance 5000

 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 2

 Account no= 11023454
 Name is Amruta
 Account balance= Rs 4000
 Account no= 11023451
 Name is Prerna
 Account balance= Rs 1000
 Account no= 11023455
 Name is Isha
 Account balance= Rs 5000
 Account no= 11023452
 Name is Deepak
 Account balance= Rs 2000
 Account no= 11023453
 Name is Hema
 Account balance= Rs 3000
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 4

 Enter account number to be deleted 11023455

 Rest of the acc nos are: 
 Account no= 11023454
 Name is Amruta
 Account balance= Rs 4000
 Account no= 11023451
 Name is Prerna
 Account balance= Rs 1000
 Account no= 11023452
 Name is Deepak
 Account balance= Rs 2000
 Account no= 11023453
 Name is Hema
 Account balance= Rs 3000
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 5

 Enter account number to be searched 11023452

 Account no= 11023452
 Name is Deepak
 Account balance= Rs 2000
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 6

 Enter account number whose balance is to be updated 11023453

 Account information: 
 Account no= 11023453
 Name is Hema
 Account balance= Rs3000
 1.For withdrawal
 2.For deposit
 Enter choice 1

 Enter amount to be withdrawn 3500

 Withdrawal amount is greater than balance, please enter agagin
 Enter amount to be withdrawn 500

 Updated balance = Rs 2500
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 6

 Enter account number whose balance is to be updated 11023453

 Account information: 
 Account no= 11023453
 Name is Hema
 Account balance= Rs2500
 1.For withdrawal
 2.For deposit
 Enter choice 2

 Enter amount to be deposited25

 Updated balance = Rs 2525
 Menu
 1.Create list of customers
 2.Display list of customers
 3.Add a customer 
 4.Delete customer
 5.Search customer details
 6.Update balance of a customer
 0.Exit
 Enter choice = 0

 End of program.Thank you*/


