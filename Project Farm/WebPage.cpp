#include "WebPage.h"
#include "Spider.h"

WebPage::WebPage(Media* pMed) {
	CurrMedia = pMed;
	found = true;
}

void WebPage::setfound(bool b) {
	found = b;
}

bool WebPage::getfound() {
	return found;
}

void WebPage::setWebPageData() {
	char* webAddress = (char*)WebAddress.c_str();
	char szFileName[80] = "namesresult.html";
	string data;
	HRESULT hr = URLDownloadToFile(NULL, webAddress, szFileName, 0, NULL);
	ofstream fout;
	if (hr == S_OK)
	{
		// Open the file and print it to the console window
		// Since the file was just written, it should still be in cache somewhere.
		ifstream fin(szFileName);
		char szBuff[160000];
		fout.open("links.txt", ios::out);
		if (fout.is_open()) {
			while (fin.getline(szBuff, 160000))
			{
				fout << szBuff << "\n";
			}
			fout.close();
		}
		ifstream fin2(szFileName);
		while (fin2.getline(szBuff, 160000))
		{
			fout << szBuff << "\n";
			data = data + szBuff + "\n";
		}
	}
	pageData = data;

}

string WebPage::getPageData() {
	return pageData;
}

Media* WebPage::getCurrMedia() {
	return CurrMedia;
}