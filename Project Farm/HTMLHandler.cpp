#include "HTMLHandler.h"
#include "IMDBWebPage.h"
#include "GSWebPage.h"
#include <iostream>
#include "gumbo-parser-master\src\gumbo.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "TVShow.h"


IMDBWebPage* HTMLHandler::getIMDBWebPage(GSWebPage* pGSWB) {
	string data = pGSWB->getPageData();
	size_t num = string::npos;
	num = data.find("imdb.com/title/");
	bool found = true;
	num = num + 15;
	string ret;
	while (data[num]!=34)
	{
		ret += data[num];
		num++;
	}

	IMDBWebPage* pIMDBWP = new IMDBWebPage(pGSWB->getCurrMedia(), ret);
	return pIMDBWP;
}

void HTMLHandler::setProperties(IMDBWebPage* pIMDBWP) {
	setRatings(pIMDBWP); //temp
}

static std::string cleantext(GumboNode* node) {
	if (node->type == GUMBO_NODE_TEXT) {
		return std::string(node->v.text.text);
	}
	else if (node->type == GUMBO_NODE_ELEMENT &&
		node->v.element.tag != GUMBO_TAG_SCRIPT &&
		node->v.element.tag != GUMBO_TAG_STYLE) {
		std::string contents = "";
		GumboVector* children = &node->v.element.children;
		for (unsigned int i = 0; i < children->length; ++i) {
			const std::string text = cleantext((GumboNode*)children->data[i]);
			if (i != 0 && !text.empty()) {
				contents.append(" ");
			}
			contents.append(text);
		}
		return contents;
	}
	else {
		return "";
	}
}


string clean_text(string html) {
	/*string ret;
	bool script = false;
	int num = 0;
	while (checkend(data, num)) {
		while (data[num] = '<') {
			if ((data[num] = '<') && (data[num + 1] = 's') && (data[num + 2] = 'c') && (data[num + 3] = 'r') && (data[num + 4] = 'i') && (data[num + 5] = 'p') && (data[num + 6] = 't') && (data[num + 7] = '>')) {
				script = true;
			}
			while (data[num] != '>') {
				num++;
			}
			num++;
		}
		if (script=false) {
			ret = ret + data[num];
		}
		num++;
	}

	return ret;*/
	
	while (html.find("<") != std::string::npos)
	{
		auto startpos = html.find("<");
		auto endpos = html.find(">") + 1;

		if (endpos != std::string::npos)
		{
			html.erase(startpos, endpos - startpos);
		}
	}

	return html;

}

void HTMLHandler::setRatings(IMDBWebPage* pIMDBWP) {
	if (pIMDBWP->getfound() == false) {
		return;
	}
	TVShow* pTVS = dynamic_cast<TVShow*>(pIMDBWP->getCurrMedia());
	string pageData = pIMDBWP->getPageData();
	char* parsedString = (char*)pageData.c_str();
	GumboOutput* output = gumbo_parse(parsedString);
	pageData = cleantext(output->root);
	size_t num = 0;
	num = pageData.find("(");
	while (pageData[num] < 48 || pageData[num]>57) {
		num++;
	}
	string year;
	while (pageData[num] != 41) {
		year = year + pageData[num];
		num++;
	}
	if (year.size() > 4) {
		year[4] = 45;
		year.erase(5, 2);
	}
	pTVS->setYear(year);
	num = pageData.find("Quotes  Alternate Versions  Connections  Soundtracks      ");
	num = num + 58;
	string rating;
	for (int i = 0;i < 3;i++) {
		rating = rating + pageData[num];
		num++;
	}
	if (rating.find_first_of("0123456789") == string::npos) {
		pTVS->setRating(0);
	}
	else {
		pTVS->setRating(stof(rating));
	}
	pageData.erase(0, num);
	num = pageData.find("| ");
	pageData.erase(0, num);
	num = 2;
	while (pageData[num+1] == 32) {
		num++;
	}
	if (pageData[num+1] > 47 && pageData[num+1] < 58) {
		pageData.erase(0, num);
		num = pageData.find("| ");
		num = num + 2;
	}
	string genre;
	while (pageData[num] != 124) {
		while ((pageData[num] != 10) && (pageData[num] != 124)) {
			genre = genre + pageData[num];
			num++;
		}
		if ((pageData[num] != 124)) {
			num = num + 2;
		}
	}
	pTVS->setGenre(genre);

}