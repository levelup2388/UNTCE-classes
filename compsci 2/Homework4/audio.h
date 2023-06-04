#ifndef AUDIO_H
#define AUDIO_H

#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class Audio : public Item{
	public:
		Audio();
		Audio(int itemID, int cost, char status, string artist, string title, int numTracks, string date, string genere);
		void setArtist(string artist);
		void setTitle(string title);
		void setNumTracks(int numTracks);
		void setDate(string date);
		void setGenere(string genere);
		string getArtist();
		string getTitle();
		int getNumTracks();
		string getDate();
		string getGenere();
		void printItem() ;
	private:
		string Artist;
		string Title;
		int NumTracks;
		string Date;
		string Genere;
};

#endif
