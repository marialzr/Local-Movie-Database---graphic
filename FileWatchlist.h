#pragma once
#include "Watchlist.h"
class FileWatchList : public WatchList
{
protected:
	std::string filename;

public:
	FileWatchList();
	virtual ~FileWatchList() {}

	void setFilename(const std::string& filename);
	virtual void writeToFile() = 0;
	virtual void displayWatchlist() const = 0;
};
