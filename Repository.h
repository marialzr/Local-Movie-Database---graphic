#pragma once
#include "Film.h"
#include <iostream>
#include <vector>
#include <string>

class Repository
{
	//private:
protected:
    std::vector<Film> elems;
	std::string filename;

public:
	Repository(std::string fn);
	/*
	adds a movie to repository
	input: f-film
	output: -
	*/
	void Repository::addFilm(const Film& f);
	/*
	remove a movie from repository
	input: name- string: the title of the movie
	output:-
	*/
	void removeFilm(const std::string& name);
	/*
	update a movie
	input: f- the movie to which the old movie is replaced
	output:-
	*/
	void updateFilm(const Film& f);

	/*
	finds the movie that have the title s
	input: string s
	output: position of the movie that have the title s if it exists is repository
	-1 if it does not exist
	*/
	int finds(const std::string& s);
	/*
	finds the movie f
	input: f-movie
	output: position of the movie that have the title same as title of f if it exists is repository
	-1 if it does not exist
	*/
	int find(const Film& f);
	std::vector<Film>& getFilms();
	void readFromFile();
	void writeToFile();
};
