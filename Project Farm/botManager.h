#pragma once
#include <string>
using namespace std;

#include "botManager.h"
#include "FileHandler.h"
#include "HTMLHandler.h"
#include "Library.h"
#include "Spider.h"
#include "Defs.h"
#include "OutputHandler.h"

class botManager
{
private:
	FileHandler fileHandler;
	Spider PeterParker;
	Library RottenPotatoes;
	HTMLHandler HTMLhandler;
	MEDIA_MODE MediaMode;
	OutputHandler OutHandle;

public:
	botManager(string path,int);
	void execute();
	MEDIA_MODE getMediaMode();
	void setMediaMode(int);
};

