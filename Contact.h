#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

#include "Address.h"
using namespace std;


class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address* address;

public:
	bool equals(Contact contact);
	Contact* copy_contact();
	Contact copyConstructor(const Contact&);
	void printContact() const;
	string addressForFile() const;
	Contact operator =(Contact);
	bool operator ==(Contact);


	string get_first_name() const;
	string get_last_name() const;
	string get_mobile_number() const;
	string get_email_address() const;
	Address* getAddress() const;
	void set_first_name(const string&);
	void set_last_name(const string&);
	void set_mobile_number(const string&);
	void set_email_address(const string&);
	void setAddress(Address*);
	void setContact();

	Contact();
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address);
};
