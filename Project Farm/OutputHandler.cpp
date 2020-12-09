#include "OutputHandler.h"
#include "Library.h"
#include <iostream>
#include <fstream>
#include "C:\Users\ahmed\Desktop\old\MY PROJECTS\Project Farm\myProj\libxl-3.9.1.4\include_cpp\libxl.h"
#include "Queue.h"
using namespace libxl;
using namespace std;

void OutputHandler::setLibrary(Library* plib) {
	pLibrary = plib;
}

void OutputHandler::execute() {
	Queue<Media*>* FinLib = pLibrary->getFinMedia();
	Book* book = xlCreateBook();
	if (book)
	{
		Sheet* sheet = book->addSheet("Sheet1");
		if (sheet)
		{
			/*sheet->writeStr(2, 1, "Hello, World !");
			sheet->writeNum(3, 1, 1000.5);*/
			int row = 2;
			Media* pMed;
			while (FinLib->dequeue(pMed)) {
				TVShow* pTVS = dynamic_cast<TVShow*>(pMed);
				sheet->writeStr(row, 0, (char*)pTVS->getName().c_str());
				sheet->writeStr(row, 1, (char*)pTVS->getYear().c_str());
				sheet->writeStr(row, 2, (char*)pTVS->getGenre().c_str());
				sheet->writeNum(row, 3, pTVS->getRating());
				row++;
			}
		}
		book->save("RottenPotatoes.xls");
		book->release();
	}
}