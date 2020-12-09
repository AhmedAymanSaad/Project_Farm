#include "FileHandler.h"
#include "botManager.h"
#include <direct.h>
#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>

void FileHandler::setParentBot(botManager* bm) {
	ParentBot = bm;
}

void FileHandler::setPath(string path) {
	this->path = path;
}

void FileHandler::setLibrary(Library* pLib) {
	pLibrary = pLib;
}

void FileHandler::FillLibrary() {
	if (ParentBot->getMediaMode() == TV_SHOW) {
		list_dir((char*)path.c_str());
	}
	if (ParentBot->getMediaMode() == MOVIE) {
		list_subdir((char*)path.c_str());
	}
}

void FileHandler::execute() {
	FillLibrary();
}

void FileHandler::list_dir(const char* path) {
	struct dirent* entry;
	DIR* dir = opendir(path);

	if (dir == NULL) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != 46 )
			if (true) {
				TVShow* pTVS = nullptr;
				pTVS = new TVShow(entry->d_name);
				pLibrary->enqueue(pTVS);
			}
	}
	closedir(dir);
}

void FileHandler::nlist_sub(const char* path, int& c) {
	struct dirent* entry;
	DIR* dir = opendir(path);

	if (dir == NULL) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != 46 && entry->d_type == DT_DIR) {
			c++;
		}
	}
	closedir(dir);
}

void FileHandler::list_subdir(const char* path) {
	struct dirent* entry;
	DIR* dir = opendir(path);
	string subPath = path;
	string temp;
	int c = 0;

	if (dir == NULL) {
		return;
	}
	while ((entry = readdir(dir)) != NULL) {
		if (entry->d_name[0] != 46 && entry->d_type == DT_DIR)
		{
			subPath = path;
			temp = entry->d_name;
			subPath = subPath + "//" + temp;
			nlist_sub((char*)subPath.c_str(), c);
			if (c == 0) {
				if (true) {
					TVShow* pTVS = nullptr;
					pTVS = new TVShow(entry->d_name);
					pLibrary->enqueue(pTVS);
				}
			}
			else {
				list_subdir((char*)subPath.c_str());
			}
			c = 0;
		}
	}
	closedir(dir);
}