#include "CSVWatchlist.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void CSVWatchlist::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
        return;

	for (auto s : this->movies)
		f <<s;

	f.close();
}

void CSVWatchlist::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "c:\\Program Files\\Notepad++\\notepad++.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
