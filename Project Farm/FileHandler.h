#pragma once
#include <string>
using namespace std;

#include "Defs.h"

class Library;
class botManager;

class FileHandler
{
private:
	botManager* ParentBot;
	string path;
	Library* pLibrary;
	MEDIA_MODE MediaMode;
	
public:
	void setParentBot(botManager*);
	void setPath(string path);
	void execute();
	void setLibrary(Library*);
	void FillLibrary();
	void list_dir(const char*);
	void list_subdir(const char*);
	void nlist_sub(const char*,int&);

};

