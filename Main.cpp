#include<iostream>
#include<iomanip>
#include<fstream>
#include"Contact.h"
#include"Address.h"
#include"ContactsBook.h"
#include "Group.h"
#include "history.h"
#include "historyob.h"
using namespace std;
int main()
{
	int choice = 0;
	bool contact_list_checker = false;
	int size = 0;
	bool contact_adder_checker = false;
	ContactsBook book_of_contacts(size);
	group contactGroup(size);

	do
	{
		cout << "\n\n";
		cout << "\t\tCONTACT BOOK" << endl;
		cout << " 1. CREATE A CONTACT SIZE" << endl;
		cout << " 2. ADD CONTACT" << endl;
		cout << " 3. MERGE DUPLICATES" << endl;
		cout << " 4. STORE TO FILE" << endl;
		cout << " 5. LOAD FROM FILE" << endl;
		cout << " 6. PRINT CONTACTS SORTED" << endl;
		cout << " 7. PRINT CONTACTS" << endl;
		cout << " 8. SEARCH CONTACTS" << endl;
		cout << " 9. DISPLAY TOTAL COUNT" << endl;
		cout << "10. ADD CONTACT IN GROUP" << endl;
		cout << "11. DISPLAY CONTACT IN GROUP" << endl;
		cout << "12. STORE GROUP TO FILE" << endl;
		cout << "13. LOAD GROUP FROM FILE" << endl;
		cout << "14. EXIT PROGRAM" << endl;
		cout << "\n\nEnter your choice: ";
		while (!(cin >> choice) || choice < 1 || choice>14)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID CHOICE !" << endl;
			cout << "TRY AGAIN : ";
		};
		cout << endl << endl;
		if (choice == 1)
		{
			if (contact_list_checker == false)
			{

				cin.ignore();
				cout << "ENTER THE SIZE OF CONTACTS LIST: ";
				while (!(cin >> size) || size < 1)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "INVALID INPUT !" << endl;
					cout << "INPUT AGAIN : ";
				};
				book_of_contacts = size;
				cout << endl;
				cout << "BOOK CREATED SUCCESSFULLY OF " << size << " CONTACTS LIST" << endl << endl;
				contact_list_checker = true;
			}
			else
			{
				cout << "YOU HAVE ALREADY CREATED THE SIZE OF THE CONTACT BOOK |" << size << " >>" << endl << endl;
			}
		}
		else if (choice == 2)
		{
			cout << "    ADD CONTACT   " << endl << endl;
			if (contact_list_checker == true)//TO SEE IF THE BOOK IS CREATED OR NOT
			{
				Address address_for_book;
				address_for_book.setAddress();
				Contact contact_for_book("", "", "", "", &address_for_book);
				contact_for_book.setContact();
				book_of_contacts.addContact(contact_for_book);
				cout << endl << endl;
				std::cout << " Contact added successfully!Total contacts : " << book_of_contacts.getContactCount() << "\n\n";
				//ONE CONTACT IS ADDED
				contact_adder_checker = true;
			}
			else
			{
				cout << " \tCREATE THE CONTACT BOOK FIRST!  " << endl << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "\tMERGE CONTACT " << endl << endl;
			if (contact_list_checker == true)
			{
				if (contact_adder_checker == true)//TO CHECK IF A CONTACT IS ADDED OR NOT
				{
					book_of_contacts.mergeDuplicates();
				}
				else
				{
					cout << "PLEASE ADD A CONTACT FIRST TO MERGE IT :" << endl << endl;
				}
			}
			else
			{
				cout << "PLEASE CREATE THE CONTACT BOOK FIRST :" << endl << endl;
			}
		}
		else if (choice == 4)
		{
			cout << "\tSAVE TO FILE " << endl;
			if (contact_list_checker == true)
			{
				if (contact_adder_checker == true)//TO CHECK IF A CONTACT IS ADDED OR NOT
				{
					cin.ignore();
					string file;
					cout << "ENTER THE FILE NAME : ";
					getline(cin, file);
					cout << endl;
					book_of_contacts.saveToFile(file);
				}
				else
				{
					cout << "ADD A CONTACT FIRST TO SAVE IT:" << endl << endl;
				}
			}
			else
			{
				cout << "CREATE THE CONTACT BOOK FIRST:" << endl << endl;
			}
		}
		else if (choice == 5)
		{
			cout << " \tLOAD FROM FILE " << endl << endl;
			cin.ignore();
			string file;
			cout << "ENTER THE FILE NAME : ";
			getline(cin, file);
			cout << endl;
			book_of_contacts.loadFromFile(file);
			ifstream reading_handler(file);
			if ((reading_handler.is_open()))
			{
				contact_adder_checker = true;
				contact_list_checker = true;
			}
		}
		else if (choice == 6)
		{
			cout << "\tCONTACT BOOK SORTED " << endl << endl;
			if (contact_list_checker == true)
			{
				if (contact_adder_checker == true)//TO CHECK IF A CONTACT IS ADDED OR NOT
				{
					book_of_contacts.printContactsSortedFunction();
				}
				else
				{
					cout << "PLEASE ADD A CONTACT FIRST TO PRINT SORTED: " << endl << endl;
				}
			}
			else
			{
				cout << "PLEASE CREATE THE CONTACT BOOK FIRST: " << endl << endl;
			}
		}
		else if (choice == 7)
		{
			cout << "\t CONTACT BOOK UNSORTED " << endl << endl;
			//CHECKER FOR SEEING THAT THE BOOK IS CREATED OR NOT
			if (contact_list_checker == true)
			{
				//CHECKER TO CHECK THAT CONTACT IS ADDED OR NOT
				if (contact_adder_checker == true)
				{
					book_of_contacts.printContactsUnsortedFunction();
				}
				else
				{
					cout << "PLEASE ADD A CONTACT FIRST TO PRINT IT :" << endl << endl;
				}
			}
			else
			{
				cout << "PLEASE CREATE THE CONTACT BOOK FIRST ! :" << endl << endl;
			}
		}
		else if (choice == 8)
		{
			cout << "\t SEARCH CONTACT" << endl << endl;
			if (contact_list_checker == true)//TO CHECK IF BOOK IS CREATED OR NOT
			{
				if (contact_adder_checker == true)//TO CHECK IF A CONTACT IS ADDED OR NOT
				{
					book_of_contacts.findEntireContact();
					cout << endl << " SEARCHING ENDED SUCCESFULLY " << endl;
				}
				else
				{
					cout << "PLEASE ADD A CONTACT FIRST TO SEARCH IT:" << endl << endl;
				}
			}
			else
			{
				cout << "PLEASE CREATE THE CONTACT BOOK FIRST :" << endl << endl;
			}
		}
		else if (choice == 9)
		{
			cout << " TOTAL CONTACTS " << endl << endl;
			if (contact_list_checker == true)
			{
				cout << "TOTAL NUMBER OF CONTACTS CURRENTLY : " << book_of_contacts.getContactCount() << endl << endl;
			}
			else
			{
				cout << "PLEASE CREATE THE CONTACT BOOK FIRST :" << endl << endl;
			}
		}
		else if (choice == 10)
		{
			string groupName;
			cout << "Enter group name: ";
			cin >> groupName;

			Contact* contact = book_of_contacts.copyContactsList();
			cout << "Select a contact to add to group:" << endl;

			for (int i = 0; i < book_of_contacts.totalContacts(); ++i)
			{
				std::cout << i + 1 << ". ";
				contact[i].printContact();
			}

			int contactIndex;
			cout << "Enter the index of the contact to add to group: ";
			cin >> contactIndex;

			if (contactIndex >= 1 && contactIndex <= book_of_contacts.totalContacts())
			{
				contactGroup.addContact(contact[contactIndex - 1]);
			}
			else 
			{
				cout << "Invalid contact index. Please enter a valid index." << endl;
			}
		}
		else if (choice == 11)
		{
			cout << "you are now displaying contacts in groups\n";
			contactGroup.DisplayContacts();
		}
		else if (choice == 12)
		{
			cout << "you are now saving group in a file\n";
			string file_name;
			cout << "Enter file name to save contacts to: ";
			cin >> file_name;
			book_of_contacts.saveToFile(file_name);
		}
		else if (choice == 13)
		{
			cout << "you are now loading group from file\n";
			string file_name;
			cout << "Enter file name to load contacts from: ";
			cin >> file_name;
			book_of_contacts.loadFromFile(file_name);
		}
		else if (choice == 14)
		{

		}
		cin.ignore();
		system("pause");
		system("cls");
	} while (choice != 14);
}