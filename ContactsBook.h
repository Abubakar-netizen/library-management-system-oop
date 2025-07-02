#pragma once
#include "Address.h"
#include "Contact.h"
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif
using namespace std;
class ContactsBook
{
private:
	Contact* contacts_list;
	int size_of_contacts;
	int contacts_count;
public:
	ContactsBook();
	ContactsBook(int size_of_list);
	void addContact(const Contact& contact);
	int totalContacts();
	Contact* searchContact(string first_name, string last_name);
	Contact* searchContact(string phone);
	Contact* searchContact(const Address& address);
	void mergeDuplicates();
	void loadFromFile(string file_name);
	void saveToFile(string file_name);
	int getContactCount();
	ContactsBook operator=(int size);
	void printContactsUnsortedFunction();
	void printContactsSortedFunction();
	void findEntireContact();
	Contact* copyContactsList();
private:
	bool full();
	void resizeList();
	void printContactsSorted(string choice);
	void sortContactsList(Contact* contacts_list, string choice);
};