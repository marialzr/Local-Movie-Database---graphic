#include "HTMLWatchlist.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void HTMLWatchlist::writeToFile()
{
	ofstream f(this->filename);
	//ofstream f("");
	if (!f.is_open())
        return;

	f << "<!DOCTYPE html>\n";
		f << "<html>\n";
		f << "<head>\n";
		f << "<title>Watchlist</title>\n";
		f << "</head>\n";
		f << "<body>\n";
		f << "<table border = ""1"">\n";
		f << "<tr>\n";
		f << "<td>Title</td>\n";
		f << "<td>Genre</td>\n";
		f << "<td>Year</td>\n";
		f << "<td>No likes</td>\n";
		f << "<td>Youtube link</td>\n";
		f << "</tr>\n";
		
		
		for (auto s : this->movies)
		{
			f << "<tr>\n";
			f << "<td>" + s.getTitle() + "</td>\n";
			f << "<td>" + s.getGenre() + "</td>\n";
			f << "<td>" + to_string(s.getNrLikes()) + "</td>\n";
			f << "<td>" + to_string(s.getYear()) + "</td>\n";
			f << "<td><a href =" + s.getTrailer() + ">Link</a></.td>\n";
			f << "</tr>\n";
		}
		
		f << "</table>\n";
		f << "</body>\n";
		f << "</html>\n";
	f.close();
}

void HTMLWatchlist::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\""; // if the path contains spaces, we must put it inside quotations
											   //ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\OpenOffice 4\\program\\scalc.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
