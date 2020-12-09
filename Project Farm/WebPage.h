#pragma once
#include <string>
using namespace std;

#include "Defs.h"
#include "Media.h"

class WebPage
{
protected:
	string pageData;
	string WebAddress;
	WEBPAGE_TYPE WebPageType;
	Media* CurrMedia;
	bool found;
	
public:
	WebPage(Media*);
	void setWebPageData();
	string getPageData();
	Media* getCurrMedia();
	void setfound(bool);
	bool getfound();
};

