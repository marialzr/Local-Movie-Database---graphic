#include "Film.h"
#include <stddef.h>
#include <Windows.h>
#include <shellapi.h>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <assert.h>

int Film::objectCount;

int Film::getCount()
{
	return objectCount;
}

Film::Film(std::string title, std::string genre, int year, int nrl, std::string trailer)
{
	this->_title = title;
	this->_genre = genre;
	this->_year = year;
	this->_nrlikes = nrl;
	this->_trailer = trailer;
	objectCount++;
}


Film::Film()
{
	this->_title = "";
	this->_genre = "";
	this->_year = 0;
	this->_nrlikes = 0;
	this->_trailer = "";
	objectCount++;
}

Film::Film(const Film& f)
{
	this->_title = f._title;
	this->_genre = f._genre;
	this->_year = f._year;
	this->_nrlikes = f._nrlikes;
	this->_trailer = f._trailer;
	objectCount++;
}

Film::~Film()
{
	objectCount--;
}

bool Film::operator ==(Film f)
{
	if (this->_title == f._title)
		return true;
	return false;
}

void Film::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::vector<std::string> Film ::tokenize(std::string s, char delim)
{
	std::vector<std::string>result;
	std::stringstream ss(s);
	std::string word;
	while (getline(ss, word, delim))
	{
		result.push_back(word);
	}
	return result;
}

std::istream& operator >> (std::istream& f, Film& m)
{
	std::string line;
	getline(f, line);
	char d = ' ';
	std::vector<std::string> tokens = m.tokenize(line, d);
	if (tokens.size() != 5)
		return f;
	m._title = tokens[0];
	m._genre = tokens[1];
	int v1 = stoi(tokens[2], nullptr, 10);
	m._year = v1;
	int v2 = stoi(tokens[3], nullptr, 10);
	m._nrlikes = v2;
	m._trailer = tokens[4];
	return f;
}

std::ostream& operator<<(std::ostream& g, const Film& m)
{
	g << m._title << " " << m._genre << " " << m._year << " " << m._nrlikes << " " << m._trailer << "\n";
	return g;
}
