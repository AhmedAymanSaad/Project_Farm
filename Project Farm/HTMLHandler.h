#pragma once
#include <fstream>
#include "WebPage.h"
#include "gumbo-parser-master\src\gumbo.h"

class IMDBWebPage;
class GSWebPage;

class HTMLHandler
{
private:
	WebPage* CurrWebPage;
	ifstream ifile;
	string* WebPageData;
	Media* CurrMedia;

public:
	IMDBWebPage* getIMDBWebPage(GSWebPage*);
	void setProperties(IMDBWebPage*);
	void setRatings(IMDBWebPage*);
};

