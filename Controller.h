#pragma once
#include "Repository.h"
#include "FileWatchlist.h"
#include <string>
class Controller
{
private:
	Repository _repo;
	FileWatchList* _watchList;

public:
    Controller::Controller(Repository &repo, FileWatchList* watchList) :_repo(repo), _watchList(watchList){}
	//Controller();
	void Controller::setWatchList(FileWatchList* fw);
	void Controller::setFileWatchList(const std::string& filename);
	void addFilm(const Film& f);
	void removeFilmCtrl(const std::string& s);
	void removeFilmCtrlWatch(const std::string& s);
	void updateFilmCtrl(const Film& f);
	std::vector<Film> getByGenre(const std::string& s);
	void addWatch(const Film& f);
	Repository& getRepo();
	FileWatchList* getWatchList();
	void startWatchlist();
	void nextMovieWatchlist();
	void saveWatchlist(const std::string& filename);
	void Controller::openWatchlist() const;
};
