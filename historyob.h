#pragma once
#include <string>
#include <ctime>
using namespace std;
class HistoryObject
{
private:
	string b;
	string searchString;
	time_t searchTime;

public:
	HistoryObject(const string& searchStr, const string&d) : searchString(searchStr), b(d), searchTime(time(nullptr)) {}

	HistoryObject(const string& searchStr) : searchString(searchStr), searchTime(time(nullptr)) {}

	const string& G_Search_String() const { return searchString; }

	time_t G_Search_Time() const { return searchTime; }
};