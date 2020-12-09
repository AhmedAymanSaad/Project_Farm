#pragma once
#include <string>
using namespace std;

class Media
{
private:
	string name;

public:
	Media();
	Media(string name);
	string getName();
	virtual ~Media();

};

