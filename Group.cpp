#include"Group.h"
#include"fstream"

group::group()
{

}
group::group(int size)
{
	this->size = size;
	Contact_arrptr = new Contact[size];
	members_count = 0;
}
bool group::full()
{
	/*
	* Return true if list is full, false otherwise
	*/
	return members_count == size;
}
void group::LoadFile(std::string file_name)
{
	ifstream input_file(file_name);
	if (!input_file.is_open())
	{
		cout << "Error: Unable to open file " << file_name << endl;
	}

	int contacts_count;
	input_file >> contacts_count;

	// Resize the contact array to accommodate the contacts being loaded
	while (members_count + contacts_count > size) 
	{
		resize_list();
	}

	// Loop through each contact in the file and add it to the group
	for (int i = 0; i < contacts_count; ++i) 
	{
		string first_name, last_name, mobile_number, email_address;
		string house, street, city, country;

		input_file >> first_name >> last_name >> mobile_number >> email_address >> house >> street >> city >> country;

		// Create a new Contact object and add it to the group
		Address* address = new Address(house, street, city, country);
		Contact contact(first_name, last_name, mobile_number, email_address, address);
		addContact(contact);
	}

	// Close the file
	input_file.close();
}

void group::resize_list()
{

	int new_size = size * 2;
	Contact* new_list = new Contact[new_size];

	for (int i = 0; i < size; ++i)
	{
		new_list[i] = Contact_arrptr[i];
	}

	delete[] Contact_arrptr;

	Contact_arrptr = new_list;

	size = new_size;
}

void group::AddContact(const Contact& contact)
{
	if (full())
	{
		resize_list();
	}

	Contact_arrptr[members_count].set_first_name(contact.get_first_name());
	Contact_arrptr[members_count].set_last_name(contact.get_last_name());
	Contact_arrptr[members_count].set_mobile_number(contact.get_mobile_number());
	Contact_arrptr[members_count].set_email_address(contact.get_email_address());
	Contact_arrptr[members_count].setAddress(contact.getAddress());
	members_count++;
}

void group::DisplayContacts()
{
	if (members_count == 0)
	{
		cout << "No contacts to display in group.." << endl;
		return;
	}

	cout << "Contacts:" << endl;
	for (int i = 0; i < members_count; ++i)
	{
		cout << "Contact " << i + 1 << ":" << endl;
		Contact_arrptr[i].printContact();
		cout << endl;
	}
}
void group::SaveInFile(string file_name)
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in space separated format. On second line
	*	store address atributes in the same format
	*	first_name last_name mobile_number email_address
	*	housestreet city country
	*	Close the file
	*/
	ofstream output_file(file_name);
	if (!output_file.is_open())
	{
		cout << "Error: Unable to open file " << file_name << endl;
	}
	// Write contacts_count to the file
	output_file << members_count << endl;
	// Loop through contacts and write each contact's details to the file
	for (int i = 0; i < members_count; ++i)
	{
		output_file << Contact_arrptr[i].get_first_name() << " "
			<< Contact_arrptr[i].get_last_name() << " "
			<< Contact_arrptr[i].get_mobile_number() << " "
			<< Contact_arrptr[i].get_email_address() << endl;

		// Write address attributes in comma-separated format
		output_file << Contact_arrptr[i].getAddress()->get_house() << " "
			<< Contact_arrptr[i].getAddress()->get_street() << " "
			<< Contact_arrptr[i].getAddress()->get_city() << " "
			<< Contact_arrptr[i].getAddress()->get_country() << endl;
	}
	// Close the file
	output_file.close();
}