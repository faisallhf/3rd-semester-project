#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;
struct Node
{
	string name;
	string phone_number;    
	Node *next;
	Node *prev;
};
class ContactBook
{
		Node *head;
		string user_name;
		string ph_number;
	public:
		ContactBook()
		{
			head=NULL;
			user_name="";
			ph_number= "";
		}

		void Loading()

		{
			system("COLOR 0e");
			system("cls");
			int bar1=177, bar2=219;
			cout<<"\n\n\n\t\t\t\tLoading...";
			cout<<"\n\n\n\t\t\t\t";
			for(int i=0	; i<25; i++)
				cout<<char(bar1);
			cout<<'\r';
			cout<<"\t\t\t\t";
			for(int i=0	; i<25; i++)
			{
				cout<<char(bar2);
				Sleep(90);
			}
			system("cls");
		}


		void CreateNode()
		{
			if(head==NULL)   //1st number
			{
				Node *newer= new Node;
				cout<<"Name of Contact: ";
				cin>>user_name;
				newer->name=user_name;

				cout<<"Phone Number: ";
				cin>>ph_number;
				newer->phone_number=ph_number;

				newer->next=NULL;
				newer->prev==NULL;
				head=newer;

				cout<<"Contact Added SuccessFully."<<endl;
			}
			else
			{
				Node *newer= new Node;
				cout<<"Name of Contact: ";
				cin>>user_name;
				newer->name=user_name;

				cout<<"Phone Number: ";
				cin>>ph_number;
				newer->phone_number=ph_number;

				newer->next=NULL;

				Node *temp=head;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=newer;
				newer->prev=temp;
				cout<<"Contact Added SuccessFully"<<endl;
			}
		}


		void Display()
		{
			Node *temp=head;
			int count=0;

			if(temp==NULL)
			{
				cout<<"No Contacts... Add Some Contacts"<<endl;
				cout<<"Thanks"<<endl;
			}
			else
			{
				cout<<"Name: "<<"      Number: "<<endl;
				while(temp!=NULL)
				{
					count++;
					cout<<temp->name;
					cout<<"        "<<temp->phone_number<<endl;
					temp=temp->next;
				}
				cout<<"Total contacts: "<<count<<endl;
			}
		}


		void Search()
		{
			bool check=false;
			Node *temp=head;
			cout<<endl;
			cout<<"Search By Name, Press 1"<<endl;
			int command;
			cout<<"Enter the Command: ";
			cin>>command;

			if(command==1 && temp!=NULL)
			{
				cout<<"Enter Your Contact Number To Search"<<endl;
				cin>>user_name;
				while(temp!=NULL)
				{
					if(temp->name==user_name)       
					{
						cout<<endl;
						cout<<"Name: "<<temp->name<<endl;
						cout<<"Phone Number:"<<temp->phone_number<<endl;
						cout<<endl;
						check=true;
						break;
					}
					temp=temp->next;
				}
				if(check==false)
				{
					cout<<"Name Not Found"<<endl;
				}
			}
			else
			{
				cout<<"You Entered Wrong Command.\n";
			}
		}

		void EditContacts()
		{
			Node *temp=head;
			cout<<endl;
			cout<<"Search By Name, Press 1"<<endl;
			int Ecommand;
			cout<<"Enter the Command: ";
			cin>>Ecommand;

			if(Ecommand==1)
			{
				bool Echeck=false;
				cout<<"Enter the Name to Edit: ";
				cin>>user_name;
				while(temp!=NULL)
				{
					if(temp->name==user_name)
					{
						cout<<endl;
						cout<<"Name: "<<temp->name<<endl;
						cout<<"Phone Number: "<<temp->phone_number<<endl;
						cout<<endl;
						Echeck=true;
						break;
					}
					temp=temp->next;
				}
				if(Echeck==true)
				{
					int command;
					cout<<"Search By Name, Press 1";
					cin>>command;
					if(command==1)
					{
						cout<<"Enter New Name: ";
						cin>>user_name;
						cout<<"Enter New Number: ";
						cin>>ph_number;

						temp->name=user_name;
						temp->phone_number=ph_number;

						cout<<"Contact Edited Success Fully"<<endl;
					}
					else
					{
						cout<<"You Enter Wrong Command ... Try Again"<<endl;
					}
				}
				else if(Echeck==false)
				{
					cout<<"Contact Not Found"<<endl;
				}
			}
			else
			{
				cout<<"You Enter Wrong Command ... Try Again"<<endl;
			}
		}


		void DeleteContactBySearch()
		{

			Node *temp=head;
			cout<<endl;
			cout<<"Search By Name, Press 1"<<endl;
			cout<<"Search By Number, Press 2"<<endl;
			int command;
			cout<<"Enter the Command: ";
			cin>>command;

			if(command==1)
			{	bool Dcheck=false;
				cout<<"Enter the Name to Delete: ";
				cin>>user_name;
				while(temp!=NULL)
				{	if(temp->name==user_name)
					{	cout<<endl;
						cout<<"Name: "<<temp->name<<endl;
						cout<<"Phone Number: "<<temp->phone_number<<endl;
						cout<<endl;
						Dcheck=true;
						break;
					}
					temp=temp->next;
				}
				if(Dcheck==true)
				{	int command;
					cout<<"To Delete the Contact, Press 1: ";
					cin>>command;
					if(command==1 && temp==head)
					{	Node *temp1;
						temp1=temp;
						temp=temp->next;
						delete temp1;

						temp->prev=NULL;
						head=temp;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
					else if(command==1 && temp->next==NULL)
					{	temp->prev->next=NULL;
						delete temp;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
					else if(command==1)
					{	Node *temp1;
						temp1=temp;
						temp->prev->next=temp1->next;
						temp->next->prev=temp1->prev;
						delete temp1;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
					else
					{	cout<<"You Enter Wrong Command ... Try Again"<<endl;
					}
				}
				else if(Dcheck==false)
				{	cout<<"Contact of This Name Not Found."<<endl;
				}
			}
			else if(command==2)
			{ bool Dcheck=false;
				cout<<"Enter the Number to Delete: ";
				cin>>ph_number;
				while(temp!=NULL)
				{	if(temp->phone_number==ph_number)
					{	cout<<endl;
						cout<<"Name: "<<temp->name<<endl;
						cout<<"Phone Number: "<<temp->phone_number<<endl;
						cout<<endl;
						Dcheck=true;
						break;
					}
					temp=temp->next;
				}
				if(Dcheck==true)
				{	int command;
					cout<<"To Delete the Contact, Press 1: ";
					cin>>command;
					if(command==1 && temp==head)
					{	Node *temp1;
						temp1=temp;
						temp=temp->next;
						delete temp1;

						temp->prev=NULL;
						head=temp;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
					else if(command==1 && temp->next==NULL)
					{	temp->prev->next=NULL;
						delete temp;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
					else if(command==1)
					{	Node *temp1;
						temp1=temp;
						temp->prev->next=temp1->next;
						temp->next->prev=temp1->prev;
						delete temp1;
						cout<<"Contact Deleted SuccessFully"<<endl;
					}
			else
			{	cout<<"You Enter wrong Command"<<endl;
			}
		
		}
		}
	}



		void DeleteAllContacts()
		{
			Node *temp=head;
			Node *temp2;
			if(head==NULL)
			{
				cout<<"Contact Book is Empty"<<endl;
				cout<<endl;
			}
			else
			{
				while(temp!=NULL)
				{
					temp2=temp;
					temp=temp->next;
					delete temp2;
				}
				head=NULL;
				cout<<"Successfully Deleted All Contacts."<<endl;
				cout<<endl;
			}
		}


		void SaveContact()
		{
			Node *temp=head;
			ofstream myfile ("contactbook.txt");
			if (myfile.is_open())
			{
				while(temp!=NULL)
				{
					myfile<<temp->name<<endl;
					myfile<<temp->phone_number<<endl;
					temp=temp->next;
				}
				myfile.close();
				MainMenu();
			}
			else
			{
				cout<<"Thanks file is empty."<<endl;
			}
		}


		void ReadContact()
		{
			bool isEmpty;
			ifstream myfile ("contactbook.txt");
			if (myfile.is_open() & myfile.peek() != EOF)
			{
				int i=0;
				while(getline(myfile,user_name))
				{
					if(i % 2 == 0)
					{
						if(head==NULL)
						{
							Node *newer= new Node;
							newer->name=user_name;

							newer->next=NULL;
							newer->prev==NULL;
							head=newer;
						}
						else
						{
							Node *newer= new Node;

							newer->name=user_name;
							newer->next=NULL;

							Node *temp=head;
							while(temp->next!=NULL)
							{
								temp=temp->next;
							}
							temp->next=newer;
							newer->prev=temp;
						}
					}
					else
					{
						Node *temp=head;
						if(temp->phone_number=="")
						{

							stringstream convert(user_name);
							convert>>ph_number;
							temp->phone_number=ph_number;
						}
						else
						{
							Node *temp=head;
							while(temp->next!=NULL)
							{
								temp=temp->next;
							}

							stringstream convert(user_name);
							convert>>ph_number;
							temp->phone_number=ph_number;

						}

					}
					i++;
				}
				myfile.close();
			}
			else
			{
				cout<<"  File is Empty so Cannot open...Sorry"<<endl;
			}
		}

		void MainMenu()
		{
			cout<<"\n\n";
			cout<<"1. Add Contact"<<endl;
			cout<<"2. Edit the Contact"<<endl;
			cout<<"3. Delete Contact"<<endl;
			cout<<"4. Search Contact"<<endl;
			cout<<"5. Display All Contacts"<<endl;
			cout<<"6. Delete All Contacts"<<endl;
			cout<<"7. Exit the Contact Book"<<endl;

			int Mcommand;
			cout<<"Enter the Command: ";
			cin>>Mcommand;
			switch(Mcommand)
			{
				case 1:
				{
					CreateNode();
					SaveContact();
					MainMenu();
					break;
				}
				case 2:
				{
					EditContacts();
					SaveContact();
					MainMenu();
					break;
				}
				case 3:
				{
					DeleteContactBySearch();
					MainMenu();
					break;
				}
				case 4:
				{
					Search();
					MainMenu();
					break;
				}
				case 5:
				{
					Display();
					SaveContact();
					MainMenu();
					break;
				}
				case 6:
				{
					DeleteAllContacts();
					SaveContact();
					MainMenu();
					break;
				}
				case 7:
				{
					cout<<"Quiting";
					for(int i=0; i<5; i++)
					{
						cout<<" . ";
						Sleep(300);
					}
					exit(0);
				}
			}
		}
};

int main()
{
	ContactBook c1;
	c1.Loading();
	c1.ReadContact();
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"=========================";
	cout<<"\t\t\t\t\t\t\t\t\t\tWELCOME TO CONTACT BOOK";
	cout<<endl;
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"==============================";
	cout<<"=========================";
	c1.MainMenu();
	return 0;
}
