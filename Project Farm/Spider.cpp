#include "Spider.h"
#include "HTMLHandler.h"
#include "Library.h"
#include "botManager.h"
#include "WebPage.h"
#include "GSWebPage.h"
#include "IMDBWebPage.h"

Spider::Spider() {
	webPage = nullptr;
	CurrMedia = nullptr;
	pHTMLhandler = nullptr;
	pLibrary = nullptr;
}

void Spider::setHandler(HTMLHandler* pHandler) {
	pHTMLhandler = pHandler;
}

void Spider::setLibrary(Library* pLibrary) {
	this->pLibrary = pLibrary;
}

void Spider::setParentBot(botManager* pBot) {
	ParentBot = pBot;
}

void Spider::execute() {
	Queue<Media* >* CurrLib = nullptr;
	CurrLib = pLibrary->getQueue(TV_SHOW);
	Media* pMed;
	GSWebPage* pGSWP;
	IMDBWebPage* pIMDBWP;
	int count = 0;
	int c = 0;
	CurrLib->toArray(count);
	while (CurrLib->dequeue(pMed)) {
		pGSWP = new GSWebPage(pMed);
		pGSWP->setWebPageData();
		pIMDBWP = pHTMLhandler->getIMDBWebPage(pGSWP);
		pIMDBWP->setWebPageData();
		pHTMLhandler->setProperties(pIMDBWP);
		pLibrary->getFinMedia()->enqueue(pMed);
		c++;
		cout << "Done: " << c << " out of " << count << endl;
	}
}

