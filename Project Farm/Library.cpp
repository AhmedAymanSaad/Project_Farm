#include "Library.h"

Library::Library() {
	TVShows = new Queue<Media*>;
	Movies = new Queue<Media*>;
	FinMedia = new Queue<Media*>;
}

bool Library::enqueue(TVShow* pMedia) {
	return TVShows->enqueue(pMedia);
}

Queue<Media*>* Library::getQueue(MEDIA_MODE MediaMode) {
	if (MediaMode == TV_SHOW) {
		return getTVShows();
	}
	if (MediaMode == MOVIE) {
		return getMovies();
	}
}

Queue<Media*>* Library::getTVShows() {
	return TVShows;
}

Queue<Media*>* Library::getMovies() {
	return Movies;
}

Queue<Media*>* Library::getFinMedia() {
	return FinMedia;
}