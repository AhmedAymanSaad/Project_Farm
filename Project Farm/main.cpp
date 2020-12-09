#include "botManager.h"

int main() {
	cout << "Enter path: " << endl;
	string path;
	getline(cin, path);
	cout << "Enter 1 for TV_SHOW mode OR 2 for MOVIE mode: " << endl;
	int m;
	cin >> m;
	botManager FarmBot(path,m);
	FarmBot.execute();
	return 0;
}

/*
===TODO:
1) Seperate mode for movies and TV Shows
2) Get the content rating
3) Fix the year for TV mini-series
4) Make a class for genre and inherit each genre type
5) 
*/