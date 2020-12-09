#include "botManager.h"
#include "FileHandler.h"
#include "HTMLHandler.h"
#include "Library.h"
#include "Spider.h"
#include "Media.h"

botManager::botManager(string path,int m) {
	setMediaMode(m);
	fileHandler.setPath(path);
	fileHandler.setLibrary(&RottenPotatoes);
	fileHandler.setParentBot(this);
	PeterParker.setHandler(&HTMLhandler);
	PeterParker.setLibrary(&RottenPotatoes);
	PeterParker.setParentBot(this);
	OutHandle.setLibrary(&RottenPotatoes);
}

void botManager::execute() {
	fileHandler.execute();
	PeterParker.execute();
	OutHandle.execute();
}

MEDIA_MODE botManager::getMediaMode() {
	return MediaMode;
}

void botManager::setMediaMode(int m) {
	if (m == 2) {
		MediaMode = MOVIE;
	}
	else {
		MediaMode = TV_SHOW;
	}
}