#pragma once
#include <vector>
#include "Film.h"

class WatchList
{
protected:
	std::vector<Film> movies;
	int current;

public:
	WatchList();

	// Adds a song to the playlist.
	void add(const Film& Film);
	//void add(const std::string& title, const std::string& genre, int year, int nrlikes, const std::string& trailer);

	void WatchList::remove(const std::string& s); 


	// Returns the song that is currently playing.
	Film WatchList::getCurrentFilm();

	// Starts the playlist - plays the first song.
	void play();

	// Plays the next song in the playlist.
	void next();

	// Checks if the playlist is empty.
	bool isEmpty();

	virtual ~WatchList() {}

	std::vector<Film> getMovies();

	int getCurrent();
}; 