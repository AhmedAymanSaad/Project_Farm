#pragma once
#include "Media.h"

class TVShow : public Media
{
private:
	string genre;
	float rating;
	int seasons;
	int episodes;
	string year;

public:
	TVShow();
	TVShow(string name);
	void setYear(string);
	void setRating(float);
	void setGenre(string);
	string getYear();
	string getGenre();
	float getRating();

};

