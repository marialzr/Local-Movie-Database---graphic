#include "Controller.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <QDebug>
using namespace std;

void Controller::setWatchList(FileWatchList* fw)
{
	this->_watchList = fw;
}

void Controller::setFileWatchList(const std::string& filename)
{
	this->_watchList->setFilename(filename);
}

void Controller::addFilm(const Film& f)
{
	this->_repo.addFilm(f);
}

void Controller::removeFilmCtrl(const std::string& s)
{
	this->_repo.removeFilm(s);
}

void Controller::removeFilmCtrlWatch(const std::string& s)
{
	this->_watchList->remove(s);
}

void Controller::updateFilmCtrl(const Film& f)
{
	this->_repo.updateFilm(f);
}

vector<Film> Controller::getByGenre(const std::string& s)
{
	vector<Film> newList;
	vector<Film> elems = this->_repo.getFilms();
	if (s != "null")
	{
		for (int i = 0; i < elems.size(); i++)
		{
			if (elems[i].getGenre() == s)
				newList.push_back(elems[i]);
		}
	}
	else
	{
		for (int i = 0; i < elems.size(); i++)
			newList.push_back(elems[i]);
	}
    qDebug() <<newList.size();
	return newList;
}

void Controller::addWatch(const Film& f)
{
	this->_watchList->add(f);
}

Repository& Controller::getRepo()
{
	return this->_repo;
}

FileWatchList* Controller::getWatchList()
{
	return this->_watchList;
}

void Controller::startWatchlist()
{
	if (this->_watchList == nullptr)
		return;
	this->_watchList->play();
}

void Controller::nextMovieWatchlist()
{
	if (this->_watchList == nullptr)
		return;
	this->_watchList->next();
}

void Controller::saveWatchlist(const std::string& filename)
{
	if (this->_watchList == nullptr)
		return;

	this->_watchList->setFilename(filename);
	this->_watchList->writeToFile();
}

void Controller::openWatchlist() const
{
	if (this->_watchList == nullptr)
		return;

	this->_watchList->displayWatchlist();
}



