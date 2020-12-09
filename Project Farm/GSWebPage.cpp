#include "GSWebPage.h"

GSWebPage::GSWebPage(Media* pMed) : WebPage(pMed) {
	WebAddress = "https://www.google.com/search?q=" + CurrMedia->getName() + "+imdb";
	WebPageType = GOOGLE_SEARCH;
}
