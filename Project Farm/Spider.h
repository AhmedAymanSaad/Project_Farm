#pragma once
#include <urlmon.h>
#include <fstream>
#include <iostream>
#include "WebPage.h"
using namespace std;

class Library;
class HTMLHandler;
class botManager;

class Spider
{
private:
	botManager* ParentBot;
	WebPage* webPage;
	Library* pLibrary;
	Media* CurrMedia;
	HTMLHandler* pHTMLhandler;

public:
	Spider();
	void setHandler(HTMLHandler*);
	void setLibrary(Library*);
	void setParentBot(botManager*);
	void execute();
};

