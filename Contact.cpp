#include "Contact.h"

using namespace std;

Contact::Contact()
{
	first_name = " ";
	last_name = " ";
	mobile_number = " ";
	email_address = " ";
	address = nullptr;
}

Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address* address) :
	first_name(first_name), last_name(last_name), mobile_number(mobile_number), email_address(email_address), address(address) {}

string Contact::get_first_name() const
{
	return first_name;
}

void Contact::set_first_name(const string& new_first_name)
{
	first_name = new_first_name;
}

string Contact::get_last_name() const
{
	return last_name;
}

void Contact::set_last_name(const string& new_last_name)
{
	last_name = new_last_name;
}

string Contact::get_mobile_number() const
{
	return mobile_number;
}

void Contact::set_mobile_number(const string& new_mobile_number)
{
	if (new_mobile_number.size() == 11)
	{
		mobile_number = new_mobile_number;
	}
}

string Contact::get_email_address() const
{
	return email_address;
}

void Contact::set_email_address(const string& new_email_address)
{
	email_address = new_email_address;
}

Address* Contact::getAddress() const
{
	return address;
}

void Contact::setAddress(Address* new_address)
{
	address = new_address;
}

bool Contact::equals(Contact contact)
{
	if (first_name == contact.first_name &&
		last_name == contact.last_name &&
		mobile_number == contact.mobile_number &&
		email_address == contact.email_address &&
		(address ? address->equals(*contact.address) : !contact.address))
		return true;
	else
		return false;// Compare address if not nullptr
}

Contact* Contact::copy_contact()
{
	Contact* temporary = new Contact(this->first_name, this->last_name, this->mobile_number, this->email_address, nullptr);
	if (this->address != nullptr)
	{
		temporary->address = new Address(*this->address);
	}
	return temporary;
}

Contact Contact::copyConstructor(const Contact& contact)
{
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->email_address = contact.email_address;
	this->mobile_number = contact.mobile_number;
	this->address = new Address(*(contact.address));
	return *this;
}

Contact Contact::operator=(Contact contact)
{
	if (this != &contact) {
		this->first_name = contact.first_name;
		this->last_name = contact.last_name;
		this->email_address = contact.email_address;
		this->mobile_number = contact.mobile_number;
		if (this->address != nullptr)
		{
			delete this->address;
		}
		if (contact.address != nullptr)
		{
			this->address = new Address(*(contact.address));
		}
		else
		{
			this->address = nullptr;
		}
	}
	return *this;
}
// EQUAL OPERTOR -> OPERATOR OVERLOADING
bool Contact::operator==(Contact contact) {
	if ((this->first_name == contact.first_name) && (this->last_name == contact.last_name) &&
		(this->mobile_number == contact.mobile_number) && (this->email_address == contact.email_address) &&
		(*(this->address) == *(contact.address)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Contact::printContact() const
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Mobile Number: " << mobile_number << std::endl;
	std::cout << "Email Address: " << email_address << std::endl;
	address->print_address();
}

string Contact::addressForFile() const
{
	return address->get_house() + "," + address->get_street() + "," + address->get_city() + "," + address->get_country();
}
void Contact::setContact()
{
	string first = "", last = "", email = "", mobile = "";

	cout << "ENTER FIRST NAME : ";
	getline(cin, first);
	set_first_name(first);
	cout << "ENTER LAST NAME : ";
	getline(cin, last);
	set_last_name(last);
	cout << "ENTER MOBILE NUMBER [11 digits limit] : ";
	getline(cin, mobile);
	set_mobile_number(mobile);
	cout << "ENTER EMAIL ADDRESS : ";
	getline(cin, email);
	set_email_address(email);
}