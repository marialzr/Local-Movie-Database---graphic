#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <assert.h>

class Film
{
private:
	std::string _title;
	std::string _genre;
	int _year;
	int _nrlikes;
	std::string _trailer;
public:
	static int objectCount;
	static int getCount();

	Film(std::string title, std::string genre, int year, int nrl, std::string trailer);
	Film();
	Film(const Film& f);
	~Film();
	bool operator ==(Film f);
    std::string getTitle() const { return this->_title; }
    std::string getGenre() const { return this->_genre; }
    int getYear() { return this->_year; }
	int getNrLikes() { return this->_nrlikes; }
	std::string getTrailer() const { return this->_trailer; }
	void play();

	friend std::istream& operator >> (std::istream& f, Film& m); //at >> the object Film is passed without const becaused it's gonna be modified
	friend std::ostream& operator<<(std::ostream& g, const Film& m);
	std::vector<std::string> Film::tokenize(std::string s, char delim);
};

