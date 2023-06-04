#include "audio.h"

Audio::Audio(){
	Artist = "none";
	Title = "none";
	NumTracks = 0;
	Date = "none";
	Genere = "none";
}
Audio::Audio(int itemID, int cost, char status, string artist, string title, int numTracks, string date, string genere) :Item(itemID, cost, status) {
	Artist = artist;
	Title = title;
	NumTracks = numTracks;
	Date = date;
	Genere = genere;
}
void Audio::setArtist(string artist){
	Artist = artist;
}
void Audio::setTitle(string title){
	Title = title;
}
void Audio::setNumTracks(int numTracks){
	NumTracks = numTracks;
}
void Audio::setDate(string date){
	Date = date;
}
void Audio::setGenere(string genere){
	Genere = genere;
}
string Audio::getArtist(){
	return Artist;
}
string Audio::getTitle(){
	return Title;
}
int Audio::getNumTracks(){
	return NumTracks;
}
string Audio::getDate(){
	return Date;
}
string Audio::getGenere(){
	return Genere;
}
void Audio::printItem() {
	//Item::printItem();
	cout << "Item ID: " << ItemID;
	cout << "\nCost: $" << Cost;
	cout << "\nStatus: ";
	if (Status == 'I') {
		cout << "In\n";
	}
	else if (Status == 'O') {
		cout << "Out\n";
	}
	else if (Status == 'R') {
		cout << "Repair\n";
	}
	else if (Status == 'L') {
		cout << "Lost\n";
	}
	cout << "\nArtist: " << Artist;
	cout << "\nTitle: " << Title;
	cout << "\nNumTracks: " << NumTracks;
	cout << "\nDate" << Date;
	cout << "\nGenere: " << Genere << endl;
}