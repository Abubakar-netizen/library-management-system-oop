#include "ContactsBook.h"
#include"Contact.h"
#include<fstream>
using namespace std;

ContactsBook::ContactsBook()
{

}
//PARAMETRIZE CONSTRUCTOR
ContactsBook::ContactsBook(int size_of_list)
{
	contacts_list = new Contact[size_of_list];
	contacts_count = 0;
	size_of_contacts = size_of_list;
}
//FOR ADDING CONTACT
void ContactsBook::addContact(const Contact& contact)
{
	if (full())
	{
		resizeList();
	}
	//CONTACT OPERATOR OVERLOADING
	contacts_list[contacts_count] = contact;
	contacts_count++;
}
int ContactsBook::totalContacts()
{
	return contacts_count;
}
//FOR RESIZING THE LIST IF ARRAY IS FULL NO SPACE IN ARRAY
void ContactsBook::resizeList()
{
	Contact* temporary_list = new Contact[size_of_contacts * 2];
	//COPYING THE DATA TO TEMPORARY ARRAY
	for (int i = 0; i < size_of_contacts; i++)
	{
		temporary_list[i] = *(contacts_list[i].copy_contact());
	}
	delete[] contacts_list;
	contacts_list = temporary_list;
	size_of_contacts = size_of_contacts * 2;
}
//CHECKING ARRAY IS FULL OR NOT
bool ContactsBook::full()
{
	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void ContactsBook::printContactsSorted(string choice)
{
	//RETURNS THE COPY OF ORIGINAL CONTACT ARRAY
	Contact* sorted_contacts = copyContactsList();
	sortContactsList(sorted_contacts, choice);
	cout << endl;
	for (int i = 0; i < contacts_count; i++)
	{
		cout << "|CONTACT no " << i + 1 << " |" << endl << endl;
		sorted_contacts[i].printContact();
		cout << endl;
	}
	delete[] sorted_contacts;
}
void ContactsBook::sortContactsList(Contact* copied_contacts_list, string choice)
{
	if (choice == "FIRST")
	{
		for (int i = 1; i < contacts_count; i++)
		{
			Contact temporary;
			temporary.copyConstructor(copied_contacts_list[i]);
			int index = i - 1;
			while (index >= 0 && toupper(copied_contacts_list[index].get_first_name()[0]) > toupper(temporary.get_first_name()[0]))
			{
				copied_contacts_list[index + 1].copyConstructor(copied_contacts_list[index]);
				index = index - 1;
			}
			copied_contacts_list[index + 1].copyConstructor(temporary);
		}
	}
	else if (choice == "LAST")
	{
		for (int i = 1; i < contacts_count; i++)
		{
			Contact temporary;
			temporary.copyConstructor(copied_contacts_list[i]);
			int index = i - 1;
			while (index >= 0 && toupper(copied_contacts_list[index].get_last_name()[0]) > toupper(temporary.get_last_name()[0]))
			{
				copied_contacts_list[index + 1].copyConstructor(copied_contacts_list[index]);
				index = index - 1;
			}
			copied_contacts_list[index + 1].copyConstructor(temporary);
		}
	}
}
//SEARCH THE CONTACT DEPENDING TO FIRST NAME AND LAST NAME
Contact* ContactsBook::searchContact(string first_name, string last_name)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if ((contacts_list[i].get_first_name() == first_name) && (contacts_list[i].get_last_name() == last_name))
		{
			return contacts_list[i].copy_contact();
		}
	}
	cout << endl << "==|| NO CONTACT FOUND WITH THESE CREDENTIALS  ||==" << endl << endl;
	return nullptr;
}
//SEARCH CONTACT DEPENDING ON PHONE NUMBER
Contact* ContactsBook::searchContact(string phone)
{
	for (int i = 0; i < contacts_count; i++)
	{
		if ((contacts_list[i].get_mobile_number() == phone))
		{
			return contacts_list[i].copy_contact();
		}
	}
	cout << endl << "WRONG INFORMATION NOT CONTACT FOUND!!" << endl << endl;
	return nullptr;
}
// This function searches for a Contact in the ContactsBook based on the provided Address.
// It iterates over the list of contacts in the ContactsBook.
// For each contact, it compares the contact's address with the provided address.
// If a match is found, it creates a copy of the contact and returns it.
// If no match is found after checking all contacts, it prints a message and returns nullptr.
Contact* ContactsBook::searchContact(const Address& address)
{
	for (int i = 0; i < contacts_count; i++)
	{
		// Dereference the address pointer of the current contact and compare it with the provided address.
		if (*(contacts_list[i].getAddress()) == address)
		{
			return contacts_list[i].copy_contact();
		}
	}
	cout << endl << "WRONG INFORMATION NOT CONTACT FOUND!!" << endl << endl;
	return nullptr;
}
Contact* ContactsBook::copyContactsList()
{
	Contact* copied_contacts_list = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; i++)
	{
		//COPYING ORIGINAL ARRAY DATA TO NEW DYNAMIC ARRAY
		copied_contacts_list[i] = contacts_list[i];
	}
	return copied_contacts_list;
}
void ContactsBook::mergeDuplicates()
{
	int Mergecount = 0;
	for (int i = 0; i < contacts_count - 1; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if ((contacts_list[i]) == (contacts_list[j]))
			{
				for (int k = j; k < contacts_count - 1; k++)//SHIFTING THE ARRAY SO THAT THE DUPLICATE WILL BE REMOVED AND CONTACTS NEXT TO IT MOVE ON PREVIOUS SPACE 
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				// Decrement the contacts_count
				contacts_count--;
				Mergecount++;
				// Decrement j to recheck the replaced contact
				j--;
			}
		}
	}
	cout << "<<<<RESULT>>>>" << endl << endl;
	if (Mergecount != 0)
	{
		cout << "CONTACTS MERGED SUCCESFULLY : " << Mergecount << endl;
	}
	else
	{
		cout << "==|| NO DUPLICATE CONTACTS FOUND ||==" << endl << endl;
	}
}
void ContactsBook::loadFromFile(string file_name)
{
	ifstream readfile(file_name);
	if (!(readfile.is_open()))
	{
		cout << "==|| ERROR WHILE OPENING THE FILE " << file_name << " ||==" << endl;
	}
	else
	{
		cout << "==|| FILE " << file_name << " OPENED SUCCESSFULLY AND DATA HAS BEEN READED ||==" << endl << endl;
		int loaded_contacts_count;
		readfile >> loaded_contacts_count;
		this->contacts_list = new Contact[loaded_contacts_count];
		this->size_of_contacts = loaded_contacts_count;
		this->contacts_count = 0;
		readfile.ignore();
		for (int i = 0; i < loaded_contacts_count; ++i)
		{
			string whole_Line;
			getline(readfile, whole_Line);
			string data_contact[4];
			for (int i = 0; i < 4; i++)
			{
				int position = whole_Line.find(",");
				data_contact[i] = whole_Line.substr(0, position);
				whole_Line.erase(0, position + 1);
			}

			getline(readfile, whole_Line);
			string data_address[4];
			for (int i = 0; i < 4; i++)
			{
				int position = whole_Line.find(",");
				data_address[i] = whole_Line.substr(0, position);
				whole_Line.erase(0, position + 1);
			}
			Address temporary(data_address[0], data_address[1], data_address[2], data_address[3]);
			Contact contact;
			contact.set_first_name(data_contact[0]);
			contact.set_last_name(data_contact[1]);
			contact.set_mobile_number(data_contact[2]);
			contact.set_email_address(data_contact[3]);
			contact.setAddress(&temporary);
			this->addContact(contact);
		}
		readfile.close();
	}
}
void ContactsBook::saveToFile(string file_name)
{
	ofstream writefile(file_name, ios::trunc);
	if (!(writefile.is_open()))
	{
		cout << "==|| FILE DOES NOT OPEN " << file_name << " ||==" << endl;
	}
	else
	{
		cout << "==|| DATA STORED SUCCESSFULLY ON " << file_name << " ||==" << endl;
		for (int i = 0; i < contacts_count; ++i)
		{
			//WORKS ONLY 1st TIME
			if (i == 0)
			{
				writefile << contacts_count << endl;
			}
			writefile << contacts_list[i].get_first_name() << "," << contacts_list[i].get_last_name() << ","
				<< contacts_list[i].get_mobile_number() << "," << contacts_list[i].get_email_address() << endl;
			writefile << contacts_list[i].addressForFile() << endl;
		}
		writefile.close();
	}
}
//OPERATOR OVERLOADING OF CONTACTT BOOK WITH INT AS WE NEED TO SET THE ARRAY MEMBER AFTER CONSTRUCTOR
ContactsBook ContactsBook::operator=(int size)
{
	this->size_of_contacts = size;
	contacts_list = new Contact[size];
	return size;
}
//FOR RETURNING THE CURRENT NUMBER OF CONTACTS
int ContactsBook::getContactCount()
{
	return contacts_count;
}
//TO PRINTING ALL CONTACTS OF A BOOK 
void ContactsBook::printContactsUnsortedFunction()
{
	for (int i = 0; i < contacts_count; i++)
	{
		cout << " CONTACT no " << i + 1 << "  " << endl;
		contacts_list[i].printContact();
		cout << endl;
	}
}
void ContactsBook::findEntireContact()
{
	int choice = 0;
	do
	{
		cout << "1.SEARCH WITH FRIST AND LAST NAME " << endl;
		cout << "2.SEARCH WITH PHONE NUMBER " << endl;
		cout << "3.SEARCH WITH ADDRESS " << endl;
		cout << "4.END SEARCH " << endl;
		cout << "CHOICE : ";
		while (!(cin >> choice) || choice < 1 || choice > 4)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INVALID CHOICE !" << endl;
			cout << "TRY AGAIN : ";
		};
		cin.ignore();
		cout << endl << endl;
		if (choice == 1)
		{
			cout << "\t SEARCH WITH FIRST & LAST NAME " << endl;
			string first, last;
			cout << "ENTER FIRST NAME : ";
			getline(cin, first);
			cout << "ENTER LAST NAME : ";
			getline(cin, last);
			Contact* temp = (this->searchContact(first, last));
			if (temp != nullptr)
			{
				cout << endl << " CONTACT FOUNDED  " << endl << endl;
				temp->printContact();
			}
		}
		else if (choice == 2)
		{
			cout << "\t SEARCH WITH PHONE NUMBER " << endl;
			string phone;
			cout << "ENTER A PHONE NUMBER : ";
			getline(cin, phone);
			Contact* temp = (this->searchContact(phone));
			if (temp != nullptr)
			{
				cout << endl << "| CONTACT FOUND |" << endl << endl;
				temp->printContact();
			}
		}
		else if (choice == 3)
		{
			cout << "\t SEARCH WITH ADDRESS " << endl;
			string house, street, city, country;
			cout << "ENTER HOUSE NUMBER : ";
			getline(cin, house);
			cout << "ENTER STREET NUMBER : ";
			getline(cin, street);
			cout << "ENTER CITY : ";
			getline(cin, city);
			cout << "ENTER COUNTRY : ";
			getline(cin, country);
			Address for_check(house, street, city, country);
			Contact* temp = (this->searchContact(for_check));
			if (temp != nullptr)
			{
				cout << endl << " CONTACT FOUNDED " << endl << endl;
				temp->printContact();
			}
		}
		else if (choice == 4)
		{
			break;
		}
	} while (choice != 4);
}
void ContactsBook::printContactsSortedFunction()
{
	int choice;
	cout << "1.SORT BY FIRST NAME " << endl;
	cout << "2.SORT BY LAST NAME " << endl;
	cout << "CHOICE : ";
	while (!(cin >> choice) || choice < 1 || choice>2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "INVALID CHOICE !" << endl;
		cout << "TRY AGAIN : ";
	};
	cin.ignore();
	cout << endl;
	if (choice == 1)
	{
		cout << "\t SORTED BY FIRST NAME " << endl << endl;
		this->printContactsSorted("FIRST");
	}
	else if (choice == 2)
	{
		cout << "\tSORTED BY LAST NAME " << endl << endl;
		this->printContactsSorted("LAST");
	}
}