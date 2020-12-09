#include "IMDBWebPage.h"

IMDBWebPage::IMDBWebPage(Media* pMed, string title) : WebPage(pMed) {
	WebAddress = "https://www.imdb.com/title/" + title;
	WebPageType = IMDB_PAGE;
	if (title.find_first_of("0123456789") == string::npos) {
		found = false;
	}
}