#pragma once

class Library;

class OutputHandler
{
private:
	Library* pLibrary;

public:
	void setLibrary(Library*);
	void execute();


};

