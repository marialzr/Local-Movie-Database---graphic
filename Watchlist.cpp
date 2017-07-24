#include "Watchlist.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

WatchList::WatchList()
{
	this->current = 0;
}

void WatchList::add(const Film& f)
{
	this->movies.push_back(f);
}

void WatchList::remove(const std::string& s)
{
	int pos = -1;
	for (int i = 0; i < this->movies.size(); i++)
		if (movies[i].getTitle() == s)
			pos = i;
	if (pos != -1)
	{
		std::swap(this->movies[pos], this->movies.back());
		this->movies.pop_back();
	}
}

Film WatchList::getCurrentFilm()
{
	if (this->current == this->movies.size())
		this->current = 0;
	return this->movies[this->current];
	return Film{};
}

void WatchList::play()
{
	if (this->movies.size() == 0)
		return;
	Film currentFilm = this->getCurrentFilm();
	currentFilm.play();
}

void WatchList::next()
{
	if (this->movies.size() == 0)
		return;
	this->current++;
}

bool WatchList::isEmpty()
{
	return this->movies.size() == 0;
}

std::vector<Film> WatchList::getMovies()
{
	return this->movies;
}

int WatchList::getCurrent()
{
	return this->current;
}
