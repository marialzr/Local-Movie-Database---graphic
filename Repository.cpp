#include "Repository.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <QDebug>
using namespace std;
Repository::Repository(string fn)
{
    this->filename =fn;
	this->readFromFile();
}


int Repository::find(const Film& f)
{
    for (int i = 0; i < this->elems.size(); i++)
	{
        if (this->elems[i].getTitle() == f.getTitle())
			return i;
	}
	return -1;
}


int Repository::finds(const std::string& s)
{
    for (int i = 0; i < this->elems.size(); i++)
	{
        if (this->elems[i].getTitle() == s)
			return i;
	}
	return -1;
}

void Repository::addFilm(const Film& f)
{
	if (find(f) != -1)
        return;
    for (auto s : this->elems)
		cout << s.getTitle();
    this->elems.push_back(f);
	this->writeToFile();
}

void Repository::removeFilm(const std::string& s)
{
	int pos = finds(s);
	if (pos == -1)
        return;
    swap(this->elems[pos], this->elems.back());
    this->elems.pop_back();
	this->writeToFile();
}


void Repository::updateFilm(const Film& f)
{
	int pos = find(f);
	if (pos == -1)
        return;
    this->elems[pos] = f;
	this->writeToFile();
}


vector<Film>& Repository::getFilms()
{
    return this->elems;
}



void Repository::readFromFile()
{
	ifstream file(this->filename);
    std::string s=this->filename;
    qDebug() << s.data()<<s.c_str();
	if (!file.is_open())
        qDebug() << "not read";
	cout << this->filename;
	Film m;
	while (file >> m)
        this->elems.push_back(m);
	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
        return;

    for (auto s : this->elems)
	{
		file << s;
	}

	file.close();
}
