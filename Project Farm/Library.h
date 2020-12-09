#pragma once
#include "Queue.h"
#include "TVShow.h"
#include "Movie.h"
#include "Defs.h"

class Library
{
private:
	Queue<Media*>* TVShows;
	Queue<Media*>* Movies;
	Queue<Media*>* FinMedia;

public:
	Library();
	bool enqueue(TVShow*);
	Queue<Media*>* getQueue(MEDIA_MODE);
	Queue<Media*>* getTVShows();
	Queue<Media*>* getMovies();
	Queue<Media*>* getFinMedia();
};

