#include "TVShow.h"

TVShow::TVShow(string name) : Media(name) {
	genre = "";
	rating = 0;
	year = "";
}

TVShow::TVShow() {
	genre = "";
	rating = 0;
	year = "";
}

void TVShow::setYear(string y) {
	year = y;
}

void TVShow::setRating(float r) {
	rating = r;
}

void TVShow::setGenre(string g) {
	genre = g;
}

string TVShow::getYear() {
	return year;
}

string TVShow::getGenre() {
	return genre;
}

float TVShow::getRating() {
	return rating;
}