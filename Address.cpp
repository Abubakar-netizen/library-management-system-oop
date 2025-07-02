#include "Address.h"
using namespace std;

Address::Address(string house, string street, string city, string country) :
	house(house), street(street), city(city), country(country) {}

string Address::get_house() const
{
	return house;
}

void Address::set_house(const string& new_house)
{
	house = new_house;
}

string Address::get_street() const
{
	return street;
}

void Address::set_street(const string& new_street)
{
	street = new_street;
}

string Address::get_city() const
{
	return city;
}

void Address::set_city(const string& new_city)
{
	city = new_city;
}

string Address::get_country() const
{
	return country;
}

void Address::set_country(const string& new_country)
{
	country = new_country;
}

bool Address::equals(const Address& address) const
{
	if ((this->house == address.house) && (this->street == address.street) && (this->city == address.city) && (this->country == address.country))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Address::print_address() const
{
	cout << "House: " << house << "\n"
		<< "Street: " << street << "\n"
		<< "City: " << city << "\n"
		<< "Country: " << country << "\n";
}

Address Address::copy_address()
{
	return Address(house, street, city, country);
}

bool Address::operator==(const Address& address)
{
	if ((this->house == address.house) && (this->street == address.street) && (this->city == address.city) && (this->country == address.country)) {
		return true;
	}
	else {
		return false;
	}
}

Address& Address::operator=(Address address)
{
	this->house = address.house;
	this->street = address.street;
	this->city = address.city;
	this->country = address.country;
	return *(this);
}

void Address::setAddress()
{
	cin.ignore();
	cout << "ENTER HOUSE NUMBER : ";
	getline(cin, this->house);
	cout << "ENTER STREET NUMBER : ";
	getline(cin, this->street);
	cout << "ENTER CITY : ";
	getline(cin, this->city);
	cout << "ENTER COUNTRY : ";
	getline(cin, this->country);
}