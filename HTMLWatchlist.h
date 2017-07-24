#pragma once
#include "FileWatchlist.h"
#include <string>

class HTMLWatchlist : public FileWatchList
{
public:
	/*
	Writes the playlist to file.
	Throws: FileException - if it cannot write.
	*/
	void writeToFile() override;

	/*
	Displays the playlist using Microsof Excel.
	*/
	void displayWatchlist() const override;
};
