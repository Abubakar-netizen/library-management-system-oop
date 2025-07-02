#pragma once
#include <iostream>
#include <string>
using namespace std;

class Address {
private:
	string house;
	string street;
	string city;
	string country;

public:

	bool equals(const Address&)const;
	void print_address()const;
	Address copy_address();
	bool operator==(const Address&);
	Address& operator=(Address);

	string get_house() const;
	string get_street() const;
	string get_city() const;
	string get_country() const;
	void set_house(const string&);
	void set_street(const string&);
	void set_city(const string&);
	void set_country(const string&);
	void setAddress();

	Address(string house, string street, string city, string country);
	Address() {}
};