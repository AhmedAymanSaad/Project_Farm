#include "Media.h"

Media::Media(string name) {
	this->name = name;
}

Media::Media() {
	this->name = "NULL";
}

string Media::getName() {
	return name;
}

Media::~Media() {

}